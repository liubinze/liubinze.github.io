#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
const int inf=1e18;

int n;
int p[N],a[N];
int dist1[N],dist2[N],cnt1[N],cnt2[N];

signed main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&p[i],&a[i]);
	}
	cnt1[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		dist1[i]=dist1[i-1]+1ll*(p[i]-p[i-1])*cnt1[i-1];
		cnt1[i]=cnt1[i-1]+a[i];
	}
	cnt2[n]=a[n];
	for(int i=n-1;i>=1;i--)
	{
		dist2[i]=dist2[i+1]+1ll*(p[i+1]-p[i])*cnt2[i+1];
		cnt2[i]=cnt2[i+1]+a[i];
	}
	int ans=inf;
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,dist1[i]+dist2[i]);
	}
	printf("%lld",ans);
	return 0;
}
