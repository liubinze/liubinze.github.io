#include<iostream>
#include<cstring>
using namespace std;
int n,m;
string s;
struct node{
	int l,r,sum,lazy,cnt;
}t[130][800005];
void pu(int k,int p)
{
	t[k][p].sum=t[k][2*p].sum+t[k][2*p+1].sum;
}
void pd(int k,int p)
{
	if(t[k][p].l!=t[k][p].r)
	{
		t[k][2*p].lazy+=t[k][p].lazy;
		t[k][2*p].sum=0;
		t[k][2*p+1].lazy+=t[k][p].lazy;
		t[k][2*p+1].sum=0;
	}
	t[k][p].lazy=0;
}
void build(int k,int p,int x,int y)
{
	t[k][p].l=x;
	t[k][p].r=y;
	if(x==y)
	{
		return ;
	}
	int mid=(x+y)/2;
	build(k,2*p,x,mid);
	build(k,2*p+1,mid+1,y);
}
void up(int k,int p,int x)
{
	if(t[k][p].l==x&&t[k][p].r==x)
	{
		t[k][p].sum=1;
		return ;
	}
	int mid=(t[k][p].l+t[k][p].r)/2;
	if(x<=mid)
		up(k,2*p,x);
	else
		up(k,2*p+1,x);
	pu(k,p);
}
void ud(int k,int p,int x,int y)
{
	if(t[k][p].l>=x&&t[k][p].r<=y)
	{
		t[k][p].sum=0;
		t[k][p].lazy+=1;
		pd(k,p);
		return ;
	}
	pd(k,p);
	int mid=(t[k][p].l+t[k][p].r)/2;
	if(x<=mid)
		ud(k,2*p,x,y);
	if(y>mid)
		ud(k,2*p+1,x,y);
	pu(k,p);
}
int q(int k,int p,int x)
{
	if(t[k][p].l==x&&t[k][p].r==x)
	{
		return t[k][p].sum;
	}
	int mid=(t[k][p].l+t[k][p].r)/2,res=0;
	if(x<=mid)
		res=q(k,2*p,x);
	else
		res=q(k,2*p+1,x);
	return res;
}
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=128;i++)
		build(i,1,1,n);
	for(int i=1;i<=n;i++)
		up(int(s[i-1]),1,i);
	for(int i=1;i<=m;i++)
	{
		char c;
		int x,y;
		scanf("%d%d %c",&x,&y,&c);
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=128;j++)
		{
			if(q(j,1,i))printf("%c",char(j));
		}
	}
}

