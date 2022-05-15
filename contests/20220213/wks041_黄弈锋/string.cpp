#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, del;
int L, R;
string F;
string s[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d %d",&n,&m);
	s[0] = getchar(); //\n
	for(int i = 1; i <= n; i++) s[i] = getchar();
	
	for(int st = 1; st <= m; st++)
	{
		scanf("%d %d",&L,&R);
		s[0] = getchar(); //\n
		F = getchar();
		if(L >= n - del + 1) continue;
		for(int i = L + del, now = 1; i <= R + del && now <= R - L + 1; i++)
		{
			if(s[i] == "")
			{
				continue;
			}
			else
			{
				if(s[i] == F) s[i] = "", del++;
				now++;
			}
//			cout << now << endl;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(s[i] != "") cout << s[i];
	}
	return 0;
}
/*
4 2
abac
1 3 a
2 2 c

b

9 5
aAAaBBccD
1 4 a
5 6 c
2 3 B
4 4 D
2 3 A

AB

10 4
agtFrgF4aF
2 5 g
4 9 F
1 5 4
1 7 a

tFrg4
*/
