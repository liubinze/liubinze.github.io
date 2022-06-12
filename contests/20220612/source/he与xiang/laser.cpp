#include<bits/stdc++.h>
using namespace std;
int n,m,t,cnt,tot,bcc,k;
bool flag;
int num[505][505];
int lste[505],lsti[505];
char c[505][505];
int se[505][505],si[505][505];
int h[500005],to[1000005],nxt[1000005];
int dfn[500005],low[500005],bel[500005];
stack<int> q;
void jb(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=h[u];
	h[u]=cnt;
}
void haha(){
	for(int i=0;i<n;i++) lste[i]=0;
	for(int i=0;i<m;i++) lsti[i]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(c[i][j]=='.'){
				if(lste[i]!=0) se[i][j]=lste[i];
				if(lsti[j]!=0) si[i][j]=lsti[j];
			}
			if(c[i][j]=='#'){
				lste[i]=0;
				lsti[j]=0;
			}
			if(c[i][j]=='S'){
				if(lste[i]!=0) jb(num[i][j],num[i][j]+k);
				if(lsti[j]!=0) jb(num[i][j]+k,num[i][j]);
				lste[i]=num[i][j];
				lsti[j]=num[i][j];
			}
		}
	}
	for(int i=0;i<n;i++) lste[i]=0;
	for(int i=0;i<m;i++) lsti[i]=0;
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(c[i][j]=='.'){
				if(lste[i]!=0){
					if(se[i][j]!=0) se[i][j]=0;
					else se[i][j]=lste[i];
				}
				if(lsti[j]!=0){
					if(si[i][j]!=0) se[i][j]=0;
					else si[i][j]=lsti[j];
				}
			}
			if(c[i][j]=='#'){
				lste[i]=0;
				lsti[j]=0;
			}
			if(c[i][j]=='S'){
				if(lste[i]!=0) jb(num[i][j],num[i][j]+k);
				if(lsti[j]!=0) jb(num[i][j]+k,num[i][j]);
				lste[i]=num[i][j];
				lsti[j]=num[i][j];
			}
		}
	}
}
void tarjan(int u){
	dfn[u]=low[u]=++tot;
	q.push(u);
	for(int i=h[u];i!=0;i=nxt[i]){
		int v=to[i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!bel[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		++bcc;
		while(!q.empty()){
			int v=q.top();
			q.pop();
			bel[v]=bcc;
			if(u==v) break;
		}
	}
}
int main(){
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		cnt=tot=bcc=k=0;flag=0;
		for(int i=0;i<n;i++){
			scanf("%s",&c[i]);
			for(int j=0;j<m;j++){
				if(c[i][j]=='S') num[i][j]=++k;
				else num[i][j]=0;
			}
		}
		for(int i=1;i<=k*2;i++) h[i]=bel[i]=dfn[i]=low[i]=0;
		haha();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(c[i][j]!='.') continue;
				if(se[i][j]==0){
					if(si[i][j]==0) flag=1;
					else jb(si[i][j],si[i][j]+k);
				}
				else{
					if(si[i][j]==0) jb(se[i][j]+k,se[i][j]);
					else{
						jb(se[i][j]+k,si[i][j]+k);
						jb(si[i][j],se[i][j]);
					}
				}
			}
		}
		if(flag==1){
			printf("No\n");
			continue;
		}
		for(int i=2*k;i>=1;i--) if(!dfn[i]) tarjan(i);
		for(int i=1;i<=k;i++){
			if(bel[i]==bel[i+k]) flag=1;
		}
		if(flag==1){
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(c[i][j]!='S') printf("%c",c[i][j]);
				else{
					if(bel[num[i][j]]<bel[num[i][j]+k]) printf("-");
					else printf("|");
				}
			}
			printf("\n");
		}
	}
}
