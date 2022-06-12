#include<bits/stdc++.h>
using namespace std;

const int N = 505;

int n,m;
char mp[N][N];

bool check_h(int x,int y)
{
	for(int i = y + 1; i <= m; i++)
	{
		if(mp[x][i] == 'S' || mp[x][i] == '-')
		{
			mp[x][i] = '-';
			return 1;
		}
		if(mp[x][i] == '#') return 0;
	}
	for(int i = y - 1; i >= 1; i++)
	{
		if(mp[x][i] == 'S' || mp[x][i] == '-')
		{
			mp[x][i] = '-';
			return 1;
		}
		if(mp[x][i] == '#') return 0;
	}
	return 0;
}

bool check_l(int x,int y)
{
	for(int i = x + 1; i <= n; i++)
	{
		if(mp[i][y] == 'S' || mp[i][y] == '|')
		{
			mp[i][y] = '|';
			return 1;
		}
		if(mp[i][y] == '#') return 0;
	}
	for(int i = x - 1; i >= 1; i--)
	{
		if(mp[i][y] == 'S' || mp[i][y] == '|')
		{
			mp[i][y] = '|';
			return 1;
		}
		if(mp[i][y] == '#') return 0;
	}
	return 0;
}

bool check_kill(int x,int y,int z)
{
	for(int i = x + 1; i <= n; i++)
	{
		if(mp[i][y] == '#') return 0;
		if(mp[i][y] == '|') return 1;
		if(mp[i][y] == '-' || mp[i][y] == 'S') if(z == 1) return 1;
	}
	for(int i = x - 1; i >= 1; i--)
	{
		if(mp[i][y] == '#') return 0;
		if(mp[i][y] == '|') return 1;
		if(mp[i][y] == '-' || mp[i][y] == 'S') if(z == 1) return 1;
	}
	for(int i = y + 1; i <= m; i++)
	{
		if(mp[x][i] == '#') return 0;
		if(mp[x][i] == '-') return 1;
		if(mp[x][i] == '|' || mp[x][i] == 'S') if(z == 2) return 1;
	}
	for(int i = y - 1; i >= 1; i--)
	{
		if(mp[x][i] == '#') return 0;
		if(mp[x][i] == '-') return 1;
		if(mp[x][i] == '|' || mp[x][i] == 'S') if(z == 2) return 1;
	}
	return 0;
}

bool check()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(mp[i][j] == '.')
			{
				for(int k = i + 1; k <= n; k++)
				{
					if(mp[k][j] == '#') break;
					if(mp[k][j] == 'S' || mp[k][j] == '|') goto out;
				}
				for(int k = i - 1; k >= 1; k--)
				{
					if(mp[k][j] == '#') break;
					if(mp[k][j] == 'S' || mp[k][j] == '|') goto out;
				}
				for(int k = j + 1; k <= m; k++)
				{
					if(mp[i][k] == '#') break;
					if(mp[i][k] == 'S' || mp[i][k] == '-') goto out;
				}
				for(int k = j - 1; k >= 1; k--)
				{
					if(mp[i][k] == '#') break;
					if(mp[i][k] == 'S' || mp[i][k] == '-') goto out;
				}
				return 0;
			}
			out:;
		}
	}
	return 1;
}

signed main()
{
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				while(1)
				{
					mp[i][j] = getchar();
					if(mp[i][j] == '.' || mp[i][j] == 'S' || mp[i][j] == '#') break;
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(mp[i][j] == 'S')
				{
					bool h = 0,l = 0;
					for(int k = i + 1; k <= n; k++)
					{
						if(mp[k][j] == '#') break;
						if(mp[k][j] == 'S' || mp[k][j] == '-') l = 1;
						if(mp[k][j] == '|')
						{
							puts("No");
							goto over;
						}
					}
					for(int k = i - 1; k >= 1; k--)
					{
						if(mp[k][j] == '#') break;
						if(mp[k][j] == 'S' || mp[k][j] == '-') l = 1;
						if(mp[k][j] == '|')
						{
							puts("No");
							goto over;
						}
					}
					for(int k = j + 1; k <= m; k++)
					{
						if(mp[i][k] == '#') break;
						if(mp[i][k] == 'S' || mp[i][k] == '|') h = 1;
						if(mp[i][k] == '-')
						{
							puts("No");
							goto over;
						}
					}
					for(int k = j - 1; k >= 1; k--)
					{
						if(mp[i][k] == '#') break;
						if(mp[i][k] == 'S' || mp[i][k] == '|') h = 1;
						if(mp[i][k] == '-')
						{
							puts("No");
							goto over;
						}
					}
					if(l && h)
					{
						puts("No");
						goto over;
					}
					else
					{
						if(h)
						{
							mp[i][j] = '|';
							for(int k = j + 1; k <= m; k++)
							{
								if(mp[i][k] == '.' && !check_l(i,k))
								{
									puts("No");
									goto over;
								}
								if(mp[i][k] == '#') break;
							}
							for(int k = j - 1; k >= 1; k--)
							{
								if(mp[i][k] == '.' && !check_l(i,k))
								{
									puts("No");
									goto over;
								}
								if(mp[i][k] == '#') break;
							}
							if(check_kill(i,j,1))
							{
								puts("No");
								goto over;
							}
						}
						if(l)
						{
							mp[i][j] = '-';
							for(int k = i + 1; k <= n; k++)
							{
								if(mp[k][j] == '.' && !check_h(k,j))
								{
									puts("No");
									goto over;
								}
								if(mp[k][j] == '#') break;
							}
							for(int k = i - 1; k >= 1; k++)
							{
								if(mp[k][j] == '.' && !check_h(k,j))
								{
									puts("No");
									goto over;
								}
								if(mp[k][j] == '#') break;
							}
							if(check_kill(i,j,2))
							{
								puts("No");
								goto over;
							}
						}
					}
				}
			}
		}
		puts("Yes");
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(mp[i][j] != 'S') putchar(mp[i][j]);
				else putchar('-');
			}
			puts("");
		}
		over:;
	}
	return 0;
}
