#include "iostream"
#include "fstream"

using namespace std;



int n;




int main () {
	freopen("mooyo.in", "r", stdin);
	freopen("mooyo.out", "w", stdout);
	scanf("%d", &n);
	for (register int i = 1; i <= n; i ++) {
		for (register int i = 1; i <= 10; i ++)
			cout << 0;
		cout << endl;
	}
	return 0;
}
