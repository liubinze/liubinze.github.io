#include <bits/stdc++.h>
using namespace std;
unsigned long long n = 1;
int main () {
	for(int i = 1; i <= 63; i ++) {
		n = n * 2ULL;
	}
	cout << n;
	return 0;
}

