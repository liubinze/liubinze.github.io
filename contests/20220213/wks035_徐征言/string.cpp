#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,tot;
char s[200002],C;
struct X
{
	int l,r,cnt[63];
	bool lazy[63];
}j[650002];
int turn(char s)
{
	if(s>='a'&&s<='z') return 1+s-'a';
	if(s>='A'&&s<='Z') return 27+s-'A';
	return 53+s-'0';
}
void maketree(int p,int l,int r)
{
	j[p].l=l;
	j[p].r=r;
	if(l==r)
	{
		j[p].cnt[turn(s[l])]++;
		j[p].cnt[0]=1;
		return;
	}
	int mid=(l+r)/2;
	tot++;
	maketree(p*2,l,mid);
	tot++;
	maketree(p*2+1,mid+1,r);
	for(int a=0;a<=62;a++) j[p].cnt[a]=j[p*2].cnt[a]+j[p*2+1].cnt[a];
}
void spread(int p)
{
	for(int a=1;a<=62;a++)
	{
		if(j[p].lazy[a]==1)
		{
			j[p*2].cnt[0]-=j[p*2].cnt[a];
			j[p*2].cnt[a]=0;
			j[p*2].lazy[a]=1;
			j[p*2+1].cnt[0]-=j[p*2+1].cnt[a];
			j[p*2+1].cnt[a]=0;
			j[p*2+1].lazy[a]=1;
			j[p].lazy[a]=0;
		}
	}
}
void change(int p,int l,int r,int x)
{
	if(l<=j[p].l&&r>=j[p].r)
	{
		j[p].cnt[0]-=j[p].cnt[x];
		j[p].cnt[x]=0;
		j[p].lazy[x]=1;
		return;
	}
	spread(p);
	int mid=(j[p].l+j[p].r)/2;
	if(l<=mid) change(p*2,l,r,x);
	if(r>mid) change(p*2+1,l,r,x);
	for(int a=0;a<=62;a++) j[p].cnt[a]=j[p*2].cnt[a]+j[p*2+1].cnt[a];
}
int pos(int p,int x)
{
	if(j[p].l==j[p].r) return j[p].l;
	spread(p);
	if(x<=j[p*2].cnt[0]) return pos(p*2,x);
	else return pos(p*2+1,x-j[p*2].cnt[0]);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	maketree(1,1,n);
	while(m--)
	{
		scanf("%d%d %c",&l,&r,&C);
		if(l>j[1].cnt[0]) continue;
		r=min(r,j[1].cnt[0]);		
		change(1,pos(1,l),pos(1,r),turn(C));
	}
	for(int a=1;a<=j[1].cnt[0];a++) printf("%c",s[pos(1,a)]);
}
