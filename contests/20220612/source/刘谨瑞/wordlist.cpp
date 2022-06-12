#include<stdio.h>
#include<cstdio>
#include<cctype>
const int SIZE=1<<20;
char buf[SIZE],*p1,*p2;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++)
void read(int &x)
{
	x=0;
	char ch;
	while(!isdigit(ch = gc));
	do
	{
		x=x*10+ch-'0';
	}while(isdigit(ch = gc));
}
int i,j,k;
int n,w;
int a[1000005];
int l,r,mid;
int main()
{
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
//	scanf("%d%d",&n,&w);
	read(n);
	read(w);
	for(i=1;i<=n;i++)
	{
//		scanf("%d",&a[i]);
		read(a[i]);
	}
	l=1;
	r=n;
	while(l<=r)
	{
		mid=l+r>>1;
		k=w;
		j=0;
		for(i=1;i<=n;i++)
		{
			j=j>a[i]?j:a[i];
//			printf("%d:%d %d\n",mid,i,j);
			if(i%mid==0||i==n)
			{
				k-=j+1;
				j=0;
				if(k<-1)
				{
					break;
				}
			}
		}
		if(k>=-1)
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%d\n",l);
	return 0;
}
