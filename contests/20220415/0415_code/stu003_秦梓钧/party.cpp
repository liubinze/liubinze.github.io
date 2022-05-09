#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
	int p,cnt;
}a[1000005];
bool cmp(node x,node y){
	return x.p<y.p;
}
int mid,sum;
int get_num(int id){
	int now=1;
	while(now<=n+1){
		if(id<=0)return a[now-1].p;
		id-=a[now].cnt;
		now++;
	}
}
int get_ans(int p){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i].cnt*abs(a[i].p-p);
	}
	return ans;
}
signed main(){
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].p,&a[i].cnt);
		sum+=a[i].cnt;
	}
	sort(a+1,a+1+n,cmp);
	mid=sum/2ll;
	printf("%lld",min(get_ans(get_num(mid)),get_ans(get_num(mid+1))));
	return 0;
}
