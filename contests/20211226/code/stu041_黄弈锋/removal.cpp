#include<bits/stdc++.h>
using namespace std;

bool flag[100005];
int s[100005], s1[100005];
int n, m, k;

queue<int> q;

int main()
{
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s1[i] = s[i];
	}
	for(int d = 1; d <= m; d++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = i; j <= n; j++)
			{
				s1[j] = s1[j + 1];
			}
			for(int j = 1; j < n; j++)
			{
				if(s1[j] > s[j]) flag[i] = 1;
			}
			if(flag[i] == 0)
			{
				if(q.empty())
				{
					for(int j = 1; j < n; j++)
					{
						q.push(s1[j]);
					}
				}
				
				else 
				{
					if(q.front() > s1[1])
					{
						for(int j = 1; j < n; j++)
						{
							q.pop();
							q.push(s1[j]);
						}
					}
					else if(q.front() < s1[1])
					{
						;
					}
					else
					{
						queue<int> p;
						for(int j = 1; j < n; j++)
						{
							if(q.front() > s1[j])
							{
								while(q.size()) q.pop();
								for(int l = 1; l < n; l++) q.push(s1[l]);
							}
							else if(q.front() < s1[j])
							{
								while(q.size()) p.push(q.front()), q.pop();
								while(p.size()) q.push(p.front()), p.pop();
							}
							else
							{
								p.push(q.front());
								q.pop();
							}
						}
					}
				}
			}
			for(int j = 1; j <= n; j++) s1[j] = s[j];
		}
		for(int i = 1; i < n; i++)
		{
			s[i] = q.front();
			s1[i] = q.front();
			q.pop();
		}
		n--;
		while(q.size()) q.pop();
	}
	while(q.size())
	{
		cout << q.front() << ' ';
		q.pop();
	}
	return 0;
}
