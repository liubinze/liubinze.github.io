#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("moon.in","r",stdin),
	freopen("moon.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	if(n==0ll)
		printf("2");
	else if(n==15ll)
		printf("13");
	else if(m==0ll)
		printf("1");
	else if(m==15ll)
		printf("14");
	else if(m<n)
		printf("%lld",m-1ll);
	else if(m>n)
		printf("%lld",m+1ll);
	else
		printf("I_love_NotDeep!");
	return 0;
}
