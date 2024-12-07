#include <iostream>

int arr[] = {1,2,3,4,5,6,7};
int len = sizeof(arr)/sizeof(int);
int k = 5;
int res = 0;
int i = 0;

int func()
{
    int left = 0;
    int right = len-1;

    while(left<=right)
    {
        int min = left + (right - left) / 2;

        if(arr[min] == k)
            return min;
        else if(arr[min] < k)
            left = min+1;
        else
            right = min-1; 
    }
    return -1;
}


int main()
{
    std::cout<<func()<<std::endl;
    return 0;
}