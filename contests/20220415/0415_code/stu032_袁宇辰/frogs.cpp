#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5,M=1e9+5;
int n,m,ans;
int a[N];
bool mark[M];

signed main()
{
	freopen("frogs.in","r",stdin);
	freopen("frogs.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int x=0;
		do
		{
			if(!mark[x])
			{
				ans+=x;
				mark[x]=1;
			}
			x=(x+a[i])%m;
		}while(x!=0);
	}
	printf("%lld\n",ans);
	return 0;
}
