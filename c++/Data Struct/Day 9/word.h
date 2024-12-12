

struct onechar
{
    onechar *prev;
    char l;
    onechar *next;
};

class word
{
private:
    onechar *head;

public:
    word() { head = 0; }
    bool isempty()
    {
        return (head == 0);
    }
    onechar *gethead() { return head; }
    void insertatbeg(char x);
    void print();
    void printrec();
    void printprev();
    void del_c(char x);
};
