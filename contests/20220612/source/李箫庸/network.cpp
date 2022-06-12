#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>

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



struct Node {
	int x, y, ans;
	bool d;
}	a[300007];

vector <int> v[300007];
int n, m, A, B, lnx, lny, op, ans[300007];
bool bee[300007], een[300007];
bool visit[300007];

int get_ans(int x) {
	visit[x] = true;
	int retu = 0;
	if (een[x])
		retu ++;
	for (auto i : v[x])
		if (!visit[i])
			retu += get_ans(i);
	return retu;
}

inline bool cmp(Node x, Node y) {
	return x.y > y.y;
}




int main () {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	read(n);
	read(m);
	read(A);
	read(B);
	for (register int i = 1; i <= n; i  ++) {
		read(a[i].x);
		read(a[i].y);
		if (a[i].x == 0)
			a[i].d = true;
		if (a[i].x == A) {
			a[i].d = false;
			een[i] = true;
		}
			
	}
	for (register int i = 1; i <= m; i ++) {
		read(lnx);
		read(lny);
		read(op);
		v[lnx].push_back(lny);
		if (op == 2)
			v[lny].push_back(lnx);
	}
	for (register int i = 1; i <= n; i ++) {
		memset(visit, false, sizeof (visit));
		if (!a[i].d)
			continue;
		a[i].ans = get_ans(i);
	}
	sort(a + 1, a + n + 1, cmp);
	for (register int i = 1; i <= n; i ++) {
		if (a[i].d == true)
			cout << a[i].ans << endl;
	}
	return 0;
}
