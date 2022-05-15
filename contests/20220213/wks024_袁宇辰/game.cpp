#include<bits/stdc++.h>
using namespace std;
int T,cnt;
bool two(int x)
{
	while(x%2==0)x/=2,cnt++;
	if(x==1)return true;
	else return false;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		cnt=0;
		int n,k;
		scanf("%d%d",&n,&k);
		if(k==0)
		{
			printf("YES\n0\n");
			continue;
		}
		if(!(two(k+1)))
		{
			printf("NO\n");
			continue;
		}
		else
		{
			printf("YES\n%d\n",cnt);
			int step=1;
			for(int i=1;step<=k;i++)
			{
				printf("%d ",step);
				step+=pow(2,i-1);
			}
			printf("\n");
		}
	}
	return 0;
}
