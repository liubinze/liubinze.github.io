#include<bits/stdc++.h>
using namespace std;
char s[35][35],an[35];
int n,m,t,h[35],l[35];
int sx,sy,tx,ty,maxk;
bool p;
struct node{
	int r,u,d,l;
}a[35][35];
void dfs(int x,int y,int k,char f){
	if(x==tx&&y==ty&&k==maxk) p=1;
	int r=a[x][y].r;
	int l=a[x][y].l;
	int u=a[x][y].u;
	int d=a[x][y].d;
	a[x][r].l=l;
	a[x][l].r=r;
	a[u][y].d=d;
	a[d][y].u=u;
	if(f!='D'&&u!=0){
		dfs(u,y,k+1,'U');
		if(p==1){
			an[k]='U';
			return;
		}
	}
	if(f!='U'&&d!=0){
		dfs(d,y,k+1,'D');
		if(p==1){
			an[k]='D';
			return;
		}
	}
	if(f!='L'&&r!=0){
		dfs(x,r,k+1,'R');
		if(p==1){
			an[k]='R';
			return;
		}
	}
	if(f!='R'&&l!=0){
		dfs(x,l,k+1,'L');
		if(p==1){
			an[k]='L';
			return;
		}
	}
	a[x][r].l=y;
	a[x][l].r=y;
	a[u][y].d=x;
	a[d][y].u=x;
}
void love(){
	for(int i=0;i<=n;i++) h[i]=0;
	for(int j=0;j<=m;j++) h[j]=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			a[i][j].r=0;
	        a[i][j].l=0;
	        a[i][j].u=0;
	        a[i][j].d=0;
		}
	}
	maxk=0,p=0;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&t);
	for(int v=1;v<=t;v++){
		love();
	    scanf("%d%d",&n,&m);
	    for(int i=1;i<=n;i++){	
		    for(int j=1;j<=m;j++){
			    cin>>s[i][j];
			    if(s[i][j]=='S')
			        sx=i,sy=j;
			    if(s[i][j]=='T')
			        tx=i,ty=j;
		    }
	    }
	    for(int i=1;i<=n;i++){
	    	for(int j=1;j<=m;j++){
	    		if(s[i][j]!='#'){
	    		    a[i][h[i]].r=j;
	    		    a[i][j].l=h[i];
	    		    a[l[j]][j].d=i;
	    		    a[i][j].u=l[j];
	    		    h[i]=j,l[j]=i;
	    		    maxk++;
	    		}
			}
	    }
	    dfs(sx,sy,1,'q');
	    if(p==0) printf("NO\n");
	    else{
	    	printf("YES\n");
	        for(int i=1;i<maxk;i++)
			    printf("%c",an[i]);
	        printf("\n");
	    }
	}
}
