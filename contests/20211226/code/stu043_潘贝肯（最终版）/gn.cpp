#include <bits/stdc++.h>
using namespace std;
int t,n,p[1000005],r[10000005],m_r[10000005];
long long g[10000005];
bool bp[10000005];
void OL(int n) {
	for (int i = 2; i <= n; i ++) {
		if (!bp[i]) p[++ p[0]] = i,r[i] = m_r[i] = 1;
		for (int j = 1; j <= p[0] && i * p[j] <= n; j ++) {
			bp[i * p[j]] = 1;
			if (i % p[j] == 0) {
				r[i * p[j]] = r[i] + 1;
				m_r[i * p[j]] = max(m_r[i],r[i * p[j]]);
				break;
			} else r[i * p[j]] = 1,m_r[i * p[j]] = max(m_r[i],m_r[p[j]]);
		}
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; i * j <= n; j ++)
			g[i * j] += i * m_r[j];
}
int main() {
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	OL(10000000);
	scanf("%d",&t);
	while (t --) {
		scanf("%d",&n);
		printf("%lld\n",g[n]);
	}
	return 0;
}
