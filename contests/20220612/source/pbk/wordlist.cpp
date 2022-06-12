#include <bits/stdc++.h>
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
	} while(isdigit(ch = gc));
}
int n,w,r,p,a[1000005];
inline int Max(int x,int y) {
	return x > y ? x : y;
}
inline bool check(int x) {
	int i = 1,j,sum = 0,maxx;
	while (i <= n) {
		maxx = 0;
		j = i + x;
		for (; i < j && i <= n; i ++)
			maxx = Max(a[i],maxx);
		sum += maxx;
		if (n - i >= 0) sum ++;
		if (sum > w) return 0;
	}
	return 1;
}
int main() {
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	read(n);
	read(w);
	for (int i = 1; i <= n; i ++) read(a[i]);
	r = n,p = 1;
	while (p) {
		if (r - p > 0 && check(r - p)) r -= p,p <<= 1;
		else p >>= 1;
	}
	printf("%d",r);
	return 0;
}
