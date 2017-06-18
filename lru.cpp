#include<iostream>
using namespace std;
int lru(int max,int *pages,int len)
{
int miss=0;;
int cache[max];
for(int i=0;i<max;i++)
{
	cache[i]=0x8778;
}
for(int i=0;i<len;i++)
{
	for(int j=0;j<max;j++)
	{
		if(pages[i]==cache[j])
		{
		   for(int k=0;k<max;k++)
		   {
		   	cache[i]==cache[i+1];
		   }
		   cache[max-1]=pages[i];
		   break;
		}
		else if(j==(max-1))
		{
			for(int l=0;l<max;l++)
			{
				cache[l]=cache[l+1];
			}
			cache[max-1]=pages[i];
			miss++;
		}

	}
}
return miss;
}
int main()
{
	int pages[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0};
	int *cells=pages;
	int miss=lru(3,cells,16);
    cout<<miss;
}