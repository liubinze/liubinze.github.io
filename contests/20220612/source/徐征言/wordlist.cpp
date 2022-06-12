#include<bits/stdc++.h>
using namespace std;
int n,m,w,x[1000005];
bool check(int k)
{
	int tot=0;
	for(int a=1;a<=n;a++)
	{
		if(a!=1) tot++;
		int b=a,h=a,m=0;
		for(;b<h+k&&b<=n;b++)
		{
			m=max(m,x[b]);
			a=b;
		}
		tot+=m;
		if(tot>w) return 0;
	}
	return 1;
}
int main()
{
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int a=1;a<=n;a++) scanf("%d",&x[a]);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid)==1) r=mid;
		else l=mid+1;
	}
	printf("%d",l);
}
