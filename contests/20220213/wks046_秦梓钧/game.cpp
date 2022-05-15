#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[105],tot;
vector<int>vec;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&T);
	a[1]=1;
	for(int i=2,k=2;k<=1e9;i++,k=k*2)a[++tot]=k-1;
	int k;
	while(T--){
		scanf("%d%d",&n,&k);
		if(k==0){
			puts("Yes");
			puts("0");
			continue;
		}
		if(k%2==0){
			puts("No");
			continue;
		}
		bool fl=0;
		vec.clear();
		for(int i=1,l=0;i<=n&&!fl;i*=2,l++){
			for(int j=i;j<=tot;j++){
				if(a[j]-a[l]==k){
					int ans=1,cc=1<<l;
					while(ans<k){
						vec.push_back(ans);
						ans+=cc;
						fl=1;
						cc*=2;
					}
					break;
				}
			}
			if(fl)break;
			vec.push_back(k+1);
			k+=i;
			if(k>n)break;
		}
		if(!fl){
			puts("No");
			continue;
		}
		puts("Yes");
		printf("%d\n",vec.size());
		for(int i=0;i<vec.size();i++){
			printf("%d ",vec[i]);
		}
		puts("");
	}
	return 0;
}
