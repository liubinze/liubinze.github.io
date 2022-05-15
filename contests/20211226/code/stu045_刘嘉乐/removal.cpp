#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,a[100005],b[15];
int main(){
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	while(cin>>n>>m>>k){
		c=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n&&c<m;i++)for(int j=i;j>=1&&a[j]>a[i+1]&&c<m;j--)if(a[j]!=10000)b[++c]=j,a[j]=10000;
		for(int i=1;i<=n;i++)if(a[i]!=10000)printf("%d ",a[i]);
		printf("\n");                       
	}
	return 0;
}
