#include<iostream>
using namespace std;
unsigned long long t,n,k;

unsigned long long func(unsigned long long n)
{
	unsigned long long x=n&(-n);
	return (n+x)|(((n^(n+x)))/x)>>2ll;
}
unsigned long long funk(unsigned long long n,unsigned long long kkkk)
{
	unsigned long long x=n&(-n);
	unsigned long long xx=(n+x)%kkkk;
	return (xx)|((n^xx)/x)>>2ll;
}
int main()
{
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		unsigned long long kk=1ll<<k;
		if(k==64)
			printf("%lld\n",func(n));
		else
			printf("%lld\n",funk(n,kk-1));
	}
}

