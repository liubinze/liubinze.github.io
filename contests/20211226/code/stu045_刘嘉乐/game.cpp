#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,sx,sy,tx,ty,b[35][35][5];
char a[35][35];
int dfs(int x,int y){
	
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			if(a[i][j]=='S')sx=i,sy=j;
			if(a[i][j]=='T')tx=i,ty=j;
			if(a[i][j]=='.'){
				for(int l=1;l<i;l++)b[l][j][3]=(b[l][j][3]==0?i-l:min(b[l][j][3],i-l));
				for(int l=i+1;l<=n;l++)b[l][j][1]=(b[l][j][1]==0?l-i:min(b[l][j][1],l-i));
				for(int l=1;l<j;l++)b[i][l][2]=(b[i][l][2]==0?j-l:min(b[i][l][2],j-l));
				for(int l=j+1;l<=n;l++)b[i][l][4]=(b[i][l][4]==0?l-j:min(b[i][l][4],l-j));
				k++;
			}
		}
		dfs(sx,sy);
		printf("NO\n");
	}
	return 0;
}
