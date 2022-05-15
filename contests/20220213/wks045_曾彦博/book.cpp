#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1e9 * 2e5;
long long val[200005],n,m;

bool check(long long mid)
{
	int cnt = 0,tot = 0;
	for(int i = 1;i <= n;i++)
	{
		if(tot <= mid) cnt++,tot = val[i];
		else tot += val[i];
	}
	if(tot <= mid) cnt++;
	return cnt > m;
}

int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i = 1;i <= n;i++) scanf("%lld",&val[i]);
	long long l = -MAX,r = MAX;
//	if(check(0)) printf("!");
	while(l <= r)
	{
//		printf("%lld %lld\n",l,r);
		long long mid = (l + r) >> 1;
		if(!check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	if(check(l - 1)) l--;
	printf("%lld",l);
	return 0;
}
