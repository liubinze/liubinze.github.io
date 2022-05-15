#include<bits/stdc++.h>
using namespace std;
long long n;
int k,t;
bool bn[65],bnx[65],bnxx[65];
long long cz(long long n){
	long long ans=0;
	int q=0;
	int x;
	for(int i=k;i>=1;i--){
		if(n%2==1) bn[i]=1;
		else bn[i]=0;
		bnx[i]=bn[i];
		if(bn[i]==1&&q==0){
			x=i;
			q=1;
			//cout<<x<<" ";
		}
		n/=2;
		//cout<<bn[i];
	}
	//cout<<endl<<x;
	//cout<<endl;
	for(int i=x;i>=1;i--){
		if(bnx[i]==1) bnx[i]=0;
		else{
			bnx[i]=1;
			break;
		}
	}
	for(int i=k;i>=1;i--){
		//cout<<bnx[i];
		if(bn[i]==bnx[i]){
			bnxx[i]=0;
		}
		else bnxx[i]=1;
	}
	for(int i=x-2,j=k;i>=1;i--,j--){
		if(bnx[j]==1&&bnxx[i]==1){
			bnx[j]=1;
		}
	}
	long long a=1;
	for(int i=k;i>=1;i--){
		if(bnx[i]==1) ans+=a;
		a=a*2;
	}
	return ans;
}
int main(){
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%lld%d",&n,&k);
		printf("%lld\n",cz(n));
	}
}
