#include <iostream>
#include <fstream>

using namespace std;
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



int n, w, a[1000007], l, r, mid;

inline bool check(int x) {
	int ans = 0;
	for (register int i = 1; i <= n; i += x) {
		int Max = 0;
		for (register int j = i; j < i + x; j ++)
			Max = max(Max, a[j]);
		ans += Max + 1;
	}
	return (ans  - 1 <= w);
}




int main () {
	freopen("wordlist.in", "r", stdin);
	freopen("wordlist.out", "w", stdout);
	read(n);
	read(w);
	for (register int i = 1; i <= n; i ++) {
		read(a[i]);
	}
	l = 1;
	r = 1000000;
	while (l < r) {
		mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << r << endl;
	return 0;
}
