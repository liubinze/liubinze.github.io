#include<bits/stdc++.h>
using namespace std;
int n,t,a,b,an[35];
bool bn[35],bl[35];
void cz(int n,int r){
	if(n==0){
		printf("YES\n0\n");
		return;
	}
	int k;
	for(int i=1;i;i++){
		if(n%2==1) bn[i]=1;
		else bn[i]=0;
		n/=2;
		//cout<<bn[i];
		if(n==0){
			k=i;
			break;
		}
	}
	//cout<<endl;
	for(int i=1;i<=k;i++){
		bl[i]=1;
		if(bn[i]==0){
			if(i==1){
				printf("NO\n");
				return;
			}
			bl[i-1]=0;
		}
	}
	//for(int i=1;i<=k;i++) cout<<bl[i];
	//cout<<endl;
	int a=pow(2,k-1),now=1;
	//cout<<a<<endl;
	for(int i=k;i>=1;i--){
		if(bl[i]==1){
			now=now+a;
		}
		else{
		    now=now-a;
		}
		//cout<<now<<" ";
		if(bl[i]==1) an[i]=now-a;
		else an[i]=now;
		a/=2;
		if(now-1>r){
			printf("NO\n");
			return;
		}
		//cout<<a<<endl;
	}
	printf("YES\n%d\n",k);
	for(int i=1;i<=k;i++){
		printf("%d ",an[i]);
	}
	printf("\n");
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		cz(b,a);
	}
}
