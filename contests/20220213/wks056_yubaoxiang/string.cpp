#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int n,m;
char s[N];
struct SegmentTree
{
	struct Tree
	{
		int l,r,lazy,cnt;
	}t[4*N];
	
	void build(int p,int l,int r)
	{
		t[p].l=l,t[p].r=r,t[p].lazy=-1;
		if(l==r)return;
		int mid=l+r>>1;
		build(p*2,l,mid),build(p*2+1,mid+1,r);
	}
	
	void pushdown(int p)
	{
		if(t[p].lazy==-1)return;
		t[p*2].lazy=t[p*2+1].lazy=0;
		t[p*2].cnt=t[p*2+1].cnt=0;
		t[p].lazy=-1;
	}
	
	void update(int p,int l,int r,int d)
	{
		if(l<=t[p].l&&t[p].r<=r)
		{
			t[p].lazy=d,t[p].cnt=d;
			return;
		}
		pushdown(p);
		int mid=t[p].l+t[p].r>>1;
		if(l<=mid)update(p*2,l,r,d);
		if(r>mid)update(p*2+1,l,r,d);
		t[p].cnt=t[p*2].cnt+t[p*2+1].cnt;
	}
	
	int ask(int p,int x)
	{
		if(t[p].l==t[p].r)return t[p].cnt;
		pushdown(p);
		int mid=t[p].l+t[p].r>>1;
		if(x<=mid)return ask(p*2,x);
		else return ask(p*2+1,x);
	}
	
}seg[105];

int query(int p,int x)
{
	if(seg[0].t[p].l==seg[0].t[p].r)return seg[0].t[p].l;
	for(int i=0;i<=100;i++)
	{
		seg[i].pushdown(p);
	}
	int lcnt=0;
	for(int i=0;i<=100;i++)
	{
		lcnt+=seg[i].t[p*2].cnt;
	}
	if(x<=lcnt)return query(p*2,x);
	else query(p*2+1,x-lcnt);
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=0;i<=100;i++)
	{
		seg[i].build(1,1,n);
	}
	for(int i=1;i<=n;i++)
	{
		int id=s[i]-'1';
		seg[id].update(1,i,i,1);
	}
	while(m--)
	{
		int l,r;
		char c[3];
		scanf("%d%d%s",&l,&r,c);
		l=query(1,l),r=query(1,r);
		seg[c[0]-'1'].update(1,l,r,0);
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=100;j++)
			if(seg[j].ask(1,i))
			{
				putchar('1'+j);
				break;
			}
	return 0;
}
