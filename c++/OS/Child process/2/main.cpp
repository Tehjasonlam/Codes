#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main()
{
    cout << "I am the parent process " << endl;
    for (int i = 0; i <= 4; i++)
    {
        int pid = fork();
        if (pid == 0) // if first child
        {
            cout << "I am the child process " << i << endl;
            for (int j = 1; j <= 2; j++)
            {
                int pidg = fork();
                if (pidg == 0)
                {
                    cout << "I am a grandchild process from child processs " << j << endl;
                    _exit(0);
                }
                else if (pidg > 0)
                {
                    wait(nullptr);
                }
            }
            _exit(0);
        }
        else if (pid > 0)
        {
            wait(nullptr);
        }
    }

    return 0;
}