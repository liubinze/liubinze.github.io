#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1.0E7+1;
bool mark[N];
int p[N];
int f[N];
int minp[N];
int n,t;
ll res;
ll h2(ll x)
{
	int cnt=-1,tmp=0,op;
	while (x!=1LL)
	{
		op=minp[x];
		tmp=0;
		while (minp[x]==op && x!=1)
		{
			x/=minp[x];
			tmp++;
		}
		cnt=max(cnt,tmp);
	}
	return cnt;
}
void Euler()
{
	for (register int i=2; i<N; i+=1)
	{
		if (!mark[i])
		{
			p[++p[0]]=i;
			minp[i]=i;
		}
		for (register int j=1; j<=p[0] && 1LL*i*p[j]<N; j+=1)
		{
			mark[p[j]*i]=true;
			minp[p[j]*i]=p[j];
			if (i/p[j]*p[j]==i)
			{
				break;
			}
		}
	}
}
int main()
{
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	Euler();
	f[1]=0;
	memset(f,0,sizeof (f));
	scanf("%d",&t);
	while (t--)
	{
		res=0;
		scanf("%d",&n);
		for (register int i=1; i*i<=n; i++)
		{
			if (n/i*i==n)
			{
				if (!f[n/i] && n/i!=1) f[n/i]=h2(n/i);
				res+=1LL*i*f[n/i];
				if (i*i!=n)
				{
					if (!f[i] && i!=1) f[i]=h2(i);
					res+=1LL*(n/i)*f[i];
				}
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
