#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int n,w;
int a[N];

bool check(int h)
{
	int m=0;
	long long tot=0;
	for(int i=1;i<=n;i++)
	{
		if(i%h==1)
		{
			tot+=m;
			m=a[i];
		}
		else m=max(m,a[i]);
	}
	tot+=m;
	if(n%h==0)tot+=n/h-1;
	else tot+=n/h;
	if(tot>w)return 0;
	else return 1;
}

int main()
{
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
	return 0;
}
