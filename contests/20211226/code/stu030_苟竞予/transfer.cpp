#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int u,v;
	ll w;
}Edge[100005];
bool cmp(node a,node b){return a.w>b.w;}
int n,m,fa[100005];
ll ra[100005];
int find(int r){return r==fa[r]?r:(fa[r]=find(fa[r]));}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
    if(fx==fy)return ;
    fa[fy]=fx;
    ra[fx]+=ra[fy];
    return ;
}
int main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    	int u,v;ll w;
    	scanf("%d%d%lld",&u,&v,&w);
    	Edge[i].u=u,Edge[i].v=v,Edge[i].w=w;
	}
	for(int i=1;i<=n;i++)fa[i]=i,ra[i]=1ll;
	sort(Edge+1,Edge+m+1,cmp);
	ll ans=0;
	for(int i=1;i<=m;i++){
		if(find(Edge[i].u)!=find(Edge[i].v))ans+=1ll*ra[find(Edge[i].u)]*ra[find(Edge[i].v)]*Edge[i].w;
		else ans+=1ll*ra[find(Edge[i].u)]*Edge[i].w;
		merge(Edge[i].u,Edge[i].v);
	}
	cout<<ans;
	return 0;
}
