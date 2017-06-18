#include<iostream>
using namespace std;
int path(int grid[][4],int x,int y,int m,int n);
int isgrid(int grid[][4],int m,int n)
{
	return path(grid,0,0,m,n);
}
int path(int grid[][4],int x,int y,int m,int n)
{
	if(x<=m && y<=n && x>=0 && y>=0)
	{
		if(grid[x][y]==9)
		{
			return 1;
		}
		if(grid[x][y]==1)
		{
			if(path(grid,x+1,y,m,n)==1)
				return 1;
			if(path(grid,x,y+1,m,n)==1)
				return 1;
			else
			{
				return 0;
			}
		}
		grid[x][y]=0;
		return 0;
	}
	return 0;
}
int main()
{
	int maze[4][4]={
                1, 1, 0,
                0, 1, 1,
                1, 9, 1,
                0, 0, 1,
        };
        //int **check=maze;
   
    int x=isgrid(maze,3,3);
    cout<<x;
    return 0;

}