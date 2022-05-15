#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,tot;
struct node
{
	int a,t,c,ans;
}cow[N],cow1[N];

bool cmp(node u,node v)
{
	if(u.a==v.a)return u.c<v.c;
	else return u.a<v.a;
}

priority_queue<int,vector<int>,greater<int> >q;

signed main()
{
	freopen("grass.in","r",stdin);
	freopen("grass.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&cow[i].a,&cow[i].t);
		cow[i].c=i;
		cow1[i].a=cow[i].a,cow1[i].t=cow[i].t,cow1[i].c=i;
	}
	sort(cow+1,cow+1+n,cmp);
	tot=cow[1].a+cow[1].t;
	int i=2;
	while(i<=n)
	{
		while(cow[i].a<=tot)
		{
			q.push(cow[i].c);
			i++;
		}
		while(!q.empty()&&tot<cow[i].a)
		{
			int j=q.top();
			q.pop();
			cow1[j].ans=tot-cow1[j].a;
			tot+=cow1[j].t;
		}
		if(tot<cow[i].a&&i<=n)
		{
			tot=cow[i].t;
			i++;
		}
	}
	int Ans=0;
	for(int i=1;i<=n;i++)Ans=max(Ans,cow1[i].ans);
	printf("%lld\n",Ans);
	return 0;
}
