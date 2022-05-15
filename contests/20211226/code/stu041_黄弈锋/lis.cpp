#include<bits/stdc++.h>
using namespace std;

struct node{int num, head;bool flag;} a[5005];
queue<int>p, q;
int f[5005], b[5005];
int n, ans;

int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&a[i].num);
		b[i] = a[i].num;
		a[i].flag = 0;
	}
	sort(b + 1, b + 1 + n);
	for(int i = 1; i <= n; i++)
	{
		if(a[i].flag == 0)
		{
			int x = i, y = i;
			for(int j = 1; j <= n; j++)
			{
				if(a[y].num == b[j])
				{
					a[y].flag = 1;
					p.push(a[y].num);
					y++;
					while(a[y].num < a[x].num) y++;
					
				}
			}
			if(q.empty())
			{
				while(!p.empty())
				{
					q.push(p.front());
					p.pop();
				}
			}
			
			
			else if(q.size() > p.size())
			{
				while(!p.empty()) p.pop();
			}
			
			
			else if(q.size() < p.size())
			{
				while(!q.empty())
				{
					q.pop();
				}
				while(!p.empty())
				{
					q.push(p.front());
					p.pop();
				}
			}
			
			
			else if(q.size() == p.size())
			{
				if(q.front() > p.front())
				{
					while(!p.empty()) p.pop();
				}
				if(q.front() < p.front())
				{
					while(!q.empty())
					{
						q.pop();
					}
					while(!p.empty())
					{
						q.push(p.front());
						p.pop();
					}
				}
			}
			ans = q.size();
		}
		
		if(i == n)
		{
			for(int j = 1; j <= n; j++)
			{
				if(a[j].flag == 0)
				{
					i = j;
					break;
				}
			}
		}
		
	}
	printf("%d\n",ans);
	while(!q.empty())
	{
		printf("%d ",q.front());
		q.pop();
	}
	return 0;
}
/*
6
4 5 3 1 2 6
*/
