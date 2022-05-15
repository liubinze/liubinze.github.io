#include<bits/stdc++.h>
#define int long long
#define r register
using namespace std;

signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	r int T,n,k,h=0,pdh;
	r bool mark=0;
	scanf("%lld",&T);
	while(T--)
	{
		mark=0;
		pdh=h=0;
		scanf("%lld%lld",&n,&k);
		if(k==0) printf("YES\n0\n");
		else 
		{
			for(r int i=1;h<k;i*=2) 
			{
				h+=i;
				if(h==(n-k)) mark=1,pdh=i*2;
			}
			if(h==k)
			{
				h=0;
				printf("YES\n");
				for(r int i=1;h<k;i*=2)
				{
					printf("%lld ",h+1);
					h+=i;
				}
				printf("\n");
			}
			else 
			{
				if(mark)
				{
					h=0;
					for(r int i=pdh;h<n;i*=2)
					{
						h+=i;
					}
					if(h==n)
					{
						printf("YES\n");
						r int i=1;
						h=0;
						cerr<<n-k<<" "<<h<<endl;
						for(i=1;h<n-k;i*=2)
						{
							h+=i;printf("%lld ",n-h+1);
						}
						h=0;
						for(i;h<n;i*=2)
						{
							printf("%lld ",h+1);
							h+=i;
						}
						printf("\n");
					}
					else 
					{
						printf("NO\n");
						continue;
					}
					
				}
				else printf("NO\n");
			}
		}
	}
	exit(0);
}
