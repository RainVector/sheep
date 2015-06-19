#include <stdio.h>

int Judge(int a[10][10],int chesser,int col,int row);

int main()
{
	int x,y,input;
	int win = 0;
	int chess[10][10];
	freopen("./in.txt","r",stdin);
	//input  the chessboard
	for(x=0;x<10;x++)
		for(y=0;y<10;y++)
		{
			scanf("%d",&input);
			chess[x][y] = input;	
		}
	
	for(x=0;x<10;x++)
		for(y=0;y<10;y++)
		{
			if(chess[x][y] == 1)
			{
				win = Judge(chess,1,x,y);
				if(win == 1)
					break;
			}
			else if(chess[x][y] == 2)
			{
				win = Judge(chess,2,x,y);
				if(win == 2)
					break;
			}
		}
	if(win == 1)
		printf("1 win\n");
	else if(win == 2)
		printf("2 win\n");
	else
		printf("no one win\n");
	
	return 0;
}
int Judge(int a[10][10],int chesser,int col,int row)
{
	int end = 0;
	//East
	if(row+4 <10&&a[col][row+1] == chesser&&a[col][row+2] == chesser&&\
		a[col][row+3] == chesser&&a[col][row+4] == chesser)
	{
		return chesser;
	}	
	//NorthEast
	else if(row+4<10&&col-4>=0&&a[col-1][row+1]==chesser&&\
			a[col-2][row+2]==chesser&&a[col-3][row+3]==chesser&&
			a[col-4][row+4]==chesser)	
	{
		return chesser;
	}
	//North
	else if(col-4 >=0&&a[col-1][row] == chesser&&a[col-2][row] == chesser&&\
		a[col-3][row] == chesser&&a[col-4][row] == chesser)
	{
		return chesser;
	}
	//NorthWest
	else if(col-4 >=0&&row-4>=0&&a[col-1][row-1] == chesser&&a[col-2][row-2] == chesser&&\
		a[col-3][row-3] == chesser&&a[col-4][row-4] == chesser)
	{
		return chesser;
	}
	//West
	else if(row-4 >=0&&a[col][row-1] == chesser&&a[col][row-2] == chesser&&\
		a[col][row-3] == chesser&&a[col][row-4] == chesser)
	{
		return chesser;
	}
	//SouthWest
	else if(row-4>=0&&col+4<10&&a[col+1][row-1]==chesser&&\
			a[col+2][row-2]==chesser&&a[col+3][row-3]==chesser&&
			a[col+4][row-4]==chesser)	
	{
		return chesser;
	}
	//South
	else if(col+4 <10&&a[col+1][row] == chesser&&a[col+2][row] == chesser&&\
		a[col+3][row] == chesser&&a[col+4][row] == chesser)
	{
		return chesser;
	}
	//SouthEast
	else if(col+4 <10&&row+4<10&&a[col+1][row+1] == chesser&&a[col+2][row+2] == chesser&&\
		a[col+3][row+3] == chesser&&a[col+4][row+4] == chesser)
	{
		return chesser;
	}
	else
		return end;
}
