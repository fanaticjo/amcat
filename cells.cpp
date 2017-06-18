#include<iostream>
using namespace std;
int cellscompete(int *cells,int day)
{
	for(int i=0;i<day;i++)
	{
		cells[-1]=0;
		cells[8]=0;
		int u[8];
		for(int k=-1;k<9;k++)
		{
			u[k]=cells[k];

		}
		for(int r=0;r<8;r++)
		{
			if(u[r-1]==u[r+1])
			{
				cells[r]=0;
			}
			else
			{
				cells[r]=1;
			}
		}
	}
	for(int l=0;l<8;l++)
	{
		cout<<cells[l]<<"\t";
	}

}
int main()
{
	int days,cells[]={1,0,0,0,0,1,0,0}; //array to pass through function
int *cellsptr=cells; //creating array values to pointer
cout<<"enter days:"; //for days
cin>>days; 
//cout<<"n[1,0,0,0,0,1,0,0]n";
cellscompete(cellsptr, days); //passing to function
}