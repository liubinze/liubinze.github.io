#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int>q;
struct node{
	int st,len,p;
}arr[100005],brr[100005];
bool cmp(node x,node y){
	if(x.st==y.st)return x.p<y.p;
	return x.st<y.st;
}
int ans[100005];
int n;
signed main(){
	freopen("grass.in","r",stdin);
	freopen("grass.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&arr[i].st,&arr[i].len);
		arr[i].p=i;
		brr[i]=arr[i];
	}
	sort(arr+1,arr+1+n,cmp);
	ans[arr[1].p]=0;
	int beg=2;
	for(;beg<=n;beg++){
		if(arr[beg].st>arr[1].len+arr[1].st)break;
		q.push(-arr[beg].p);
	}
	int now=arr[1].len+arr[1].st;
	while(!q.empty()){
		int tp=-q.top();
		q.pop();
		ans[tp]=now-brr[tp].st;
		for(;beg<=n;beg++){
			if(arr[beg].st>brr[tp].len+brr[tp].st)break;
			q.push(-arr[beg].p);
		}
		if(q.size()==0&&beg<n){
			q.push(-arr[beg].p);
			now=arr[beg].st;
			beg++;
		}
		else now=brr[tp].len+now; 
//		cout<<now<<" "<<brr[tp].len<<endl;
	}
	int ansx=0;
	for(int i=1;i<=n;i++)ansx=max(ansx,ans[i]);
	printf("%lld",ansx);
	return 0;
}//long long
