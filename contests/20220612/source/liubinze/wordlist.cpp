#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<stdio.h>
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,65536,stdin),p1==p2)?EOF:*p1++)
#define max(a,b) ((a)>(b)?(a):(b))
namespace freader
{
	char buf[65539],*p1=buf,*p2=buf;
	inline int read()
	{
	    int x(0);
	    char ch;
	    while((ch=gc)<'0'||ch>'9');
	    do
	       x=(x<<3)+(x<<1)+ch-'0';
	    while((ch=gc)>='0'&&ch<='9');
	    return x;
	}
}
int n,w,a[1000001];
inline bool cheat(int x)
{
	int _max=-1,len=0;
	for(int i=0,j=0;i<n;i++,(j^x-1)?j++:j=0)
	{
		if(!j)
			len+=_max+1,_max=0;
		_max=max(_max,a[i]);
	}
	return len+_max<=w;
}
int main()
{
	freopen("wordlist.in","r",stdin),freopen("wordlist.out","w",stdout);
	n=freader::read(),w=freader::read();
	for(int i=0;i<n;i++)
		a[i]=freader::read();
	int l=1,r=n,mid;
	while(l<=r)
		if(cheat(mid=l+r>>1))
			r=mid-1;
		else
			l=mid+1;
	printf("%d",l);
	return 0;
}
