#include<iostream>
using namespace std;
int t,n,k;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if(k%2==0&&k!=0)
		{
			printf("NO\n");
		}
		else
		{
			int flag=1;
			if(k==0)
			{
				printf("YES\n0\n");
				continue;
			}
			int kk=1;
			int kc[50],cnt=0;
			while(k)
			{
				if(((k-kk)%(2*kk)==0&&(k-kk)%(4*kk)!=0)||(k-kk==0))
				{
					k-=kk;
				}
				else
				{
					k+=kk;
				}
				if(k>n)
				{
					printf("NO\n");
					flag=0;
					break;
				}
				kc[++cnt]=k+1;
				kk=kk*2;
			}
			if(flag==1)
			{
				printf("YES\n");
				for(int i=1;i<=cnt;i++)
					printf("%d ",kc[i]);
				printf("\n");
			}
		}
	}
}

