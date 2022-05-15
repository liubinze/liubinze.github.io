#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,p[10005],a[10005],b[10005];
bool pl[10005];
int dfs(int x,int s){
	if(x>k){
		int sum=0;
		for(int i=1;i<=k;i++)sum=max(sum,b[i]);
		return sum*s;
	}
	int l=b[x],ans=dfs(x+1,s);
	for(int i=1;i<=l;i++)b[x]--,s*=a[x],ans+=dfs(x+1,s);
	b[x]=l;
	return ans;
}
int main(){
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	for(int i=2;i<=10000;i++){
		if(!pl[i])p[++m]=i;
		for(int j=1;j<=m&&i*p[j]<=10000;j++){
			pl[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n),k=0;
		for(int i=1;i<=m&&p[i]*p[i]<=n;i++)if(n%p[i]==0){
			a[++k]=p[i],b[k]=0;
			while(n%p[i]==0)n/=p[i],b[k]++;
		}
		if(n>1)a[++k]=n,b[k]=1;
		printf("%d\n",dfs(1,1));
	}
	return 0;
}
