#include<bits/stdc++.h>
using namespace std;
int n,m,tot;
char a[200005],e[200005];
struct Node{int a,b,Cnt,g[80],Lazy[80];}Tree[800005];
void BuildTree(int p,int x,int y){
	Tree[p].a=x;
	Tree[p].b=y;
	Tree[p].Cnt=0;
	if(x==y){
		Tree[p].Cnt=1;
		Tree[p].g[(int)a[x]-47]=1;
		return ;
	}
	int mid=(x+y)>>1;
	BuildTree(p<<1,x,mid);
	BuildTree(p<<1|1,mid+1,y);
	Tree[p].Cnt=Tree[p<<1].Cnt+Tree[p<<1|1].Cnt;
	for(int i=1;i<=80;i++) Tree[p].g[i]=Tree[p<<1].g[i]+Tree[p<<1|1].g[i];
}
void pd(int p,int x){
	Tree[p<<1].Cnt-=Tree[p<<1].g[x];
	Tree[p<<1].g[x]=0;
	Tree[p<<1].Lazy[x]=1;
	Tree[p<<1|1].Cnt-=Tree[p<<1|1].g[x];
	Tree[p<<1|1].g[x]=0;
	Tree[p<<1|1].Lazy[x]=1;
	Tree[p].Lazy[x]=0;
}
void Change(int p,int x,int y,char z){
	for(int i=1;i<=80;i++) 
		if(Tree[p].Lazy[i]==1) pd(p,i); 
	if(x<=1&&Tree[p].Cnt<=y) {
		int k=(int)z-47;
		Tree[p].Cnt-=Tree[p].g[k];
		Tree[p].g[k]=0;
		Tree[p].Lazy[k]=1;
		return ;
	}
	int kl=Tree[p<<1].Cnt;
	if(x<=kl) Change(p<<1,x,y,z);
	if(y>kl) Change(p<<1|1,max(x-kl,1),y-kl,z);
	Tree[p].Cnt=Tree[p<<1].Cnt+Tree[p<<1|1].Cnt;
	for(int i=1;i<=80;i++) Tree[p].g[i]=Tree[p<<1].g[i]+Tree[p<<1|1].g[i];
}
void Ask(int p,int x,int y){
	for(int i=1;i<=80;i++) 
		if(Tree[p].Lazy[i]==1) pd(p,i); 
	if(Tree[p].Cnt==1) {
		for(int i=1;i<=80;i++)
			if(Tree[p].g[i]==1) {
				e[++tot]=char(i+47);
				break;	
			}
		return ;
	}
	int kl=Tree[p<<1].Cnt;
	if(x<=kl) Ask(p<<1,x,y);
	if(y>kl) Ask(p<<1|1,max(x-kl,1),y-kl);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d\n%s",&n,&m,a+1);
	BuildTree(1,1,n);
	while(m--){
		int x,y;
		char op[3];
		scanf("%d%d%s",&x,&y,op);
		Change(1,x,y,op[0]);
	}
	Ask(1,1,Tree[1].Cnt);
	for(int i=1;i<=tot;i++) putchar(e[i]);
}
