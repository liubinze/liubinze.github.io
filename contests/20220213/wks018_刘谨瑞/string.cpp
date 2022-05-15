#include<bits/stdc++.h>
using namespace std;
const int maxchar=61;
struct Tree{
	int x,cnt[70],sum,lazy[70];
}b[800005];
int n,m,nown;
char s[200005];
char c;
int a[200005];
int L,R,C;
void down(int p)
{
	for(int i=0;i<maxchar;i++)
	{
		if(b[p].lazy[i])
		{
			b[p<<1].lazy[i]=1;
			b[p<<1].sum-=b[p<<1].cnt[i];
			b[p<<1|1].lazy[i]=1;
			b[p<<1|1].sum-=b[p<<1|1].cnt[i];
			b[p].lazy[i]=0;
		}
	}
}
void up(int p)
{
	for(int i=0;i<maxchar;i++)
	{
		b[p].cnt[i]=b[p<<1].cnt[i]*(b[p<<1].lazy[i]^1)+b[p<<1|1].cnt[i]*(b[p<<1|1].lazy[i]^1);
	}
	b[p].sum=b[p<<1].sum+b[p<<1|1].sum;
}
void build(int p,int l,int r)
{
	b[p].sum=r-l+1;
	if(l==r)
	{
		b[p].x=l;
		b[p].cnt[a[l]]=1;
	}
	else
	{
		int mid=l+r>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		for(int i=0;i<maxchar;i++)
		{
			b[p].cnt[i]=b[p<<1].cnt[i]+b[p<<1|1].cnt[i];
		}
	}
}
void Del(int p,int l,int r,int c)
{
	if(l==1&&r==b[p].sum)
	{
		b[p].lazy[c]=1;
		b[p].sum-=b[p].cnt[c];
	}
	else
	{
		down(p);
		int mid=b[p<<1].sum;
		if(l<=mid&&r<=mid)
		{
			Del(p<<1,l,r,c);
		}
		else if(l>mid&&r>mid)
		{
			Del(p<<1|1,l-mid,r-mid,c);
		}
		else
		{
			Del(p<<1,l,mid,c);
			Del(p<<1|1,1,r-mid,c);
		}
		up(p);
	}
}
void print(int p)
{
	if(b[p].x!=0)
	{
		if(b[p].sum>0)
		{
			printf("%c",s[b[p].x-1]);
		}
	}
	else
	{
		down(p);
		print(p<<1);
		print(p<<1|1);
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d\n",&n,&m);
	nown=n;
	scanf("%s",&s);
	for(int i=1;i<=n;i++)
	{
		c=s[i-1];
		if(c>='a'&&c<='z')
		{
			a[i]=c-'a';
		}
		else if(c>='A'&&c<='Z')
		{
			a[i]=c-'A'+26;
		}
		else
		{
			a[i]=c-'0'+52;
		}
	}
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%s",&L,&R,&c);
		if(c>='a'&&c<='z')
		{
			C=c-'a';
		}
		else if(c>='A'&&c<='Z')
		{
			C=c-'A'+26;
		}
		else
		{
			C=c-'0'+52;
		}
		if(L>nown)
		{
			continue;
		}
		else
		{
			R=min(R,nown);
			Del(1,L,R,C);
			nown=b[1].sum;
		}
	}
	print(1);
	return 0;
}
