#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
bool ip[1000001];
int a[1000001],lp,p[1000001];
inline void Euler(int n)
{
	for(int i(2);i<=n;i++)
		ip[i]=1;
	for(int i(2),t;i<=n;i++)
	{
		if(ip[i])
			p[lp++]=i;
		for(int j(0),t(n/i);j<lp&&p[j]<=t;j++)
		{
			ip[i*p[j]]=0;
			if(i%p[j]==0)
				break;
		}
	}
	return;
}
int main()
{
	freopen("square.in","r",stdin),freopen("square.out","w",stdout);
	int n;
	scanf("%d",&n),Euler(100000);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		for(int j=0,t;j<lp&&(t=p[j]*p[j])<=a[i];j++)
			while(a[i]%t==0)
				a[i]/=t;
	}
	sort(a,a+n),printf("%d",unique(a,a+n)-a);
	return 0;
}
