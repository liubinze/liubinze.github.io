#include<bits/stdc++.h>
using namespace std;
int n;
int arr[5005],dp[5005],cs[5005];
int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
	for(int i=n;i>=1;i--){
		int maxx=0;
		dp[i]=1;
		for(int j=i+1;j<=n;j++){
			if(arr[i]<arr[j])dp[i]=max(dp[i],dp[j]+1);
		}
		int cho=0;
		for(int j=i+1;j<=n;j++){
			if(arr[i]<arr[j]&&dp[j]==dp[i]-1){
				if(cho==0)cho=j;
				else{
					if(arr[j]>arr[cho]){
						cho=j;
					}
				}
			}
		}
		cs[i]=cho;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
	printf("%d\n",ans);
	int ansi=0;
	for(int i=1;i<=n;i++){
		if(dp[i]==ans){
			if(ansi==0)ansi=i;
			else{
				if(arr[i]>arr[ansi]){
					ansi=i;
				}
			}
		}
	}
	printf("%d ",arr[ansi]);
	while(dp[ansi]!=1){
		ansi=cs[ansi];
		printf("%d ",arr[ansi]);
	}
	return 0;
}
