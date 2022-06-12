#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,m;
int a[N];

bool check(int x)
{
	int tot=0,w=0,maxn=0;
	for(int i=1;i<=n;i++)
	{
		if(tot>=x)
		{
			tot=1;
			w+=maxn+1;
			maxn=a[i];
			continue;
		}
		tot++;
		maxn=max(maxn,a[i]);
	}
	if(maxn)w+=maxn;
	if(w<=m)return true;
	tot=0,w=0,maxn=0;
	for(int i=n;i>=1;i--)
	{
		if(tot>=x)
		{
			tot=1;
			w+=maxn+1;
			maxn=a[i];
			continue;
		}
		tot++;
		maxn=max(maxn,a[i]);
	}
	if(maxn)w+=maxn;
	return w<=m;
}

int main()
{
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int minx=n;
	for(int i=1;i<=n;i++)
		if(check(i))
			minx=min(minx,i);
	printf("%d",minx);
	return 0;
}
