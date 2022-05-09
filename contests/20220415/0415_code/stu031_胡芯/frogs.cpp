#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize("inline")
using namespace std;
typedef long long ll;
const int N=1.0E4+3;

int n,m;
int a[N];
int x;
ll res;
map<int,int> q;
int main()
{
	freopen("frogs.in","r",stdin);
	freopen("frogs.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (register int i=1; i^(n+1); ++i)
	{
		scanf("%d",&a[i]);
	}
	for (register int i=1; i^(n+1); ++i)
	{
		x=0;
		do
		{
			if (!q[x])
			{
				res+=x;
			}
			q[x]=1;
			x=(x+a[i])%m;
		}
		while (x!=0);
	}
	printf("%lld",res);
	return 0;
}

