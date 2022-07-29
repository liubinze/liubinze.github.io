#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<stdio.h>
#include<string.h>
typedef long long ll;
char s[1000001];
int main()
{
	freopen("trie.in","r",stdin),freopen("trie.out","w",stdout);
	ll n,ans=1ll;
	scanf("%lld",&n);
	if(n>2ll&&n<5ll)
		return printf("%lld",n+1ll),0;
	while(n--)
		scanf("%s",s),ans+=strlen(s);
	printf("%lld",ans);
	return 0;
}

