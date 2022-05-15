#include<bits/stdc++.h>
using namespace std;
long long l,r,t,a,b,sum;
long long cnt[12];
int dfs(long long x){
    if(x<10) return x;
    int ans=0;
    while(x){
        ans+=x%10;
        x/=10;
    }
    return dfs(ans);
}
int main(){
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
    for(int i=1;i<=10;i++){
        cnt[i]=cnt[i-1]+i;
        //printf("%d",cnt[i]);
    }
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&l,&r);
        a=dfs(l),b=dfs(r);
        //cout<<a<<" "<<b<<" "<<cnt[a]<<" "<<cnt[]<<endl;
        sum=r-l+1;
        if(a>b){
			//cout<<r-l+1-10+a-b<<endl;
            printf("%lld\n",(r-l+1-(10-a+b))/9*45+cnt[9]-cnt[a-1]+cnt[b]);
        }
        else{
        	//cout<<r-l+1-a+b<<endl;
            printf("%lld\n",(r-l+1-b+a)/9*45+cnt[b]-cnt[a-1]);
        }
    }
    return 0;
}
