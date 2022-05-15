//2021/12/26

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <cstdio>

#include <climits>//need "INT_MAX","INT_MIN"

#include <cstring>//need "memset"

#include <string>

#define enter() putchar(10)

#define debug(c,que) cerr<<#c<<" = "<<c<<que

#define cek(c) puts(c)

#define blow(arr,st,ed,w) for(register int i=(st);i<=(ed);i++) cout<<arr[i]<<w;

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

const int ma=5005;

int a[ma],b[ma];

int dp[ma][ma];

int n,idx;

inline void output()
{
	string kota="";
	
	int i=1,j=1;
	
	while(i<=n || j<=n)
	{
		if(i==n)
		{
			kota+=a[j]+'0';
			
			i++,j++;
		}
		
		else if(j==n)
		{
			kota+=a[i]+'0';
			
			i++,j++;
		}
		
		else if(dp[i-1][j]>dp[i][j-1] || (dp[i-1][j]==dp[i][j-1] && a[i]>b[j]))
		{
			kota+=a[i]+'0';
			
			i++;
		}
		
		else
		{
			kota+=b[j]+'0';
			
			j++;
		}
	}
	
	cout<<kota<<endl;
}

int main(void)
{
	freopen("lis.in","r",stdin);
	
	freopen("lis.out","w",stdout);
	
	n=read();
	
	for(register int i=1;i<=n;i++)
	{
		a[i]=read();
		
		b[i]=i;
	}
	
	string ans="";
	
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			if(a[i]==b[j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	printf("%d\n",dp[n][n]);
	
	blow(a,1,dp[n][n]," ");
	
	return 0;
}
