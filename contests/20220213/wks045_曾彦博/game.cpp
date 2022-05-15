#include <bits/stdc++.h>
using namespace std;

int n,k,last,ans[35],idx[35],mi[35];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int t;
	scanf("%d",&t);
	mi[0] = 1;
	for(int i = 1;i <= 30;i++) mi[i] = mi[i - 1] * 2;
	while(t--)
	{
		scanf("%d %d",&n,&k);
		if(k == 0) printf("YES\n0\n");
		else if(k % 2 == 0) puts("NO");
		else
		{
			int tot = k,tmp = k,now = -1;
			queue<int> q;
			last = 0;
			for(int i = 1;i <= 35;i++) ans[i] = idx[i] =  0;
			while(tmp)
			{
				now++;
				if(tmp % 2 != 0) q.push(now);
				tmp /= 2;
			}
			printf("YES\n%d\n",now + 1);
			while(tot)
			{
				int t = q.front();
				q.pop();
				if(t == now) 
				{
					ans[now] = last + 1;
					break;
				}
				int u = q.front();
				u--;
				if(t == u)
				{
					ans[u] = last + 1,last = ans[u] + mi[u] - 1,tot -= mi[u];
					continue;
				}
				ans[u] = last + mi[u];
				for(int i = u - 1;i >= t;i--)
				{
					ans[i] = ans[i + 1] - mi[i] + 1;
				}
				ans[u] = ans[u] - mi[u] + 1;
				last = ans[t] - 1;
				tot -= mi[t];
			}
			for(int i = 0;i < now;i++) printf("%d ",ans[i]);
			printf("%d ",last + 1);
			puts("");
		}
	}
	return 0;
}
