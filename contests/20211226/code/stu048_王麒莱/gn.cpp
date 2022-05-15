//2021/12/26

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <cstdio>

#include <climits>//need "INT_MAX","INT_MIN"

#include <cstring>//need "memset"

#define int long long

#define enter() putchar(10)

#define debug(c,que) cerr<<#c<<" = "<<c<<que

#define cek(c) puts(c)

#define blow(arr,st,ed,w) for(register int i=(st);i<=(ed);i++)cout<<arr[i]<<w;

#define speed_up() cin.tie(0),cout.tie(0)

#define endl "\n"

#define Input_Int(n,a) for(register int i=1;i<=n;i++)scanf("%d",a+i);

#define Input_Long(n,a) for(register long long i=1;i<=n;i++)scanf("%lld",a+i);

#define mst(a,k) memset(a,k,sizeof(a))

namespace Newstd
{
	inline int read()
	{
		int x=0,k=1;
		char ch=getchar();
		while(ch<'0' || ch>'9')
		{
			if(ch=='-')
			{
				k=-1;
			}
			ch=getchar();
		}
		while(ch>='0' && ch<='9')
		{
			x=(x<<1)+(x<<3)+ch-'0';
			ch=getchar();
		}
		return x*k;
	}
	inline void write(int x)
	{
		if(x<0)
		{
			putchar('-');
			x=-x;
		}
		if(x>9)
		{
			write(x/10);
		}
		putchar(x%10+'0');
	}
}

using namespace Newstd;

using namespace std;

const int ma=1e7+5;

int p[ma];

bool is[ma];

int T,n;

int idx;

/*
inline void init(int R)
{
	is[1]=true;
	
	for(register int i=2;i<R;i++)
	{
		if(is[i]==false)
		{
			p[++idx]=i;
		}
		
		for(register int j=1;j<=idx && i*p[j]<R;j++)
		{
			is[i*p[j]]=true;
			
			if(i%p[j]==0)
			{
				break;
			}
		}
	}
}
*/

inline int solve(int now)
{
	int maxx=1;
	
	for(register int i=2;i*i<=now;i++)
	{
		if(now%i==0)
		{
			int rrr=0;
			
			while(now%i==0)
			{
				now/=i;
				
				rrr++;
			}
			
			maxx=max(maxx,rrr);
		}
	}
	
	return maxx;
}

#undef int

int main(void)
{
	freopen("gn.in","r",stdin);
	
	freopen("gn.out","w",stdout);
	
	#define int long long
	
	T=read();
		
	while(T--)
	{
		n=read();
		
		int ans=0;
		
		for(register int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				ans+=i*solve(n/i);
				
				if(i*i!=n)
				{
					ans+=n/i*solve(i);
				}
			}
		}
		
		printf("%lld\n",ans+solve(n));
	}
	
	return 0;
}
