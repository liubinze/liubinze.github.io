#include<bits/stdc++.h>
using namespace std;
struct nb{
	int a,t,zili;
	bool eat;
}w[100001];
int now,n,chi=0,last=1,m;
bool cmp(nb a,nb b)
{
	return a.a<b.a;
}
bool cmp_(nb a,nb b)
{
	return a.zili<b.zili;
}
bool eat[1000001];
int ans=0;
int main()
{
	freopen("grass.in","r",stdin);
	freopen("grass.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&w[i].a,&w[i].t);
		w[i].zili=i;
		w[i].eat=false;
	}
	sort(w+1,w+1+n,cmp);
	now=w[1].a;
	while(chi<n)
	{		
//	cout<<now<<" ";
	for(int i=last+1;i<=n;i++)
	{
		if(w[i].a>now&&w[i].a!=w[i-1].a)
		{
			if(chi==last)
			now=w[i].a;
			break;
		}
		last=i;
	}	
	sort(w+1,w+1+last,cmp_);
	for(int i=1;i<=last;i++)
	{
	if(w[i].eat==false)
	{
	w[i].eat=true;
	chi++;
	ans=max(ans,now-w[i].a);
	now+=w[i].t;	
//	cout<<w[i].t<<" ";
	break;	
	}
	}

	}
	cout<<ans;
}
