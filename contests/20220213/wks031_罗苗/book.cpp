#include <iostream>
#include <cstring>
typedef long long ll;
const ll N = 2e5;
ll n, m;
ll a[N + 5];
ll dp[2][N + 5];
ll sum[N + 5];
ll Max[N + 5];
ll ans = 0x3f3f3f3f;
int main()
{
	freopen("book.in", "r", stdin);
	freopen("book.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	Max[0] = -0x3f3f3f3f;
	for (ll i = 1; i <= n; i ++ )
	{
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
		Max[i] = std :: max(a[i], Max[i - 1]);
	}
	for (ll i = 1; i <= m; i ++ )
	{
		dp[i & 1][i] = Max[i];
		for (ll j = i + 1; j <= n; j ++ )
		{
			dp[i & 1][j] = 0x3f3f3f3f;
			for (ll k = i - 1; k < j; k ++ )
				dp[i & 1][j] = std :: min(dp[i & 1][j], std :: max(dp[(i - 1) & 1][k], sum[j] - sum[k - 1]));
		}
	}
	for (int i = m; i <= n; i ++ )
		ans = std :: min(ans, dp[m & 1][i]);
	printf("%d", ans);
	return 0;
}
