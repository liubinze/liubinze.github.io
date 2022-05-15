#include <stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 5005;

int n, ans;
int a[N], dp[N], from[N];
int maxx[N], temp[N];

int Max(int a[], int b[], int len) {
	for (int i = 1; i <= len; i++)
		if (a[i] < b[i]) return 2;
		else if (a[i] > b[i]) return 1;
}

int main() {
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = n; i; i--) {
		for (int j = i + 1; j <= n; j++) 
			if (a[j] > a[i])
				if (dp[j] > dp[from[i]] || dp[j] == dp[from[i]] && a[j] > a[from[i]])
					from[i] = j;
		dp[i] = dp[from[i]] + 1;
	}
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	for (int i = 1; i <= n; i++) {
		if (dp[i] != ans) continue;
		bool flag = false;
		for (int j = i, tot = 1; j; j = from[j], tot++) {
			if (flag) maxx[tot] = a[j];
			else if (a[j] > maxx[tot]) flag = true, maxx[tot] = a[j];
			else if (a[j] < maxx[tot]) break;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++) printf("%d ", maxx[i]);	
	return 0;
}

