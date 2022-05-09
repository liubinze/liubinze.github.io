#include <bits/stdc++.h>

using namespace std;



struct Node {
	long long x, v;
	Node(){}
	Node(long long X, long long V) {
		x = X;
		v = V;
	}
};

priority_queue <Node> pq;
vector <Node> v[200009];
long long n, m, C, l[200009], ui, vi, wi, cnt[200009];
bool visit[200009];

bool operator < (Node x, Node y) {
	return x.v > y.v;
}

void solve(long long x) {
	memset(cnt, 0x3f, sizeof (cnt));
	cnt[x] = 0;
	pq.push(Node(x, cnt[x]));
	while (!pq.empty()) {
		Node ln = pq.top();
		pq.pop();
		visit[ln.x] = true;
		for (auto i : v[ln.x]) {
			if (visit[i.x])
				continue;
			if (cnt[i.x] > cnt[ln.x] + i.v) {
				cnt[i.x] = cnt[ln.x] + i.v;
				pq.push(Node(i.x, cnt[i.x]));
			}
		}
	}
}




int main () {
	freopen("shortest.in", "r", stdin);
	freopen("shortest.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &C);
	for (register long long i = 1; i <= n; i ++) {
		scanf("%lld", &l[i]);
		v[l[i]].push_back(Node(i + n, 0));
		if (l[i] + 1 <= n)
			v[i + n].push_back(Node(l[i] + 1, C));
	}
	for (register long long i = 1; i <= m; i ++) {
		scanf("%lld%lld%lld", &ui, &vi, &wi);
		v[ui + n].push_back(Node(vi + n, wi));
		v[vi + n].push_back(Node(ui + n, wi));
	}
	solve(1 + n);
	if (cnt[2 * n] >= 0x3f)
		cout << -1 << endl;
	else
		cout << cnt[2 * n] << endl;
	return 0;
}
