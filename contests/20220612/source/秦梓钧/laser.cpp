#include<bits/stdc++.h>
using namespace std;
int n,m;
char x[505][505];
int T;
struct node{
	int x,y;
	node(int x_,int y_){
		x=x_,y=y_;
	}
};
vector<node>vec;
int c=0;
bool cl[505][505],cl1[505][505];
bool fl=0;
void dfs(int now,int k){
	if(fl)return;
	if(now==c+1&&k==0){
		fl=1;
		puts("Yes");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)putchar(x[i][j]);
			puts("");
		}
		return;
	}
	else if(now==c+1)return;
	int nx=vec[now-1].x,ny=vec[now-1].y;
	bool use=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cl1[i][j]=cl[i][j];
	}
	int kk=k;
	for(int i=nx-1;i;i--){
		if(x[i][ny]=='#')break;
		if(x[i][ny]=='|'||x[i][ny]=='-'||x[i][ny]=='S'){
			use=1;
			break;
		}
		if(!cl[i][ny])cl[i][ny]=1,k--;
	}
	for(int i=nx+1;i<=n;i++){
		if(x[i][ny]=='#')break;
		if(x[i][ny]=='|'||x[i][ny]=='-'||x[i][ny]=='S'){
			use=1;
			break;
		}
		if(!cl[i][ny])cl[i][ny]=1,k--;
	}
	if(!use){
		x[nx][ny]='|';
		dfs(now+1,k);
	}
	k=kk;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cl[i][j]=cl1[i][j];
	}
	use=0;
	for(int i=ny-1;i>=1;i--){
		if(x[nx][i]=='#')break;
		if(x[nx][i]=='|'||x[nx][i]=='-'||x[nx][i]=='S'){
			use=1;
			break;
		}
		if(!cl[nx][i])cl[nx][i]=1,k--;
	}
	for(int i=ny+1;i<=m;i++){
		if(x[nx][i]=='#')break;
		if(x[nx][i]=='|'||x[nx][i]=='-'||x[nx][i]=='S'){
			use=1;
			break;
		}
		if(!cl[nx][i])cl[nx][i]=1,k--;
	}
	if(!use){
		x[nx][ny]='|';
		dfs(now+1,k);
	}
	x[nx][ny]='S';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cl[i][j]=cl1[i][j];
	}
}
int main(){
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%s",x[i]+1);
		vec.clear();
		int cs=0;
		c=0;
		fl=0;
		memset(cl,0,sizeof cl);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(x[i][j]=='S')vec.push_back(node(i,j)),c++;
				else if(x[i][j]=='.')cs++;
			}
		}
		dfs(1,cs);
		if(!fl)puts("No");
	}
	return 0;
}
