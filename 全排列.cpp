#include <iostream>

int book[100];
int len = 0;
int *e;


void func(int arr[],int step)
{
    if(step == len)
    {
        for(int i = 0;i<len;i++)
            std::cout<<e[i]<<' ';
        std::cout<<'\n';
    }

    for(int i = 0;i<len;i++)
    {
        
        if(book[arr[i]] != 1)
        {
            book[arr[i]] = 1;
            e[step] = arr[i];

            func(arr,step+1);

            e[step] = 0;
            book[arr[i]] = 0;
        }
    }
}


int main()
{
    int arr[] = {1,2,3,4};

    len = sizeof(arr)/sizeof(int);
    e = new int[len];

    
    for(int i = 0;i<len;i++)
            e[i] = 0;

    func(arr,0);
    delete e;
    return 0;
}