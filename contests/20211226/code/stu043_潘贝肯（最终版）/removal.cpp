#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[100005];
vector <int> ans;
int main() {
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	while (cin >> n >> m >> k) {
		ans.clear();
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&a[i]);
			if (i <= n - m) ans.push_back(a[i]);
		}
		for (int i = n - m + 1; i <= n; i ++)
			for (int j = 0; j < n - m; j ++)
				if (j == n - m - 1) ans.pop_back(),ans.push_back(a[i]);
				else if (ans[j] > ans[j + 1]) {
					ans.erase(ans.begin() + j,ans.begin() + j + 1);
					ans.push_back(a[i]);
					break;
				}
		for (int i = 0; i < ans.size(); i ++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
