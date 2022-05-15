#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int arr[100005];
struct node{
	int id,val;
};
node brr[100005];
bool cmp(node x,node y){
	if(x.val==y.val)return x.id<y.id;
	return x.val>y.val;
}
int main(){
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	while(cin>>n>>m>>k){
		for(int i=1;i<=n;i++)scanf("%d",&arr[i]),brr[i].val=arr[i],brr[i].id=i;
		sort(brr+1,brr+1+n,cmp);
		for(int i=1;i<=m;i++){
			arr[brr[i].id]=0;
		}
		for(int i=1;i<=n;i++){
			if(arr[i]!=0)printf("%d ",arr[i]);
		}
		puts("");
	}
	return 0;
}

