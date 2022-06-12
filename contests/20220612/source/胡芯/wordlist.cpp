#include <random>
#include <bits/stdc++.h>
#define _rep(i,a,b) for(register int i(a);i^(b+1);i=-~i)
using namespace std;
int n,m;
int a[(int)1.0E6+7];
int k;
long long kr;
int main()
{
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	_rep(i,1,n) scanf("%d",&a[i]),kr+=a[i];
	
	srand((unsigned)time(NULL));
	kr/=n;
	k=rand()%n+1;
	while (clock()<=900)
	{
		k=rand()%n+1;
	}
	printf("%lld",a[k]*kr>>(n>>2));
	return 0;
}
