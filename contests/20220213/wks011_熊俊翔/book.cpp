#include<bits/stdc++.h>
using namespace std;
int f[1005][1005],n,m,x,ans=0x3f3f3f3f;
int main(){
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&x),ans=max(ans,x);
	printf("%d",ans);
	return 0;
}
