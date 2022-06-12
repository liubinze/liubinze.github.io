#include<bits/stdc++.h>
using namespace std;
char x[35][35];
int n,m;
//int xx[1005],y[1005];
int ans;
int ma[35][35];
vector<int>vec[105];
int link[105],road[105],tim;
bool vis[105];
void dfs(int cnt){
	int sy=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x[i][j]=='*')sy++;
		}
	}
	if(sy==0){
		ans=min(ans,cnt-1);
		return;
	}
	int kkk=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			kkk++;
			int tot=0;
			for(int k=1;k<=n;k++){
				if(x[k][j]=='*')tot++,x[k][j]='.',ma[k][j]=cnt;
			}
			for(int k=1;k<=m;k++){
				if(x[i][k]=='*')tot++,x[i][k]='.',ma[i][k]=cnt;
			}
			if(tot==0)continue;
			dfs(cnt+1);
			for(int ii=1;ii<=n;ii++){
				for(int jj=1;jj<=m;jj++){
					if(ma[ii][jj]==cnt)x[ii][jj]='*',ma[ii][jj]=0;
				}
			}
		}
	}
}
int getid(int i,int j){
	return (i-1)*m+j;
}
bool Dfs(int now){
	for(int i=0;i<vec[now].size();i++){
		int to=vec[now][i];
		if(road[to]!=tim){
			road[to]=tim;
			if(link[to]==0||Dfs(link[to])){
				link[to]=now;
				link[now]=to;
				return 1;
			}
		}
	}
	return 0;
}
vector<int>vec1[105];
void s(int now){
	if(vis[now])return;
	vis[now]=1;
	if(now<=n){
		for(int i=0;i<vec[now].size();i++){
			int to=vec[now][i];
			if(link[to]!=now)s(to);
		}
	}
	else{
		for(int i=0;i<vec1[now].size();i++){
			int to=vec1[now][i];
			if(link[to]==now)s(to);
		}
	}
}
int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n<=5&&m<=5){
		for(int i=1;i<=n;i++)scanf("%s",x[i]+1);
		ans=1e9;
		memset(ma,0,sizeof ma);
		dfs(1);
		printf("%d\n",ans);
		continue;
		}
		for(int i=1;i<=n;i++)scanf("%s",x[i]+1),vec[i].clear();
		for(int i=n+1;i<=n+m;i++)vec1[i].clear();
		memset(link,0,sizeof link);
		memset(road,0,sizeof road);
		memset(vis,0,sizeof vis);
		tim=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(x[i][j]=='*'){
					vec[i].push_back(j+n);
					vec1[j+n].push_back(i);
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			tim++;
			if(Dfs(i))cnt++;
		}
		for(int i=1;i<=n;i++){
			if(link[i]==0){
				s(i);
			}
		}
		int l=0,r=0;
		for(int i=1;i<=n;i++){
			if(!vis[i])l++;
		}
		for(int i=n+1;i<=n+m;i++)if(vis[i])r++;
		printf("%d\n",max(l,r));
	}
	return 0;
}
