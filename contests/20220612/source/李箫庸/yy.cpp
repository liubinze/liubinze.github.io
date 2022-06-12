#include <iostream>
#include <cstring>
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



int T, n, m, ln1, ln2, fir, cnt;
bool contr[13][13];
bool visit[31], c[31];

int dfs(int x, int ans, int las) {
	if (x == 2 * n) {
		for (register int i = n + 1; i <= 2 * n; i ++) {
			if (visit[i])
				continue;
			int lnans = 0;
			if (contr[las][i] == true && c[x - 1] == false)
				lnans ++;
			if (contr[fir][i] == true && c[1] == false)
				lnans ++;
			return ans + lnans;
		}
	}
	
	int retu = 0x3f3f3f3f;
	if (x & 1) {
		
		for (register int i = 1; i <= n; i ++) {
			if (visit[i])
				continue;
			visit[i] = true;
			if (x == 1) {
				fir = i;
			}
			if (contr[las][i])
				c[x] = true;
			else
				c[x] = false;
			retu = min(retu, dfs(x + 1, ans + (contr[las][i] == true), i));
			visit[i] = false;
		}
		
	}
	else {
		
		for (register int i = n + 1; i <= 2 * n; i ++) {
			if (visit[i])
				continue;
			visit[i] = true;
			if (contr[las][i])
				c[x] = true;
			else
				c[x] = false;
			retu = min(retu, dfs(x + 1, ans + (contr[las][i] == true && c[x - 1] == false), i));
			visit[i] = false;
		}
		
	}
	return retu;
}




int main () {
	freopen("yy.in", "r", stdin);
	freopen("yy.out", "w", stdout);
	read(T);
	while (T --) {
		memset(contr, false, sizeof (contr));
		memset(c, false, sizeof (c));
		read(n);
		read(m);
		for (register int i = 1; i <= m; i ++) {
			read(ln1);
			read(ln2);
			contr[ln1][ln2 + n] = contr[ln2 + n][ln1] = true;
		}
		int ans = dfs(1, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
/*

1
5 8
2 5
2 3
5 5
1 3
2 4
2 1
1 2
5 2

*/
