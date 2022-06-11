#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
typedef long long ll;
bool vis[1001][1001];
ll n=9ll,m=9ll,k=10ll,mine[1001][1001];
inline void sweep(ll x,ll y)
{
	if(x<0ll||x>=n||y<0ll||y>=m||vis[x][y])
		return;
	vis[x][y]=1;
	if(mine[x][y]>0ll)
		return;
	sweep(x-1ll,y),sweep(x-1ll,y-1ll),sweep(x,y-1ll),sweep(x+1ll,y-1ll),sweep(x+1ll,y),sweep(x+1ll,y+1ll),sweep(x,y+1ll),sweep(x-1ll,y+1ll);
	return;
}
int main()
{
	char c;
	ll x,y,t,a,b;
	mt19937 rng(time(0));
	start:
	x=n-1ll>>1ll,y=m-1ll>>1ll,t=0ll,printf("Minesweeper\nBy Eznibuil\n\n1. Use 'wasd' to move\n2. Use Enter to sweep\n\n"),system("pause"),system("cls");
	for(ll i=0ll;i<n;i++,puts(""))
		for(ll j=0ll;j<m;j++)
			printf(x^i||y^j?"#":"@");
	puts("Press Enter to sweep!"),c=getch();
	while(c^'\r'&&c^'\n')
	{
		switch(c|' ')
		{
			case'w':
				x-=ll(x>0ll);
				break;
			case'a':
				y-=ll(y>0ll);
				break;
			case's':
				x+=ll(x<n-1ll);
				break;
			case'd':
				y+=ll(y<m-1ll);
				break;
		}
		system("cls");
		for(ll i=0ll;i<n;i++,puts(""))
			for(ll j=0ll;j<m;j++)
				printf(x^i||y^j?"#":"@");
		puts("Press Enter to sweep!"),c=getch();
	}
	while(t<k)
		if(!mine[a=rng()%n][b=rng()%m]&&(abs(x-a)>1ll||abs(y-b)>1ll))
			t-=(mine[a][b]=-1);
	for(ll i=0ll;i<n;i++)
		for(ll j=0ll;j<m;j++)
			if(~mine[i][j])
				mine[i][j]=ll(i&&!~mine[i-1][j])+ll(i&&j&&!~mine[i-1][j-1])+ll(j&&!~mine[i][j-1])+ll(i<n-1ll&&j&&!~mine[i+1][j-1])+ll(i<n-1ll&&!~mine[i+1][j])+ll(i<n-1ll&&j<m-1ll&&!~mine[i+1][j+1])+ll(j<m-1ll&&!~mine[i][j+1])+ll(i&&j<m-1ll&&!~mine[i-1][j+1]);
	sweep(x,y),t=0ll;
	for(ll i=0ll;i<n;i++)
		for(ll j=0ll;j<m;j++)
			if(vis[i][j])
				t++;
	while(t<n*m-k)
	{
		system("cls");
		for(ll i=0ll;i<n;i++,puts(""))
			for(ll j=0ll;j<m;j++)
				if(x==i&&y==j)
					printf("@");
				else if(vis[i][j])
					if(mine[i][j])
						printf("%lld",mine[i][j]);
					else
						printf(" ");
				else
					printf("#");
		in:
		c=getch(),t=0ll;
		if((c|' ')=='w')
			x-=ll(x>0ll);
		else if((c|' ')=='a')
			y-=ll(y>0ll);
		else if((c|' ')=='s')
			x+=ll(x<n-1ll);
		else if((c|' ')=='d')
			y+=ll(y<m-1ll);
		else if(c=='\r'||c=='\n')
			if(~mine[x][y])
				sweep(x,y);
			else
				break;
		else
			goto in;
		for(ll i=0ll;i<n;i++)
			for(ll j=0ll;j<m;j++)
				if(vis[i][j])
					t++;
	}
	system("cls");
	if(t<n*m-k)
	{
		for(ll i=0ll;i<n;i++,puts(""))
			for(ll j=0ll;j<m;j++)
				if(x==i&&y==j)
					printf("X");
				else if(vis[i][j])
					if(mine[i][j])
						printf("%lld",mine[i][j]);
					else
						printf(" ");
				else if(~mine[i][j])
					printf("#");
				else
					printf("*");
		puts("You lost!");
	}
	else
	{
		for(ll i=0ll;i<n;i++,puts(""))
			for(ll j=0ll;j<m;j++)
				if(vis[i][j])
					if(mine[i][j])
						printf("%lld",mine[i][j]);
					else
						printf(" ");
				else if(~mine[i][j])
					printf("#");
				else
					printf("*");
		puts("You won!");
	}
	getch(),system("cls"),memset(mine,0,sizeof(mine)),memset(vis,0,sizeof(vis));
	goto start;
	return 0;
}
