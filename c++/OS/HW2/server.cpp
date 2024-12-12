#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <vector>
#include <sys/wait.h>

void fireman(int) {
    while (waitpid(-1, nullptr, WNOHANG) > 0);
}

// Function to handle Shannon encoding - placeholder
std::string encodeMessage(const std::string& message, std::string& alphabet) {
    // Implement Shannon encoding logic here and populate `alphabet`
    // Currently, it just returns the original message for demonstration
    alphabet = "Sample Alphabet with Shannon codes";
    return message;
}

void handleClient(int clientSocket) {
    char buffer[1024] = {0};
    read(clientSocket, buffer, 1024);
    
    std::string message = buffer;
    std::string alphabet;
    std::string encodedMessage = encodeMessage(message, alphabet);

    // Send alphabet and encoded message back to client
    std::string response = "Alphabet:\n" + alphabet + "\nEncoded message: " + encodedMessage;
    send(clientSocket, response.c_str(), response.size(), 0);

    close(clientSocket);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./server <port_no>" << std::endl;
        return -1;
    }

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int port = std::stoi(argv[1]);

    signal(SIGCHLD, fireman);  // To handle zombie processes

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while (true) {
        if ((new_socket = accept(server_fd, nullptr, nullptr)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        if (fork() == 0) {
            // Child process
            close(server_fd);
            handleClient(new_socket);
            exit(0);
        }
        close(new_socket);
    }
    return 0;
}