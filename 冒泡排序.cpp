#include <iostream>

int arr[] = {2,321,43,4,32,13,4,3,21,4,1234,4,34,2,2,31,123,41};

void Bubbling_sort()
{
    int len = sizeof(arr)/sizeof(int);
    for(int i = 0 ;i<len ;i++)
    {
        for(int j = i+1 ;j<len ;j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main()
{
    Bubbling_sort();

    for(int i = 0;i<sizeof(arr)/sizeof(int);i++)
        std::cout<<arr[i]<<' ';
    return 0;
}