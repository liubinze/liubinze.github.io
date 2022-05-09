#include<bits/stdc++.h>
using namespace std;
int n;
long long tot,x[1000005],y[1000005],t,ans;
int main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	scanf("%d",&n);
	for(int a=1;a<=n;a++) scanf("%lld%lld",&x[a],&y[a]),tot+=y[a];
	for(int a=1;a<=n;a++)
	{
		t+=x[a];
		if(t*2>=tot)
		{
			for(int b=1;b<=n;b++) ans+=abs(x[a]-x[b])*y[b];
			printf("%lld",ans);
			return 0;
		}
	}
}
