#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct cow
{
	ll a,t,o,m;
}e[1000001],w;
inline bool operator<(cow x,cow y)
{
	return x.m>y.m;
}
priority_queue<cow>pq;
int main()
{
	freopen("grass.in","r",stdin),freopen("grass.out","w",stdout);
	bool f=1;
	ll n,s=1ll,ti,_max=0ll;
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%lld%lld",&e[i].a,&e[i].t),e[i].m=i;
	sort(e,e+n,[](cow x,cow y){return x.a<y.a||x.a==y.a&&x.m<y.m;}),w=e[0],ti=w.a,w.o=w.a+w.t;
	while(1)
	{
		if(f&&s<n&&w.o<e[s].a)
		{
			ti=w.o;
			if(pq.empty())
				f=0;
			else
				w=pq.top(),pq.pop(),w.o=ti+w.t,_max=max(_max,ti-w.a);
		}
		else if(f&&s<n)
			ti=e[s].a,pq.push(e[s++]);
		else if(s<n)
			w=e[s++],ti=w.a,w.o=w.a+w.t,f=1;
		else
			break;
	}
	printf("%lld",_max);
	return 0;
}
