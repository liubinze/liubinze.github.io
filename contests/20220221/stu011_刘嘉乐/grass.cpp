#include<bits/stdc++.h>
using namespace std;
int n,t,k=1,ke,x[100005],y[100005],s;
struct node{int x,y,id;}a[100005];
priority_queue<int,vector<int>,greater<int> >p;
bool cmp(node a,node b){return (a.x==b.x?a.id<b.id:a.x<b.x);}
int main(){
	freopen("grass.in","r",stdin);
	freopen("grass.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i,x[i]=a[i].x,y[i]=a[i].y;
	sort(a+1,a+n+1,cmp);
	while(k<=n){
		if(t<=a[k].x)t=a[k].x+a[k].y,k++;
		else{
			if(k>ke){
				ke=k,p.push(a[k].id);
				while(a[ke+1].x<t&&ke<n)++ke,p.push(a[ke].id);
			}
			int l=p.top();
			p.pop();
			s=max(s,t-x[l]),t+=y[l],k++;
		}
	}
	printf("%d\n",s);
	return 0;
}
