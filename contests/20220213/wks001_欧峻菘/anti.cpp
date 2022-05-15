#include <bits/stdc++.h>
using namespace std;
unsigned func(unsigned n) {  
    unsigned x = n & -n;  
    return (n + x) | ((n ^ (n + x)) / x) >> 2;  
} 
int main() {
	freopen("anti.in", "r", stdin);
	freopen("anti.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << func(n) << endl;
	}
}
