#include<bits/stdc++.h>
using namespace std;
const long long SIZE=1<<20;
char buf[SIZE],*p1,*p2;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++)
void read(int &x){
	x=0;
	char ch;
	while(!isdigit(ch=gc));
	do {
		x=x*10+ch-'0';
	}while(isdigit(ch=gc));
}
int n,m,A,B,a,b,c,cnt,ans,x[500005],y[500005];
int dc,d[500005];
bool bl[500005];
int h[500005],to[2000005],nxt[2000005];
void jb(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=h[u];
	h[u]=cnt;
}
void dfs(int u){
	if(bl[u]==1) return;
	bl[u]=1;
	if(x[u]==A) ans++;
	for(int i=h[u];i!=0;i=nxt[i]){
		dfs(to[i]);
	}
}
bool cmp(int aa,int bb){
	return y[aa]>y[bb];
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	read(n);
	read(m);
	read(A);
	read(B);
	for(int i=1;i<=n;i++){
		read(x[i]);
		read(y[i]);
		if(x[i]==0) d[++dc]=i;
	}
	for(int i=1;i<=m;i++){
		read(a);
		read(b);
		read(c);
		jb(a,b);
		if(c==2) jb(b,a);
	}
	sort(d+1,d+dc+1,cmp);
	for(int i=1;i<=dc;i++){
		ans=0;
		for(int j=1;j<=n;j++) bl[j]=0;
		dfs(d[i]);
		printf("%d\n",ans);
	}
}
