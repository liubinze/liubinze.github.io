#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
ll n,k;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k==0)
		{
			puts("YES");
			puts("0");
			continue;
		}
		ll tot=1,cnt=1,kk=1;
		while(tot<k)
		{
			kk*=2;
			tot+=kk;
			cnt++;
		}
		if(tot==k)
		{
			puts("YES");
			cout<<cnt<<" ";
			for(int i=1,j=1;i<=k;i+=j,j*=2)
			{
				printf("%lld ",i);
			}
			puts("");
			continue;
		}
		ll _k=n-k;
		tot=1,cnt=1,kk=1;
		while(tot<_k)
		{
			kk*=2;
			tot+=kk;
			cnt++;
		}
		if(tot!=_k)
		{
			puts("NO");
			continue;
		}
		kk*=2,tot=kk,cnt++;
		while(tot<n)
		{
			kk*=2;
			tot+=kk;
			cnt++;
		}
		if(tot==n)
		{
			puts("YES");
			cout<<cnt<<" ";
			ll j=1;
			for(ll i=n;i>=n-_k+1;j*=2,i-=j)
			{
				printf("%lld ",i);
			}
			for(ll i=1;i<=n;i+=j,j*=2)
			{
				printf("%lld ",i);
			}
			puts("");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}
