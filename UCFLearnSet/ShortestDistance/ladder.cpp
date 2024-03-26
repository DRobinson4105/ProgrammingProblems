#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

string betweenWord(string a, string b) {
    int whichWord = 0;
    string s;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            if ((whichWord == 0 && a[i] < b[i]) || whichWord == 1) {
                s.push_back(a[i]);
                whichWord = 2;
            } else {
                s.push_back(b[i]);
                whichWord = 1;
            }
        } else {
            s.push_back(a[i]);
        }
    }

    return s;
}

pair<string, int> shortestPath(int v, vector<vpii> adj, vector<string>& words) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<long long> distWith(v, INT_MAX);
    vector<long long> distWithout(v, INT_MAX);
    vector<string> word(v, "0");
    distWithout[0] = 0;
    distWith[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (u == 1) {
            if (distWithout[u] <= distWith[u]) {
                return {"0", distWithout[u]};
            } else {
                return {word[u], distWith[u]};
            }
        }

        for (auto& [v, w] : adj[u]) {
            if (w == 1) {
                if (distWithout[v] > distWithout[u] + 1) {
                    distWithout[v] = distWithout[u] + 1;
                    pq.push({distWithout[v], v});
                }
                if (distWith[v] > distWith[u] + 1) {
                    distWith[v] = distWith[u] + 1;
                    word[v] = word[u];
                    pq.push({distWith[v], v});
                }
            } else if (distWith[v] > distWithout[u] + 2) {
                distWith[v] = distWithout[u] + 2;
                word[v] = betweenWord(words[u], words[v]);
                pq.push({distWith[v], v});
            }
		}
	}

    return {"0", -1};
}

int wordDiff(string a, string b) {
    int diff = 0;

    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i]) diff++;

    return diff;
}

int main() {
    int n, len; cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];
    if (words[0] == words[1]) {
        cout << "0\n0\n";
        return 0;
    }
    len = words[0].length();

    vector<vpii> adj(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int diff = wordDiff(words[i], words[j]);
            if (diff == 1 || diff == 2) {
                adj[i].push_back({j, diff});
                adj[j].push_back({i, diff});
            }
        }
    }

    auto [word, dist] = shortestPath(n, adj, words);

    cout << word << endl << dist << endl;
    return 0;
}