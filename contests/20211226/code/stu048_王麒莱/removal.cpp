//2021/12/26

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <cstdio>

#include <climits>//need "INT_MAX","INT_MIN"

#include <cstring>//need "memset"

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

const int ma=100005;

int a[ma];

bool vis[ma];

int n,m,k;

int main(void)
{
	freopen("removal.in","r",stdin);
		
	freopen("removal.out","w",stdout);
	
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		mst(a,0);mst(vis,false);
		
		Input_Int(n,a);
		
		for(register int i=1;i<n;i++)
		{
			if(m==0)
			{
				break;
			}
			
			if(a[i]>=a[i+1])
			{
				vis[i]=true;
				
				m--;
			}
		}
		
		for(register int i=1;i<=n;i++)
		{
			if(vis[i]==false)
			{
				printf("%d ",a[i]);
			}
		}
		
		puts("");
	}
	
	return 0;
}
