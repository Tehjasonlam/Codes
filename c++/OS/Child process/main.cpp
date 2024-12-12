#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;


int main()
{
    int pid;
    cout << "I am the parent process " << endl;
    for (int i = 0; i < 4; i++)
    {
        pid = fork();
        if (pid == 0) //child process
        {
            cout << "I am the child process " << i+1 << endl;
            if (pid == 0) // if first child
            {
                pid = fork();
                cout << "I am a grandchild process from child processs " << i+1 << endl;
                _exit(0);
            }
            wait(nullptr);
        }
        else if(i == 3) //if the last child
        {
            for(int j = 0; j < 2; j++)
            {
                pid = fork();
                if(pid == 0)
                {
                    cout << "I am a grandchild process from child process " << i + 1 << endl;
                    _exit(0);
                }
                _exit(0);
            }
            for(int j = 0 ; j < 2; i++)
            {
                wait(nullptr);
            }
            
        }
        _exit(0); //child must exit
    }
    for(int i = 0 ; i < 0; i++)
    {
        wait(nullptr);
    }

}

