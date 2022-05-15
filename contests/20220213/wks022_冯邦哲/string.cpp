#include<bits/stdc++.h>
using namespace std;
char a[200005],b[200005];
int n,m;
struct two
{
	int l,r;
	int cnt;
	string sum;
}tree[200005];
void pushup(int p)
{
	tree[p].cnt=tree[p<<1].cnt+tree[p<<1|1].cnt;
	tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
}
void pushdown(int p)
{
	tree[p<<1].cnt=tree[p].cnt-tree[p<<1|1].cnt;
	tree[p<<1|1].cnt=tree[p].cnt-tree[p<<1].cnt;
}
void build(int p,int x,int y)
{
	tree[p].l=x;
	tree[p].r=y;
	if(x==y)
	{
		tree[p].sum+=a[x];
		tree[p].cnt=1;
		return ;
	}
	int mid=(x+y)>>1;
	build(p<<1,x,mid);
	build(p<<1|1,mid+1,y);
	pushup(p);
}
void del(int p,int x,int y,string op)
{
	if(tree[p].l==tree[p].r)
	{
		if(tree[p].sum[0]==op[1])cout<<tree[p].sum<<endl,tree[p].sum.clear(),tree[p].cnt--;
		return ;
	}
	int mid=(tree[p].l+tree[p].r)>>1;
	pushdown(p);
	if(x<=mid)del(p<<1,x,mid,op);
	if(y>mid)del(p<<1|1,mid+1,y,op);
	pushup(p);
}
string query(int p,int x,int y)
{
	if(x==y)
	{
		return tree[p].sum;
	}
	string ans;
	ans.clear();
	int mid=(x+y)>>1;
	if(x<=mid)ans+=query(p<<1,x,mid);
	if(y>mid)ans+=query(p<<1|1,mid+1,y);
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>a+1;
	build(1,1,n);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		cin>>b+1;
		if(x>n)continue;
		if(y>n)y=n;
		del(1,x,y,b);
	}
	cout<<query(1,1,tree[n].cnt);
	return 0;
}
