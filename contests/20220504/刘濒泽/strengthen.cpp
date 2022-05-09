#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("strengthen.in","r",stdin),freopen("strengthen.out","w",stdout);
	ll n;
	double p;
	scanf("%lld%lf",&n,&p);
	if(fabs(p-0.5)<1e-5)
		printf("%.6lf",1.0*n*(n+1.0));
	else
		printf("%.6lf",((pow(1.0/p-1.0,n+1.0)-1.0)/(1.0/p-2.0)-n-1.0)/(1.0-2.0*p));
	return 0;
}
