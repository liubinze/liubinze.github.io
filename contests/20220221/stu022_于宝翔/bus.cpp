#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,m,k,maxn;
int t[N];

bool check(int tim)
{
	int cnt=1,last=t[1],tot=1;
	for(int i=2;i<=n;i++)
	{
		if(cnt>=k||t[i]-last>tim)
		{
			cnt=1,last=t[i],tot++;
			continue;
		}
		cnt++;
	}
	return tot<=m;
}

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		maxn=max(maxn,t[i]);
	}
	sort(t+1,t+n+1);
	int l=0,r=maxn;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}
