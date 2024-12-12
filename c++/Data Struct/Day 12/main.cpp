#include <iostream>
#include <string.h>
#include <queue> ///stl   xenqueue push

using namespace std;
// extra_10_1_3

#include <iostream>
#include <string.h>
using namespace std;
struct job
{
    string name;
    int min;
    job *next;
};
class qjob
{
private:
    job *front;
    job *back;

public:
    qjob() { front = back = nullptr; }
    bool isempty() { return front == nullptr; }
    void enqueue(string n, int m)
    {
        job *tmp = new job;
        tmp->name = n;
        tmp->min = m;
        tmp->next = nullptr;
        // update
        if (isempty())
            front = back = tmp;
        else
        {
            back->next = tmp;
            back = tmp;
        }
    }
    void dequeue()
    {
        job *tmp;
        if (!isempty())
        {
            tmp = front;
            cout << tmp->name;
            cout << tmp->min;
            front = front->next;
            delete tmp;
        }
    }
    void print();
};

int main()
{
    qjob rizk;
    int a[4];
    // create array
    for (int i = 0; i < 4; i++)
        a[i] = rand() % 50 + 10;
    // sort it
    bssort(a, 4);
    // fill teh queue
    for (int i = 0; i < 4; i++)
        rizk.enqueue("job", a[i]);
    // processing the job =dequeuing and logging the min
    job *cu;
    int sum = 0;
    while (!rizk.isempty())
    {
        cu = rizk.getfront();
        sum += cu->min;
        rizk.dequeue();
    }
    cout << " it took rizk" << sum << "minutes to finish all jobs";
}