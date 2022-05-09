#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e4+5,M=1e4+5;

int n,m;
ll ans;
int a[N];
bool mark[M],vis[M];

int main()
{
	freopen("frogs.in","r",stdin);
	freopen("frogs.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		memset(vis,false,sizeof vis);
		int st=a[i]%m;
		while(!vis[st])
		{
			vis[st]=true;
			if(!mark[st])
			{
				mark[st]=true;
				ans=ans+st;
			}
			st=(st+a[i])%m;
		}
	}
	printf("%lld",ans);
	return 0;
}
