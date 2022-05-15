#include<bits/stdc++.h>
using namespace std;
#define ls p << 1
#define rs p << 1 | 1

const int N = 1e9 + 5;

int T, n, k;
int step, now, ans;
bool flag = 1;
stack<int>anss;

bool dfs(int cnt, int &step)
{
	if(!cnt)
	{
		return 1;
	}
	if(cnt % 2 == 0)
	{
		flag = 0;
		return 0;
	}
	if(cnt == 1)
	{
		int ans = cnt <<= step;
		ans |= 1;
		anss.push(ans);
		return 1;
	}
	if(dfs((cnt - 1) / 2, ++step))
	{
		int ans = cnt - 1;
		ans <<= (step - 1);
		ans |= 1;
		anss.push(ans);
		return 1;
	}
	else if(dfs((cnt + 1) / 2, step))
	{
		int ans = cnt + 1;
		ans <<= 1;
		anss.push(ans);
		return 1;
	}
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&k);
		step = 0;
		if(dfs(k, step))
		{
			puts("YES");
			cout << step << endl;
			for(int i = 1; i <= step; i++)
			{
				cout << anss.top() << ' ';
			}
			if(step) cout << endl;
		}
		else puts("NO");
	}
	return 0;
}
/*
3
5 0
3 3 
2 2


YES
0
YES
2
3 1
NO
*/
