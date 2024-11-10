#include <iostream>

struct node
{
    int date;
    node *next;
};

node *begin=NULL,*end=NULL,*p=NULL;

void initialization_node(int len)
{
    for(int i=0;i<len;i++)
    {
        p = new node;
        std::cin>>p->date;
        p->next = NULL;

        if(begin  == NULL)
        {
            begin = p;
            end = p;
        }
        else
        {
            end->next = p;
            end = p;
        }
    }
}

void show_node()
{
    node *t = begin;
    while(t != NULL)
    {
        std::cout<<t->date<<' ';
        t = t->next;
    }
}


int main()
{
    initialization_node(3);
    show_node();

    return 0;
}