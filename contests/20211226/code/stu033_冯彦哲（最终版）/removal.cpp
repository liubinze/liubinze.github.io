#include<bits/stdc++.h>
using namespace std;
int n,k,m,a[100005],l[100005];
bool visit[100005];
int main(){
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	while(cin>>n>>m>>k){
		int num=0,i=1;
		for(int i=1;i<=n;visit[i]=0,i++) scanf("%d",&a[i]);
		while(i<=n){
			int id=0,u=0x3f3f3f3f;
			for(int j=i;j<=i+m&&j<=n;j++)
				if(a[j]<u) u=a[j],id=j;
			l[++num]=u,m-=(id-i),i=id+1;
		}
		if(m>0){
			for(int i=1;i<num&&m>0;i++)
				if(l[i]>l[i+1]) visit[i]=1,m--;
			for(int i=num;i>=1&&m>0;i--){
				if(!visit[i]) visit[i]=1,m--;
			}
		}
		for(int i=1;i<=num;i++) 
			if(!visit[i]) printf("%d ",l[i]);
		printf("\n");
	}
}
