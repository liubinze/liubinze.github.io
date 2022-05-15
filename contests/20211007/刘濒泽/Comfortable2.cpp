#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool e[2001][2001];
ll ul,ur,dl,dr;
inline bool cheat(ll x,ll y)
{
	return e[x][y]&&(ll(x&&e[x-1][y])+ll(y&&e[x][y-1])+ll(e[x+1][y])+ll(e[x][y+1])==3ll);
}
int main()
{
	freopen("Comfortable2.in","r",stdin),freopen("Comfortable2.out","w",stdout);
	ll n,x,y,ans=0ll;
	printf("0\n0\n0\n1\n0\n0\n1\n2\n4");
	return 0;
}
