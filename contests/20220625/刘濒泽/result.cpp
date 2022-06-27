#include<stdio.h>
#include<string.h>
typedef long long ll;
const ll c=2009ll;
char n[c];
ll nl,p,len,nn[c],nnl;
int main()
{
	ll t=1ll,s=0ll,m=0ll;
	scanf("%s%lld",n,&p),nl=strlen(n);
	for(len=1ll;;len++)
	{
		s=(s+(t=t*p%c)*len%c)%c;
		if(s==0ll&&t==1ll)
			break;
	}
	for(ll i=0ll;i<nl;i++)
		n[2*nl-i-1]=n[i];
	for(ll i=nl,u;i<nl<<1ll;i+=13ll,nnl++)
		for(ll j=(i+12ll<(nl<<1ll)-1ll)?i+12ll:(nl<<1ll)-1ll;j>=i;j--)
			nn[nnl]=nn[nnl]*10ll+ll(n[j]-'0');
	for(ll i=nnl-1ll;~i;i--)
		m=(m*ll(1e13)+nn[i])%len;
	for(ll i=1ll;i<=m;i++)
		s=(s+(t=t*p%c)*i%c)%c;
	printf("%lld",s);
	return 0;
}
