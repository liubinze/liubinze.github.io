#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000003],t[1000003],u[1000001];
int main()
{
	freopen("double.in","r",stdin),freopen("double.out","w",stdout);
	ll T,n,m,o,N;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%s",&n,t),m=strlen(t),o=N=0ll;
		for(ll i=0ll;i<m;i++)
			if(t[i]=='w')
				u[o++]='u',u[o++]='u';
			else if(t[i]=='m')
				u[o++]='n',u[o++]='n';
			else
				u[o++]=t[i];
		if(n>o)
			puts("Horse\'s!"),exit(0);
		for(ll i=0ll;i<o;i++)
			if(i<o-1ll&&u[i]==u[i+1]&&(u[i]=='u'||u[i]=='n')&&n<o)
				s[N++]=(u[i]=='u'?'w':'m'),i++,n++;
			else
				s[N++]=u[i];
		if(n<o)
			puts("Horse\'s!"),exit(0);
		s[N]='\0',puts(s);
	}
	return 0;
}
