#include "iostream"
#include "fstream"
#include "algorithm"
#include "queue"

using namespace std;



struct Node {
	int reachTime, eatingTime, i;
} cow[100007];

priority_queue <Node> pq;
int n, subans[100007], ans[100007], o;

bool operator < (Node x, Node y) {
	return x.i > y.i;
}

inline bool cmp(Node x, Node y) {
	return x.reachTime < y.reachTime;
}

void solve() {
	int k = 2, h = 0, lastans = cow[1].reachTime;
	pq.push(cow[1]);
	while ((!pq.empty()) || k < n) {
		h ++;
		if (pq.empty()) {
			pq.push(cow[k]);
			lastans = cow[k].reachTime;
			k ++;
		}
		Node ln = pq.top();
		pq.pop();
		ans[ln.i] = max(0, lastans - ln.reachTime);
		for (; k <= n && cow[k].reachTime <= lastans + ln.eatingTime; k ++) {
			pq.push(cow[k]);
		}
		lastans = lastans + ln.eatingTime;
	}
}



int main () {
	freopen("grass.in", "r", stdin);
	freopen("grass.out", "w", stdout);
	scanf("%d", &n);
	for (register int i = 1; i <= n; i ++) {
		scanf("%d%d", &cow[i].reachTime, &cow[i].eatingTime);
		cow[i].i = i;
	}
	sort(cow + 1, cow + n + 1, cmp);
	solve();
	for (register int i = 1; i <= n; i ++) {
		o = max(o, ans[i]);
	}
	cout << o << endl;
	return 0;
}
