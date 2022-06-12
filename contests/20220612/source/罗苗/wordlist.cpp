#include <iostream>
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
const int N = 1e6;
int n, w;
int a[N + 5];
bool check(int x)
{
	int res = -1;
	int Max = 0;
	for (int i = 1; i <= n; i ++ )
	{
		Max = std :: max(Max, a[i]);
		if (i % x == 0 || i == n)
		{
			res += Max + 1;
			if (res > w) return 0;
			Max = 0;
		}
	}
	return 1;
}
int ans;
int main()
{
	freopen("wordlist.in", "r", stdin);
	freopen("wordlist.out", "w", stdout);
	read(n), read(w);
	for (int i = 1; i <= n; i ++ ) read(a[i]);
	int l = 1, r = n;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d", ans);
	return 0;
}
