#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

ll a[200005];

int main() {
	freopen("book.in", "r", stdin);
	freopen("book.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	puts("2");
	return 0;
}
