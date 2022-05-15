#include<bits/stdc++.h>
#define MAX 10000000
using namespace std;
int p[MAX+5],cnt;
bool pr[MAX+5];
int h[MAX+5],an[MAX+5];
void love(){
	for(int i=2;i<=MAX;i++){
		if(!pr[i]){
			p[++cnt]=i;
			h[i]=1;
			an[i]=1;
		}
		for(int j=1;j<=cnt&&i*p[j]<=MAX;j++){
			pr[i*p[j]]=1;
			if(i%p[j]==0){
				h[i*p[j]]=h[i]+1;
				an[i*p[j]]=max(h[i]+1,an[i]);
				break;
			}
			else{
				h[i*p[j]]=1;
				an[i*p[j]]=an[i];
			}
		}
	}
}
int t,n;
long long ans;
int main(){
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	love();
	scanf("%d",&t);
    for(int i=1;i<=t;i++){
	    ans=0;
		scanf("%d",&n);
		for(int j=1;j*j<=n;j++){
			if(n%j==0){
				ans+=(n/j)*an[j];
				if(j*j!=n)
				    ans+=j*an[n/j];
			}
		}
		printf("%lld\n",ans);
	}
}
