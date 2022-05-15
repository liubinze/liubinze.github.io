#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int ans,ansn[40];
bool flag;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(k==0)
		{
			printf("YES\n0\n");
		}
		else if(k&1)
		{
			ans=0;
			flag=true;
			for(int i=1;k>0&&flag;i<<=1)
			{
				if(k==i)
				{
					ansn[++ans]=1;
					k-=i;
				}
				else
				{
					if(k&(i<<1))
					{
						ansn[++ans]=k-i+1;
						k-=i;
					}
					else
					{
						if(k+i<=n)
						{
							ansn[++ans]=k+1;
							k+=i;
						}
						else
						{
							flag=false;
							break;
						}
					}
				}
			}
			if(!flag)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n%d\n",ans);
				for(int i=1;i<=ans;i++)
				{
					printf("%d ",ansn[i]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
