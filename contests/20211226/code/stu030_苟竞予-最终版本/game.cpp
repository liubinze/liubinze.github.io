#include<bits/stdc++.h>
using namespace std;
struct node{int x,y;};
bool vis[31][31],flag;
int n,m,Sx,Sy,Tx,Ty,tot;
char ans[32],a[31][31];
node Right(int x,int y){
	for(int j=y+1;j<=m;j++)
	 if(vis[x][j])return node{x,j};
	return node{0,0};
}
node Left(int x,int y){
	for(int j=y-1;j>=1;j--)
	 if(vis[x][j])return node{x,j};
	return node{0,0};
}
node Up(int x,int y){
	for(int i=x-1;i>=1;i--)
	 if(vis[i][y])return node{i,y};
	return node{0,0};
}
node Down(int x,int y){
	for(int i=x+1;i<=n;i++)
	 if(vis[i][y])return node{i,y};
	return node{0,0};
}
void dfs(int i,int j,int x,char lst){
	if(flag)return ;
	if(x==tot&&i==Tx&&j==Ty){
		printf("YES\n");
		for(int i=1;i<tot;i++)printf("%c",ans[i]);
		printf("\n");
		flag=true;
		return ;
	}
	node R=Right(i,j),D=Down(i,j),L=Left(i,j),U=Up(i,j);
	vis[i][j]=0;
	if(lst!='L'&&R.x)ans[x]='R',dfs(R.x,R.y,x+1,'R');
	if(lst!='U'&&D.x)ans[x]='D',dfs(D.x,D.y,x+1,'D');
	if(lst!='R'&&L.x)ans[x]='L',dfs(L.x,L.y,x+1,'L');
	if(lst!='D'&&U.x)ans[x]='U',dfs(U.x,U.y,x+1,'U');
	vis[i][j]=1;
	return ;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
    	memset(vis,0,sizeof(vis));
    	flag=false;
    	tot=0;
    	scanf("%d%d",&n,&m);
    	for(int i=1;i<=n;i++)scanf("%s",a[i]);
    	for(int i=1;i<=n;i++)
    	 for(int j=m;j>=1;j--)a[i][j]=a[i][j-1];
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			if(a[i][j]!='#')vis[i][j]=1,++tot;
    			if(a[i][j]=='S')Sx=i,Sy=j;
    			if(a[i][j]=='T')Tx=i,Ty=j;
			}
		}
		dfs(Sx,Sy,1,'A');
		if(!flag)printf("NO\n");
	}
	return 0;
}
