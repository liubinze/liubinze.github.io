#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize("inline")
using namespace std;
typedef long long ll;

const int N=1.0E6+3;

int n;
struct node
{
	ll ft;
	ll ed;
	int p;
	int t;
} s[N];

ll len,ple;
ll res;

int main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d %d",&s[i].p,&s[i].t);
	s[1].ft=0;
	len=0;
	ple=s[1].t;
	for (int i=2; i<=n; i++)
	{
		len+=ple*(s[i].p-s[i-1].p);
		s[i].ft=len;
		ple+=s[i].t;
	}

	s[n].ed=0;
	len=0;
	ple=s[n].t;
	for (int i=n-1; i>=1; i--)
	{
		len+=ple*(s[i+1].p-s[i].p);
		s[i].ed=len;
		ple+=s[i].t;
	}
	res=0x3f3f3f3f3f3f3f3f;
	for (int i=1; i<=n; i++)
	{
		res=min(res,s[i].ft+s[i].ed);
	}
	printf("%lld",res);
	return 0;
}
