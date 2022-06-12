#include<iostream>
using namespace std;
int n,w;
int a[1000005];
struct node{
	int l,r,sum;
}t[4000005];
void ud(int p)
{
	t[p].sum=max(t[2*p].sum,t[2*p+1].sum);
}
void build(int p,int l,int r)
{
	t[p].l=l;
	t[p].r=r;
	if(l==r)
	{
		t[p].sum=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	ud(p);
	return ;
}
int q(int p,int l,int r)
{
	if(l<=t[p].l&&t[p].r<=r)
		return t[p].sum;
	int mid=(t[p].l+t[p].r)/2;
	int res=0;
	if(l<=mid)res=max(res,q(2*p,l,r));
	if(mid<r)res=max(res,q(2*p+1,l,r));
	return res;
}
int main()
{
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int sum=0,flag=0;
		for(int j=1;j<=n;j+=i)
		{
			if(j+i-1<n)
				sum+=q(1,j,j+i-1)+1;
			else
				sum+=q(1,j,n);
			if(sum>w)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("%d",i);
			return 0;
		}
	}
}

