#include<bits/stdc++.h>
using namespace std;
int ey[1500001],elast[1500001],enext[1500001],val[1500001],k,dis[1500001],n,m,cen[100001],low,hi,c;
void add(int a,int b,int c)
{
//	cout<<a<<" "<<b<<" "<<c<<endl;
	ey[++k]=b;
	val[k]=c;
	enext[k]=elast[a];
	elast[a]=k;
}
struct node{
	int num,zhi;
}; 
priority_queue<node> q;
bool operator < (node a,node b)
{
	return a.zhi>b.zhi;
}
void distral()
{
	node a;
	a.num=1,a.zhi=0;
	dis[a.num]=0;
	q.push(a);
	while(!q.empty())
	{
		node p=q.top();
	//	cout<<p.zhi<<endl;
		q.pop();
		if(dis[p.num]<p.zhi)
		continue;
		for(int i=elast[p.num];i;i=enext[i])
		{
			
			int o=ey[i],k=val[i];
	//		cout<<p.num<<" "<<o<<" "<<k<<endl;
			if(dis[o]>dis[p.num]+k)
			{
				dis[o]=dis[p.num]+k;
				node ew;
				ew.num=o,ew.zhi=dis[o];
				q.push(ew);
			} 
		}
	}
}
int main(){
	freopen("shortest.in","r",stdin);
	freopen("shortest.out","w",stdout);
	cin>>n>>m>>c;
	low=1e9,hi=0;
	for(int i=1;i<=n;i++)
	{
	int a;
	scanf("%d",&cen[i]);
	low=min(low,cen[i]);
	hi=max(hi,cen[i]);
	} 
	for(int i=1;i<=n;i++)
	{
	int a=cen[i];
	if(a!=hi)
	{
	add(a+hi+1,i,0);
	add(i,a+hi+1,c);		
	}
	if(a!=low)
	{
	add(a+hi-1,i,0);
	add(i,a+hi-1,c);		
	}		
	}
	for(int i=1;i<=m;i++)
	{
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		add(a,b,w);
		add(b,a,w);
	} 
	for(int i=1;i<=n;i++)
	dis[i]=1e9;
/*	for(int p=1;p<=n+4;p++)
	for(int i=elast[p];i;i=enext[i])
	{
			
			int o=ey[i],k=val[i];
			cout<<p<<" "<<o<<" "<<k<<endl;
	}
*/	distral();
	if(dis[n]!=1e9)
	cout<<dis[n];
	else
	cout<<-1;
}
