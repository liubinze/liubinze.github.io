#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int t;
ull n,k;

int main()
{
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ull x=n&(-n);
		x=(n+x)|((n^(n+x))/x)>>2;
		cout<<x<<endl;
	}
	return 0;
}
