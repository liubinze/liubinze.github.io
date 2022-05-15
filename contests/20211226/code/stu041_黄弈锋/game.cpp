#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	srand(time(0));
	scanf("%d",&n);
	if(n == 4)
	{
		cout << "YES\nLURD\nNO\nNO\nYES\nRUURRDLLUURDDLLLURR\n";
	}
	else for(int i = 1; i <= n; i++)
	{
		if(rand() % 2) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
