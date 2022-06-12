#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<stdio.h>
#include<algorithm>
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,65536,stdin),p1==p2)?EOF:*p1++)
namespace freader
{
	char buf[65539],*p1=buf,*p2=buf;
	inline int read()
	{
	    int x(0);
	    char ch;
	    while((ch=gc)<'0'||ch>'9');
	    do
	       x=(x<<3)+(x<<1)+ch-'0';
	    while((ch=gc)>='0'&&ch<='9');
	    return x;
	}
}
const int N=2000001;
bool mark[N],f;
int u[N],v[N],t[N],len,las[N],nex[N],en[N],lien,li[N],scc,col[N],ti,ans[N];
struct st
{
	int x,y,id,s;
}e[N];
inline void addedg(int x,int y)
{
	nex[++len]=las[x],las[x]=len,en[len]=y;
	return;
}
inline void dfs(int x)
{
	if(f)
		col[x]=scc,ans[scc]+=e[x].s;
	else
		mark[x]=1;
	for(int i=las[x];i;i=nex[i])
		if(f&&!col[en[i]]||!f&&!mark[en[i]])
			dfs(en[i]);
	if(!f)
		li[lien++]=x;
	return;
}
inline int getans(int x,int n)
{
	col[x]=ti;
	int s=ans[x-n];
	for(int i=las[x];i;i=nex[i])
		if(col[en[i]]<ti)
			s+=getans(en[i],n);
	return s;
}
int main()
{
	freopen("network.in","r",stdin),freopen("network.out","w",stdout);
	int n=freader::read(),m=freader::read(),a=freader::read(),b=freader::read(),_;
	for(int i=1;i<=n;i++)
		e[i].x=freader::read(),e[i].y=freader::read(),e[i].id=i,e[i].s=int(e[i].x==a);
	for(int i=0;i<m;i++)
		u[i]=freader::read(),v[i]=freader::read(),t[i]=freader::read(),addedg(u[i],v[i]),t[i]>1?addedg(v[i],u[i]):void();
	for(int i=1;i<=n;i++)
		if(!mark[i])
			dfs(i);
	f=1;
	for(int i=0;i<lien;i++)
		if(!col[li[i]])
			scc++,dfs(li[i]);
	for(int i=0;i<m;i++)
		if(col[u[i]]^col[v[i]])
			addedg(col[u[i]]+n,col[v[i]]+n),t[i]>1?addedg(col[v[i]]+n,col[u[i]]+n):void();
	std::sort(e+1,e+n+1,[](st a,st b){return a.x<b.x||a.x==b.x&&a.y>b.y;});
	for(int i=1;i<=n;i++)
		if(e[i].x==0)
			ti++,printf("%d\n",ans[col[e[i].id]+n]?ans[col[e[i].id]+n]:ans[col[e[i].id]+n]=getans(col[e[i].id]+n,n));
	return 0;
}
