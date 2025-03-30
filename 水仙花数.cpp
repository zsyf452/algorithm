#include <iostream>
#include <cmath>

int main()
{
    for(int i =0;i<10;i++)
    {
        for(int j =0;j<10;j++)
        {
            for(int k =0;k<10;k++)
            {
                int t = i*100+j*10+k;
                if(t == pow(i,3)+pow(j,3)+pow(k,3))  
                {
                    std::cout<<t<<std::endl;
                }
            }
        }
    }


    return 0;
}