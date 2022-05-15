#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],s[200005],f[2][200005],ans=1e16;
int main(){
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
	for(int i=1;i<=n-m+1;i++)f[1][i]=s[i];
	for(int i=2;i<=m;i++){
		for(int j=i;j<=n-m+i;j++)f[i&1][j]=1e16;
		for(int j=i;j<=n-m+i;j++)for(int l=i-1;l<j;l++)f[i&1][j]=min(f[i&1][j],max(f[(i-1)&1][l],s[j]-s[l]));
	}
	for(int i=m;i<=n;i++)ans=min(ans,f[n&1][i]);
	printf("%lld",ans);
	return 0;
}
