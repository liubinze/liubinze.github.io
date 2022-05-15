#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int arr[100005];
bool ck(int p){
	int cnt=0;
	for(int i=n;i>=1;){
		int j=i,minget=max(i-k+1,1);
		while(j>=minget){
			if(arr[j]<arr[i]-p){
				j++;
				break;
			}
			if(j==minget)break;
			j--;
		}
		i=j-1;
		cnt++;
	}
	if(cnt<=m)return 1;
	return 0;
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
	sort(arr+1,arr+1+n);
	int l=0,r=1e9,mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(ck(mid)){
			r=mid-1,ans=mid;
		}
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}
