#include<bits/stdc++.h>
using namespace std;
int t;
typedef unsigned long long ll;
ll fun(ll n)
{
	ll x=n & -n;
	return (n+x) | ((n^(n+x))/x)>>2;
}
int main()
{
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		cout<<fun(n)<<endl;
	}
}
