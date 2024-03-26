#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

struct DS {
	vector<int> s;
	DS(int n): s(n, -1) {}
	int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
    bool merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (s[a] > s[b]) swap(a, b);
		s[a] += s[b], s[b] = a;
		return true;
	}
	int size(int i) { return -s[find(i)]; }
	bool same(int a, int b) { return find(a) == find(b); }
};

int mst(vvl edges, int V) {
    DS ds(edges.size());
    sort(edges.begin(), edges.end());
    int mstWeight = 0;

    for (vl edge : edges) {
        int w = edge[0];
        int a = edge[1];
        int b = edge[2];

        if (ds.find(a) != ds.find(b)) {
            ds.merge(a, b);
            mstWeight = max(mstWeight, w);
        }
    }

    for (int i = 1; i < V; i++)
        if (!ds.same(0, i)) return -1;

    return mstWeight;
}

int diff(int k, string a, string b) {
    int res = 0;
    for (int i = 0; i < k; i++)
        res += abs(a[i] - b[i]);

    return res;
}

int main() {
    int n, k; cin >> n >> k;
    int highest = 0;
    vector<string> words(n);

    for (int i = 0; i < n; i++) cin >> words[i];
    vvl edges;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            edges.push_back({diff(k, words[j], words[i]), j, i});
        }
    }

    cout << mst(edges, n) << endl;
}