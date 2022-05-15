#include <stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

int ans = 0;

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	for (int i = 1; i <= 10000000; i++) {
		int cnt = 0;
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0) cnt += 2;
			if (j * j == i) cnt--;
		}
		ans = max(ans, cnt);
		if (i % 1000000 == 0) printf("%d\n", i);
	}
	printf("%d\n", ans);
	return 0;
}

