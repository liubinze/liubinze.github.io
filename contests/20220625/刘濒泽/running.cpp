#include<algorithm>
#include<queue>
#include<stdio.h>
typedef long long ll;
bool mark[1111111];
ll dad[1111111],len,las[1111111],nex[2333333],en[2333333],di[2333333];
struct road
{
	ll a,b,t,c;
}e[1111111];
struct pos
{
	ll id,dis;
}p[1111111],x;
inline bool operator<(pos a,pos b)
{
	return a.dis>b.dis;
}
std::priority_queue<pos>q;
inline void read(ll&x)
{
	char c(getchar());
	x=0ll;
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
		x=(x<<3ll)+(x<<1ll)+ll(c-'0'),c=getchar();
	return;
}
inline ll getdad(ll x)
{
	return dad[x]^x?dad[x]=getdad(dad[x]):x;
}
inline void addedg(ll x,ll y,ll z)
{
	nex[++len]=las[x],las[x]=len,en[len]=y,di[len]=z;
	return;
}
int main()
{
	ll n,m,s,t,u,_max;
	read(n),read(m),std::iota(dad,dad+n+1,0);
	for(ll i=0ll;i<m;i++)
		read(e[i].a),read(e[i].b),read(e[i].t),read(e[i].c);
	read(s),read(t),std::sort(e,e+m,[](road x,road y){return x.t<y.t;});
	for(u=0ll;u<m&&getdad(s)^getdad(t);u++)
		dad[getdad(e[u].a)]=getdad(e[u].b),addedg(e[u].a,e[u].b,e[u].t*e[u].c),addedg(e[u].b,e[u].a,e[u].t*e[u].c),_max=e[u].t;
	for(;u<m&&e[u].t==_max;u++)
		addedg(e[u].a,e[u].b,e[u].t*e[u].c),addedg(e[u].b,e[u].a,e[u].t*e[u].c);
	for(ll i=0ll;i<=n;i++)
		p[i]=pos{i,ll(2e18)};
	p[s].dis=0ll,q.push(p[s]);
	while(!q.empty())
	{
		x=q.top(),q.pop();
		if(mark[x.id])
			continue;
		mark[x.id]=1;
		for(ll i=las[x.id];i;i=nex[i])
			if(p[en[i]].dis>x.dis+di[i])
				p[en[i]].dis=x.dis+di[i],q.push(p[en[i]]);
	}
	printf("%lld %lld",_max,p[t].dis);
	return 0;
}
