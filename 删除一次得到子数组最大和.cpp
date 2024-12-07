#include <iostream>

int arr[] = {1,-2,0,3};
int n = sizeof(arr)/sizeof(int);

void show();
int maximumSum();
void fastSort(int left,int right);

int main()
{
    std::cout<<maximumSum();
    return 0;
}

int maximumSum()
{
    fastSort(0,n-1);
    show();
    int total = 0;
    for(int i=1;i<n;i++)
    {
        total+=arr[i];
    }
    int MAX = total > total+arr[0]?total:total+arr[0];
    int _MAX = MAX > arr[n-1]?MAX:arr[n-1];
    return _MAX;

}

void show()
{
    for(int i=0;i<n;i++)
        std::cout<<arr[i]<<' ';
    std::cout<<std::endl;
}

void fastSort(int left,int right)
{
    if(left > right)
        return;


    int j = right,i = left;
    int temp = arr[left];

    while(i != j)
    {
        while(arr[j] >= temp && i<j)
            j--;
        while(arr[i] <= temp && i<j)
            i++;
        
        if(j != i)
        {
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
        }
    }

    arr[left] = arr[j];
    arr[j] = temp;

    fastSort(left,j-1);
    fastSort(j+1,right);
}