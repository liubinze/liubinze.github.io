#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;

#include <cstdio> 
#include <cctype> 
const int SIZE = 1 << 20; 
char buf[SIZE], *p1, *p2; 
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++) 
void read(int &x) { 
    x = 0; 
    char ch; 
    while(!isdigit(ch = gc)); 
    do { 
       x = x*10 + ch - '0'; 
    }while(isdigit(ch = gc)); 
} 

int n, w;
int a[N];

bool check(int mid) {
	int sum = 0, tot = 0, maxx = 0;
	for (int i = 1; i <= n; i++) {
		tot++;
		maxx = max(maxx, a[i]);
		if (tot == mid) {
			tot = 0;
			sum += maxx + 1;
			if (i == n) sum--;
			maxx = 0;
			if (sum > w) return false;
		}
	}
	sum += maxx;
	return sum <= w;
}

int main() {
	freopen("wordlist.in", "r", stdin);
	freopen("wordlist.out", "w", stdout);
	read(n); read(w);
	for (int i = 1; i <= n; i++) read(a[i]);
	int l = 0, r = n, ans;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}

