#include<bits/stdc++.h>
using namespace std;
const int SIZE = 1 << 20; 
char buf[SIZE], *p1, *p2; 
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++) 
void read(int &x) { 
    x = 0; 
    char ch; 
    while(!isdigit(ch = gc)); 
    do { 
       x = x*10 + ch - '0'; 
    }while(isdigit(ch = gc)); 
}
struct edge{int v,nxt;}e[1800005],e1[1800005];
struct node{int x,y;}a[300005];
int elast[300005],elast1[300005],num[300005],op[300005],lm;
int n,m,A,B,tot=1,tot1=1;
int x,y,t,d,cnt;
int dfn[300005],low[300005],ins[300005],belong[300005];
int rd[300005];
bitset<10005> num1[30005];
vector<node> r;
stack<int> p;
queue<int> q;
void add(int u,int v) {
	e[tot].v=v;
	e[tot].nxt=elast[u];
	elast[u]=tot++; 
}
void add1(int u,int v) {
	e1[tot1].v=v;
	e1[tot1].nxt=elast1[u];
	elast1[u]=tot1++; 
}
void TJ(int u) {
	dfn[u]=low[u]=++d;
	p.push(u);
	ins[u]=1;
	for(int i=elast[u];i;i=e[i].nxt) {
		int v=e[i].v;
		if(!dfn[v]) {
			TJ(v);
			low[u]=min(low[u],low[v]);
		} else if(ins[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]) {
		int tp;
		++cnt;
		do{
			tp=p.top();
			p.pop();
			belong[tp]=cnt;
			ins[tp]=0;
			if(num[tp]) num1[cnt][op[tp]]=1;
		}while(!p.empty()&&tp!=u);
	}
}

bool cmp(node x,node y) {return x.y>y.y;}
int kk[300005],hl;
int main() {
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	read(n);read(m);read(A);read(B);
//	cin>>n>>m>>A>>B;
	for(int i=1;i<=n;i++) {
		read(a[i].x),read(a[i].y);
//		cin>>a[i].x>>a[i].y;
		if(a[i].x==0) r.push_back(node{i,a[i].y});
		else if(a[i].x==A) num[i]=1,op[i]=++lm;
	}
	for(int i=1;i<=m;i++) {
		read(x),read(y),read(t);
//		cin>>x>>y>>t;
		if(t==1) add(x,y);
		else add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) TJ(i);
	for(int i=1;i<=n;i++)
		for(int j=elast[i];j;j=e[j].nxt)
			if(belong[i]!=belong[e[j].v]) add1(belong[e[j].v],belong[i]),rd[belong[i]]++;
	for(int i=1;i<=cnt;i++)
		if(rd[i]==0) q.push(i);
	while(!q.empty()) {
		int tp=q.front();q.pop();
		for(int i=elast1[tp];i;i=e1[i].nxt) {
			int v=e1[i].v;
			rd[v]--;
			if(kk[v]!=tp) {
				num1[v]|=num1[tp];
				kk[v]=tp;
			}
			if(rd[v]==0) q.push(v);
		}
	}
	sort(r.begin(),r.end(),cmp);
	for(int i=0;i<r.size();i++)
		printf("%d\n",num1[belong[r[i].x]].count());
}
