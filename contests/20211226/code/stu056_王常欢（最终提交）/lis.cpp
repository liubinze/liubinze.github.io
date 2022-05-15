#include <iostream>
#include <cstdio>
using namespace std;
const int N=5010;
int n,m,a[N],tem[N],f[N];
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		int x=lower_bound(tem+1,tem+1+m,a[i])-tem;
		m=max(x,m);
		tem[x]=a[i];
		f[i]=m;
	}
	tem[m+1]=2e9;
	int x=n;
	for(int i=m;i>=1;i--){
		for(int j=1;j<=x;j++){
			if(f[j]==i&&a[j]>tem[i]&&a[j]<tem[i+1]){
				tem[i]=a[j];
				x=i;
			}
		}
	}printf("%d\n",m);
	for(int i=1;i<=m;i++)printf("%d ",tem[i]);
	return 0;
}
