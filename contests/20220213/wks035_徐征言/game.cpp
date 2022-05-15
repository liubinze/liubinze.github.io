#include<bits/stdc++.h>
using namespace std;
int n,m,t,k,ans[105];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int l=0;
		ans[0]=0;
		for(int a=1;l+a<=k;a*=2)
		{
			ans[++ans[0]]=l+1;
			l+=a;
		}
		if(l!=k) printf("NO\n");
		else
		{
			printf("YES\n%d\n",ans[0]);
			for(int a=1;a<=ans[0];a++) printf("%d ",ans[a]);
			if(ans[0]>0) printf("\n");
		}
	}
}
