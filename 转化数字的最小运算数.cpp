#include <iostream>

struct Queue
{
	int sum;
	int step;
}line[10000];

//int nums[]={2,8,16};
//int goal = 1;
//int start = 0;

int nums[]={2,4,12};
int goal = 2;
int start = 12;

//int nums[]={3,5,7};
//int goal = 0;
//int start = -4;




int len = sizeof(nums)/sizeof(int);
int res = -1;

void dfs();


int main()
{
	dfs();
	std::cout<<res<<std::endl;
	
	return 0;
}

void dfs()
{
	int begin=0,end=1,t=0,l=3*len;
	
	line[begin].sum = start;
	line[begin].step = 0;
	
	for(int i = 0;i<l;i++)
	{
		for(int j = 0;j<len;j++)
		{
			for(int k = 0;k<3;k++)
			{
				switch (k) {
				case 0:
					t = line[begin].sum + nums[j];
					break;
				case 1:
					t = line[begin].sum - nums[j];
					break;
				case 2:
					t = line[begin].sum ^ nums[j];
					break;
				}
				
				line[end].sum = t;
				line[end].step = line[begin].step+1;
				end++;
				if(t == goal)
				{
					res = line[end-1].step;
					return;
				}
					
				
			}
			
		}
		begin++;
		
	}
	
	
}

