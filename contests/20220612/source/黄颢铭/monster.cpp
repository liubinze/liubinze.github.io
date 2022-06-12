#include<bits/stdc++.h>
#define maxn 35
#define maxm 1405
using namespace std;
char c[maxn];
int head[maxm],link[maxm],vis[maxm],tot;
struct node{
	int x,y,nxt;
}e[maxm];

void add(int x,int y)
{
	tot++;
	e[tot].nxt=head[x];
    e[tot].x=x;
    e[tot].y=y;
	head[x]=tot;
}
int dfs(int u){
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].y;
		if(vis[v])continue;
		vis[v]=1;
		if(!link[v]||dfs(link[v])){
			link[v]=u;
			return 1;
		}
	}
	return 0;
}
int n,m;
int max_match(){
	memset(link,0,sizeof link);
	int cnt=0;
	for(int i=1;i<=m;i++){
		memset(vis,0,sizeof vis);
		cnt+=dfs(i+n);
	}
	return cnt;
}
int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(head,0,sizeof head);
		memset(e,0,sizeof e);
		tot=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>c;
			for(int j=1;j<=m;j++){
				if(c[j-1]=='*'){
					add(i,j+n);
			        add(j+n,i);
				}
			}
		}
		int ans=max_match();
		//for(int i=1;i<=n;i++)cout<<i<<" "<<link[i+n]<<endl;
		cout<<ans<<endl;
	}
}

/*
1
8 10
..........
..***..*.*
.*.......*
.*.......*
.*.......*
.....*****
..........
.........*
*/
