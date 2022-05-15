#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5005],dp[5005][5005],b[5005];
int main(){
	//freopen("lis2.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]<a[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
		}
	}
	printf("%d",dp[n][n]);
	return 0;
}
