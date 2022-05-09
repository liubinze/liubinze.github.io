#include<bits/stdc++.h>
using namespace std;
int last,n,zhi[100001],zong,you,zuo,max_;
int ans=1e9;
int main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		zhi[a]+=b;
		zong+=a*b;
		you+=b;
		max_=max(max_,a);
	}
	last=zong;
	for(int i=1;i<=max_;i++)
	{
		int now=last-you+zuo;
		if(zhi[i]!=0)
		{
		zuo+=zhi[i];
		you-=zhi[i];
		}
		last=now;
		ans=min(last,ans);
	}
	cout<<ans;
}
