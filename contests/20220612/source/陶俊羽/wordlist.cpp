#include <bits/stdc++.h>
 
const int SIZE = 1 << 20; 
char buf[SIZE], *p1, *p2; 

#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++) 

void read(int &x) { 
    x = 0; 
    char ch; 
    while (!isdigit(ch = gc)); 
    do { 
       x = x * 10 + ch - '0'; 
    } while(isdigit(ch = gc)); 
}

using namespace std;

int n, w, a[1000003];

bool check(int chart_height) {
	long long sum = -1;
	for (int i = 1; i <= n; i += chart_height) {
		int temp = 0;
		for (int j = 0; j < chart_height && i + j <= n; ++ j)
			temp = max(a[i + j], temp);
		sum += (long long)(temp + 1);
	}
	if (sum > (long long)(w)) return false;
	return true;
}

int main() {
	freopen("wordlist.in", "r", stdin);
	freopen("wordlist.out", "w", stdout);
	read(n); read(w);
	for (int i = 1; i <= n; ++ i) read(a[i]);
	int lft = 1, rht = n, mid;
	while (lft < rht) {
		mid = (lft + rht) >> 1;
		if (check(mid)) rht = mid;
		else lft = mid + 1;
	}
	printf("%d", lft);
	return 0;
}
