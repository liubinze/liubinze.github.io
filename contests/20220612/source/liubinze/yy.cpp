#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<stdio.h>
#include<time.h>
#include<algorithm>
#include<random>
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,65536,stdin),p1==p2)?EOF:*p1++)
#define min(a,b) ((a)<(b)?(a):(b))
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
int md[101],fac[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800},pu[101],pv[101];
int main()
{
	freopen("yy.in","r",stdin),freopen("yy.out","w",stdout);
	int t=freader::read(),n,m,x,y,ans;
	std::mt19937 e(time(0));
	while(t--)
	{
		n=freader::read(),m=freader::read();
		if(m==0)
		{
			puts("0");
			continue;
		}
		if(m==n*n)
		{
			printf("%d\n",2*n);
			continue;
		}
		for(int i=0;i<n;i++)
			md[i]=0;
		while(m--)
			x=freader::read(),y=freader::read(),md[x-1]|=1<<y-1;
		std::iota(pu,pu+n,0),ans=1e9;
		for(int i=0;i<301;i++)
		{
			std::iota(pv,pv+n,0);
			for(int j=0;j<301;j++)
			{
				pv[n]=pv[x=0];
				for(int k=0;k<n;k++)
					if((md[pu[k]]&1<<pv[k])||(md[pu[k]]&1<<pv[k+1]))
						x++;
				ans=min(ans,x),std::shuffle(pv,pv+n,e);
			}
			std::shuffle(pu,pu+n,e);
		}
		printf("%d\n",ans?ans-int(fac[n]>400):ans);
	}
	return 0;
}
