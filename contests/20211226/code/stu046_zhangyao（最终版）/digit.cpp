#include<bits/stdc++.h>
using namespace std;
long long q;
long long s(long long x)
{
	long long tp=0;
	while(x)
	{
		tp+=x%10;
		x/=10;
	}
	return tp;
}
long long f(long long x)
{
	if(x<10)
	{
		return x;
	}
	else
	{
		return f(s(x));
	}
}
int main()
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	cin >> q;
	for(long long i=1;i<=q;i++)
	{
		long long t1,t2,cnt;
		cin >> t1 >> t2;
		long long ans=0;
		for(long long i=t1;i<=t2;i++)
		{
			ans+=f(i);
		}
		cout << ans << endl;
	}
	return 0;
}
