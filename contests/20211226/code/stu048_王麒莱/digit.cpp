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

int T,l,r;

inline int calc(int x)
{
	if(x%9==0)
	{
		return 9;
	}
	
	return x%9;
}

#undef int

int main(void)
{
	freopen("digit.in","r",stdin);
	
	freopen("digit.out","w",stdout);
	
	#define int long long
	
	T=read();
	
	while(T--)
	{
		l=read(),r=read();
		
		int ans(0);
		
		if(r-l+1>=9)
		{
			int Le=l,Ri=r;
			
			for(register int i=l;;i++)
			{
				if(calc(i)==1)
				{
					Le=i;
					
					break;
				}
				
				ans+=calc(i);
			}
			
			for(register int i=r;;i--)
			{
				if(calc(i)==9)
				{
					Ri=i;
					
					break;
				}
				
				ans+=calc(i);
			}
			
			ans+=(Ri-Le+1)/9*45;
		}
		
		else
		{
			for(register int i=l;i<=r;i++)
			{
				ans+=calc(i);
			}
		}
		
		printf("%lld\n",ans);
	}
	
	return 0;
}
