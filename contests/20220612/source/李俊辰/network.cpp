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
        x = x*10 + ch -  '0';  
     }while(isdigit(ch = gc));  
  } 
int n,m,A,B,ey[100001],elast[100001],enext[100001],k,ans[100001];
bool zuo[100001],you[100001];
void add(int a,int b)
{
	k++;
	ey[k]=b;
	enext[k]=elast[a];
	elast[a]=k;
}
bool vis[100001];
int dfs(int u)
{
	vis[u]=true;
	int x=0;
	if(you[u]==true)
	x++;
	for(int i=elast[u];i;i=enext[i])
	{
		int v=ey[i];
		if(vis[v]==true)
		continue;
		x+=dfs(v);
	}
	return x;
}
struct we{
	int y,id;
}ae[100001];
int ee=0;
bool cmp(we a,we b)
{
	return a.y>b.y;
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);	
	cin>>n>>m>>A>>B;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		read(x),read(y);
		if(x<0||x>A||y<0||y>B)
		continue;
		if(x==0)
		{
		zuo[i]=true;		
		ee++;
		ae[ee].id=i;
		ae[ee].y=y;	
		}
		if(x==A)
		{
		you[i]=true;
		ans[i]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int op,a,b;
		read(a),read(b),read(op);
		if(op==1)
		{
		add(a,b);	
		if(you[b]==true)
		ans[a]++;
		}
		else
		{
			add(a,b);
			add(b,a);
		}
	}
	sort(ae+1,ae+1+ee,cmp);
	for(int i=1;i<=ee;i++)
	{
		memset(vis,0,sizeof vis);
		printf("%d\n",dfs(ae[i].id));
	}
}
