#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector <ll> G[100];
ll F[1000003];
int f(int x){
	int ans=0;
	while(x)ans+=x%10,x/=10;
	return ans;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
    for(int i=1;i<=1000000;i++)F[i]=f(i),G[F[i]].push_back(i);
    int Q;
    ll A,B,C,D;
    int n;
    cin>>Q;
    while(Q--){
    	scanf("%lld%lld%lld%lld%d",&A,&B,&C,&D,&n);
    	ll minn=1e18;
    	for(ll i=1;i<=100;i++){
    		int now=(upper_bound(G[i].begin(),G[i].end(),n)-G[i].begin());
    		if(G[i].size()==0||G[i][0]>n)continue;
    		--now;
    		ll a=(A*i+B),b=(C*i*i+D*i);
    		ll now1=b/(-2ll*a);
    		if(a>0){
    			if(G[i][now]<=now1)minn=min(minn,G[i][now]*1ll*G[i][now]*a+G[i][now]*b);
    			else{
    				if(G[i][0]>now1)minn=min(minn,G[i][0]*1ll*G[i][0]*a+G[i][0]*b);
    				else{
    					int now2=(upper_bound(G[i].begin(),G[i].end(),now1)-G[i].begin());
    					minn=min(minn,G[i][now2-1]*G[i][now2-1]*a+G[i][now2-1]*b);
    					minn=min(minn,G[i][now2]*G[i][now2]*a+G[i][now2]*b);
					}
				}
			}else if(a==0){
				if(b>0){
					minn=min(minn,G[i][0]*1ll*b);
				}else if(b==0){
					minn=min(minn,0ll);
				}else minn=min(minn,G[i][now]*1ll*b);
			}else{
				minn=min(minn,G[i][0]*G[i][0]*a+G[i][0]*b);
				minn=min(minn,G[i][now]*G[i][now]*a+G[i][now]*b);
			}
		}
		printf("%lld\n",minn);
	}
	return 0;
}
