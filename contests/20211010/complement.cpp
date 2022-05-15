#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000003];
int main()
{
	freopen("complement.in","r",stdin),
	freopen("complement.out","w",stdout);
	scanf("%s",s);
	ll n=strlen(s);
	if(s[0]^'1')
		printf(s);
	else
	{
		putchar(s[0]);
		for(ll i=1ll;i<n;i++)
			putchar(s[i]^'0'^'1');
	}
	return 0;
}
