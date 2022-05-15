#include<bits/stdc++.h>
using namespace std;
int a[5005],f[5005][5005],n,ans;
main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);	
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i),f[n][i]=1;
    for(int i=n;i;--i){
    	for(int j=1;j<=n;++j){
    		if(a[i]==j){
    			for(int k=j+1;k<=n;++k)
					f[i][j]=max(f[i][j],f[i+1][k]+1);
			}
			else f[i][j]=f[i+1][j];
			ans=max(ans,f[i][j]);
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n&&ans;++i){
		for(int j=n;j;--j){
			if(f[i][j]==ans&&f[i+1][j]-ans){
				printf("%d ",j);
				--ans;
				break;
			}
		}
	}
}
