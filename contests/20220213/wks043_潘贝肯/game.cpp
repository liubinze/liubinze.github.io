#include <bits/stdc++.h>
using namespace std;
int t,n,k,sum;
void solve(int i,int lst,int sum) {
	if (sum == 0) return ;
	int ii = i;
	if (lst - ii + 1 >= sum) solve(ii + sum,lst,sum / 2);
	else {
		i = lst - sum + 1;
		solve(lst - sum + 1,ii - 1,sum / 2);
	}
	printf("%d ",i);
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d",&n,&k);
		if (k != 0 && k % 2 == 0) printf("NO\n");
		else {
			printf("YES\n");
			sum = pow(2,int(log2(k)));
			if (k != 0) {
				printf("%d\n",int(log2(k)) + 1);
				solve(1,k,sum);
				cout << endl;
			} else printf("0\n");
		}
	}
	return 0;
}
