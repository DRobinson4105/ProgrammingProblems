#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi topSort(vvi graph, int v){
    vi inDegree(v, 0);
    int count = 0;
    vi result;
    priority_queue<int, vector<int>, greater<int>> q;

    for (vi outgoing : graph)
        for (int next : outgoing)
            inDegree[next]++;

    for (int i = 0; i < v; i++)
        if (inDegree[i] == 0) q.push(i);
 
    while (!q.empty()) {
        int curr = q.top(); q.pop();
        result.push_back(curr);
        count++;

        for (int next : graph[curr])
            if (--inDegree[next] == 0) q.push(next);
    }
 
    if (count != v) return {};
    return result;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;

    vvi adj(n, vi());
    for (int i = 0; i < n-1; i++) {
        if (s[i] == 'L') adj[i+1].push_back(i);
        else adj[i].push_back(i+1);
    }

    for (int num : topSort(adj, n)) cout << (num+1) << endl;
    return 0;
}