#include<bits/stdc++.h>
int n,l,ans,point=2;
struct X
{
	int A,t,v;
}j[100005];
bool cmp(X a,X b)
{
	return a.A<b.A||(a.A==b.A&&a.v>b.v);
}
bool operator < (X a,X b)
{
	return a.v>b.v;
}
std::priority_queue<X> q; 
int main()
{
	freopen("grass.in","r",stdin);
	freopen("grass.out","w",stdout);
	scanf("%d",&n);
	for(int a=1;a<=n;a++)
	{
		scanf("%d%d",&j[a].A,&j[a].t);
		j[a].v=a;
	}
	std::sort(j+1,j+1+n,cmp);
	q.push(j[1]);
	while(!q.empty())
	{
		X p=q.top();
		q.pop();
		if(l!=0) ans=std::max(ans,l-p.A),l+=p.t;
		else l=p.A+p.t;
		while(j[point].A<=l&&point<=n)
		{
			q.push(j[point]);
			point++;
		}
		if(q.empty()&&point<=n)
		{
			l=0;
			q.push(j[point]);
			point++;
		}
	}
	printf("%d",ans);
}
