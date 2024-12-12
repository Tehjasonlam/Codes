#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
#include <arpa/inet.h>
#include <unistd.h>

struct ThreadData {
    std::string message;
    std::string response;
    std::string hostname;
    int port;
};

void* sendMessage(void* arg) {
    ThreadData* data = static_cast<ThreadData*>(arg);
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return nullptr;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(data->port);

    if (inet_pton(AF_INET, data->hostname.c_str(), &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address or Address not supported" << std::endl;
        close(sock);
        return nullptr;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        close(sock);
        return nullptr;
    }

    send(sock, data->message.c_str(), data->message.size(), 0);
    read(sock, buffer, 1024);
    data->response = buffer;

    close(sock);
    return nullptr;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: ./client <hostname> <port_no> < input_filename" << std::endl;
        return -1;
    }

    std::string hostname = argv[1];
    int port = std::stoi(argv[2]);

    std::vector<std::string> messages;
    std::string line;
    while (std::getline(std::cin, line)) {
        messages.push_back(line);
    }

    std::vector<ThreadData> threadData(messages.size());
    std::vector<pthread_t> threads(messages.size());

    for (size_t i = 0; i < messages.size(); ++i) {
        threadData[i].message = messages[i];
        threadData[i].hostname = hostname;
        threadData[i].port = port;
        pthread_create(&threads[i], nullptr, sendMessage, &threadData[i]);
    }

    for (size_t i = 0; i < threads.size(); ++i) {
        pthread_join(threads[i], nullptr);
        std::cout << "Message: " << threadData[i].message << std::endl;
        std::cout << threadData[i].response << std::endl;
    }

    return 0;
}
