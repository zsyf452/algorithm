#include <iostream>

int arr[] = {1,23,43,4,324,5,45};
int book[1000];

void Bucket_sorting()
{
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
        book[arr[i]] = 2;

    for(int i = 0;i<sizeof(book)/sizeof(int);i++)
    {
        if(book[i] == 1)
            std::cout<<i<<" ";
    }
}

int main()
{

    Bucket_sorting();
    return 0;
}