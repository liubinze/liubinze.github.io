#include <bits/stdc++.h>
using namespace std;
long long n, b[100007], maxx;
struct stu {
	long long a, t, id;
} x[100007];
bool cmp (stu x, stu y) {
	return x.a < y.a || (x.a == y.a && x.id < y.id);
}
struct q {
	long long a, t, id;
	operator < (q p1) const {
		return id > p1.id;
	}
} tot, nw;
priority_queue<q> pq;
int main () {
	freopen ("grass.in", "r", stdin);
	freopen ("grass.out", "w", stdout);
	scanf ("%lld", &n);
	for (long long i = 1; i <= n; i ++) {
		scanf ("%lld %lld", &x[i].a, &x[i].t);
		x[i].id = i;
	}
	sort (x + 1, x + n + 1, cmp);
	for (long long i = 1; i <= n; i ++) {
		b[i] = x[i].a;
	}
	tot.id = 1e5 + 7;
	tot.a = -1;
	tot.t = -1;	
	pq.push (tot);
	long long i = 0, t = 0;
	while (i <= n) {
		nw = pq.top ();
//		cout << "1 " << i << "    " << nw.a << "  " << nw.id << "  " << nw.t << "   ! " << t << "   " << maxx << endl;
		if (nw.a == -1) {
			i ++;
			tot.a = x[i].a;
			tot.t = x[i].t;
			tot.id = x[i].id;
			t = x[i].a;
			nw = tot;
//			cout << "2 " << i << "    " << nw.a << "  " << nw.id << "  " << nw.t << "   ! " << t << "   " << maxx << endl;
		}
		else {
			pq.pop ();
//			cout << "3 " << i << "    " << nw.a << "  " << nw.id << "  " << nw.t << "   ! " << t << "   " << maxx << endl;
		}
		maxx = max (maxx, t - nw.a);
		t += nw.t;
		long long y = upper_bound (b + 1, b + n + 1, t) - b - 1;
		i ++;
		for ( ; i <= y; ++ i) {
			tot.a = x[i].a;
			tot.t = x[i].t;
			tot.id = x[i].id;
			pq.push (tot);
//			cout << "4 " << i << "    " << tot.a << "  " << tot.id << "  " << tot.t << endl;
		}
		i --;
	}
	printf ("%lld", maxx);
	return 0;
} 
