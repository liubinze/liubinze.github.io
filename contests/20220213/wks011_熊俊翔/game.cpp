#include<bits/stdc++.h>
using namespace std;
long long T,n,k,k1,x,k2,t,y,f,z;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld",&T);
	for(int i=1;i<=T;++i){
		scanf("%lld%lld",&n,&k);
		if(k==0)printf("YES\n0\n");
		else if(k%2==0)printf("NO\n");
		else{
			t=ceil(log2(k));
			if(k==(1ll<<t)-1){
				printf("%lld\n",t);
				for(int i=1;t--;i+=i&-i)printf("%lld ",i);
			}
			else{
				k1=k-1;
				for(int i=1;i<=28;++i){
					x=1ll<<i;
					k2=k1+x;
					t=ceil(log2(k2));
					if(k2==(1ll<<t)){
						y=i-1;
						if((1ll<<y)+k-1<=n)f=1;
						break;
					}
				}
				if(f==0)printf("NO\n");
				else{
					z=y;
					for(int i=1;z--;i+=i&-i)printf("%lld ",k+i);
					for(int i=1,j=y;j<=t-1;i+=(1ll<<j),++j)printf("%lld ",i);
					f=0;
				}
			}
		}
	}
	return 0;
}
