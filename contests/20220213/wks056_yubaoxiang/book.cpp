#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1005;

int n,m;
ll f[N][N],a[N],s[N];

int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i&&j<=m;j++)
			for(int k=j-1;k<i;k++)
				f[i][j]=min(f[i][j],max(f[k][j-1],s[i]-s[k]));
	printf("%lld",f[n][m]);
	return 0;
}
