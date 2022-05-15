#include<bits/stdc++.h>
using namespace std;
int n,n1,m,c,a[100005],s[100005],ans;
bool fl[100005];
struct node{int s,id;}b[100005];
bool cmp(node x,node y){return x.s<y.s;}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&m,&c),a[0]=-1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)b[i].s=a[i+1]-a[i],b[i].id=i,s[i]=b[i].s;
	sort(b+1,b+n,cmp);
	for(int i=1,j=0;j<n-m;i++){
		int sum=0;
		if(fl[b[i].id-1]&&b[i].id>1)for(int j=b[i].id-1;fl[j]&&j>=1;j--)sum++;
		if(fl[b[i].id+1]&&b[i].id<n-1)for(int j=b[i].id+1;fl[j]&&j<n;j++)sum++;
		if(sum<c)fl[b[i].id]=1,j++;
	}
	for(int i=1,sum=0;i<n;i++)if(fl[i]){
		if(fl[i-1])sum+=s[i],ans=max(ans,sum);
		else sum=s[i],ans=max(ans,sum);
	}
	printf("%d",ans);
	return 0;
}
