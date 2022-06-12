#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
vector<int>vec[300005];
struct node{
	int id,val;
	node(int id_,int val_){
		id=id_,val=val_; 
	}
};
bool cmp(node x,node y){
	return x.val>y.val;
}
vector<node>st;
bool vis[300005];
int x[300005],y[300005],ans;
bool ed[300005];
void dfs(int now){
	if(vis[now]==1)return;
	vis[now]=1;
	if(ed[now])ans++;
	for(int i=0;i<vec[now].size();i++){
		int to=vec[now][i];
		dfs(to);
	}
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]==a)ed[i]=1;
		if(x[i]==0)st.push_back(node(i,y[i]));
	}
	sort(st.begin(),st.end(),cmp);
	while(m--){
		int x,y,op;
		scanf("%d%d%d",&x,&y,&op);
		if(op==1)vec[x].push_back(y);
		else if(op==2)vec[x].push_back(y),vec[y].push_back(x);
	}
	for(int i=0;i<st.size();i++){
		memset(vis,0,sizeof vis);
		ans=0;
		dfs(st[i].id);
		printf("%d\n",ans);
	}
	return 0;
}
