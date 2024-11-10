#include <iostream>

int arr[] = {213,56,4546,5464,645,7,4,654,647,54,645,3,354,4,34,2,324,32,4,5432,324,543,54,35,435};

void fast_sort(int left,int right)
{
    if(left > right)
        return;

    int i = left,j=right;
    int temp = arr[left];

    while(i != j)
    {
        while(arr[j] >= temp && i<j)
            j--;
        while(arr[i] <= temp && i<j)
            i++;

        if(i >= j)
            break;
        
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    arr[left] = arr[j];
    arr[j] = temp;

    fast_sort(left,j-1);
    fast_sort(j+1,right);
}


int main()
{

    fast_sort(0,sizeof(arr)/sizeof(int)-1);

    for(int i = 0;i<sizeof(arr)/sizeof(int);i++)
    {
        std::cout<<arr[i]<<' ';
    }

    return 0;
}