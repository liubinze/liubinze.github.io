#include<bits/stdc++.h>
using namespace std;
long long t,l,r;
string s;
long long he(long long x)
{
	int ans=0;
	while(x>0)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}
long long k(string o)
{
	int sum1=o.length(),ko=0;
	for(int i=0;i<sum1;i++)
	{
		ko+=o[i]-'0';
	}
	return ko;
}
long long f(long long u)
{
	long long ans1=0;
	ans1=u;
	if(u>=10)ans1=f(he(u));
	return ans1;
}
signed main()
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	cin>>t;
	while(t--)
	{
		long long ans2=0;
		cin>>l>>r;
		for(int i=l;i<=r;i++)
		{
			ans2+=f(i);
		}
		cout<<ans2<<endl;;
	}
}
