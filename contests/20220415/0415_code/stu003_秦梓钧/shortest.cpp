#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,f;
}a[100005];
int C,n,m;
struct edge{
	int to,val;
	edge(int to_,int val_){
		to=to_,val=val_;
	}
};
vector<edge>vec[200005];
long long dis[200005];
int c[100005];
bool mark[200005];
struct pq{
	int u,w;
	pq(int u_,int w_){
		u=u_,w=w_;
	}
};
priority_queue<pq>q;
bool operator<(pq x,pq y){
	return x.w>y.w;
}
int main(){
	freopen("shortest.in","r",stdin);
	freopen("shortest.out","w",stdout);
	scanf("%d%d%d",&n,&m,&C);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].f);
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		c[i]=n+i;
	}
	for(int i=1;i<=n;i++){
		vec[c[a[i].f]].push_back(edge(i,0));
		if(a[i].f!=n)
		vec[i].push_back(edge(c[a[i].f+1],C));
		if(a[i].f!=1)
		vec[i].push_back(edge(c[a[i].f-1],C));
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		vec[x].push_back(edge(y,z));
		vec[y].push_back(edge(x,z));
	}
	memset(dis,0x7f,sizeof dis);
	int st=1,ed=n;
	q.push(pq(st,0));
	dis[st]=0;
	while(!q.empty()){
		pq tp=q.top();
		q.pop();
		if(tp.u==ed){
			break;
		}
		if(mark[tp.u])continue;
		mark[tp.u]=1;
		int u=tp.u;
		for(int i=0;i<vec[u].size();i++){
			if(dis[vec[u][i].to]>tp.w+vec[u][i].val){
				dis[vec[u][i].to]=tp.w+vec[u][i].val;
				q.push(pq(vec[u][i].to,dis[vec[u][i].to]));
			}
		} 
	}
	if(dis[ed]==dis[0])puts("-1");
	else printf("%lld",dis[ed]);
	return 0;
}

