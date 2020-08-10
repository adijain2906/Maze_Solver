#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <ctype.h>
#define U "UP"
#define D "DOWN"
#define L "LEFT"
#define R "RIGHT"
char maze[10][10];
char keys[100];
int ox,oy,k=-1;

/*
   '@' is the final point
   '.' represents spaces that are walkable
   Capital Letters represents the Doors to which
   the corresponding small letters are the keys
   For eg. a will open the door A, b will open the door B
   and so on...
*/


void refresh(int n,int m)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (maze[i][j]=='!')
			maze[i][j] = '.';
		}
	}
}
int solve(int x,int y,int n,int m)
{
	static int flag = 0;
	if (x==n || y==m || x<0 || y<0 ||maze[x][y]=='#'||maze[x][y]=='!')
	return 0;
	if (islower(maze[x][y]))
	{
		keys[++k] = maze[x][y];
		maze[x][y] = '.';
		refresh(n,m);
		x = ox-1;
		y = oy-1;
	}
	if (isupper(maze[x][y]))
	{
		for (int i=0;i<=k;i++)
		{
			if (maze[x][y]==toupper(keys[k]))
			{
				maze[x][y] = '.';
				break;
			}
		}
	}
	if (maze[x][y]=='@')
	return 1;
	if (maze[x][y]=='.')
	{
		maze[x][y] = '!';
		clrscr();
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				cout << maze[i][j] << " ";
			}
			cout << endl;
		}
		delay(300);
		flag = solve(x+1,y,n,m) ||
		       solve(x-1,y,n,m) ||
		       solve(x,y+1,n,m) ||
		       solve(x,y-1,n,m);
	}
	return flag;
}
void main()
{
	clrscr();
	int n,m;
	int i,j;
	int x,y;
	cin >> n >> m >> x >> y;
	ox = x;
	oy = y;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			cin >> maze[i][j];
		}
	}
	int check = solve(x-1,y-1,n,m);
	cout << endl << ((check==1)? "possible" : "not possible");
	getch();
}