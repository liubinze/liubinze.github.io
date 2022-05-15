#include<bits/stdc++.h>
int n,m,k,t[100005];
bool check(int mx)
{
	int h=0,f=0,cnt=0;
	for(int a=1;a<=n;a++)
	{
		if(a==1||h==k||t[a]-f>mx)
		{
			cnt++;
			f=t[a];
			h=0;
		}
		h++;
	}
	if(cnt>m) return 0;
	return 1;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int a=1;a<=n;a++) scanf("%d",&t[a]);
	std::sort(t+1,t+1+n);
	int l=0,r=1e9;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid)==1) r=mid;
		else l=mid+1;
	}
	printf("%d",l);
}
