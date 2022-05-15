#include<bits/stdc++.h>
using namespace std;
int n,k;
const int m=10;
int a[105][15];
char x[105][15];
bool g[105][15],vis[105][15];
struct node{
	int x,y;
	node(int x_,int y_){
		x=x_,y=y_;
	}
};
vector<node>vec[1005];
int tot=0;
void dfs(int x,int y){
	vec[tot].push_back(node(x,y));
	g[x][y]=1;
	if(a[x][y]==a[x-1][y]&&x>1&&!g[x-1][y])dfs(x-1,y);
	if(a[x][y]==a[x+1][y]&&x<n&&!g[x+1][y])dfs(x+1,y);
	if(a[x][y]==a[x][y-1]&&y>1&&!g[x][y-1])dfs(x,y-1);
	if(a[x][y]==a[x][y+1]&&y<m&&!g[x][y+1])dfs(x,y+1);
}
int main(){
	freopen("mooyo.in","r",stdin);
	freopen("mooyo.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%s",x[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)a[i][j]=x[i][j]-'0';
	while(1){
		int maxsize=0;
		for(int i=1;i<=1e3;i++)vec[i].clear();
		memset(g,false,sizeof g);
		memset(vis,false,sizeof vis);
		tot=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(!g[i][j]&&a[i][j]>0){
					dfs(i,j);
				}
			}
		}
		for(int i=1;i<=tot;i++){
			int size=vec[i].size();
			maxsize=max(maxsize,size);
		}
		if(maxsize<k)break;
		for(int i=1;i<=tot;i++){
			int size=vec[i].size();
			if(size>=k)for(int j=0;j<size;j++)vis[vec[i][j].x][vec[i][j].y]=1;
		}
		queue<int>q;
		for(int j=1;j<=m;j++){
			while(!q.empty())q.pop();
			for(int i=n;i>=1;i--){
				if(a[i][j]==0)q.push(i);
				else if(a[i][j]!=0||vis[i][j]){
					if(q.empty())continue;
					a[q.front()][j]=a[i][j];
					a[i][j]=0;
					q.push(i);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)printf("%d",a[i][j]);
		puts("");
	} 
	return 0;
} 
