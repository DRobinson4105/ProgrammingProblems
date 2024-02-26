#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <functional>
#include <string>

using namespace std;

struct edge {
    string s, t;
    int f;

    edge(string a, string b, int c) : s(a), t(b), f(c) {}

    bool operator>(const edge& other) const {
        return f > other.f;
    }
};

int main() {
    int cases;
    cin >> cases;

    for (int runs = 0; runs < cases; runs++) {
        int size;
        cin >> size;

        vector<edge> el;

        unordered_set<string> cities;
        unordered_map<string, priority_queue<edge, vector<edge>, greater<edge>>> adjList;
        unordered_map<string, int> inboundCount;

        for (int i = 0; i < size; i++) {
            string a, b;
            int f;
            cin >> a >> b >> f;

            if (cities.insert(a).second) {
                inboundCount[a] = 0;
                adjList[a] = priority_queue<edge, vector<edge>, greater<edge>>();
            }
            if (cities.insert(b).second) {
                inboundCount[b] = 0;
                adjList[b] = priority_queue<edge, vector<edge>, greater<edge>>();
            }

            el.push_back(edge(a, b, f));
        }

        for (const auto& e : el) {
            adjList[e.s].push(e);
            cities.erase(e.t);
            inboundCount[e.t]++;
        }

        priority_queue<edge, vector<edge>, greater<edge>> q;

        for (const auto& c : cities) {
            while (!adjList[c].empty()) {
                q.push(adjList[c].top());
                adjList[c].pop();
            }
        }

        string output;

        while (!q.empty()) {
            edge e = q.top(); q.pop();
            inboundCount[e.t]--;

            output += " " + to_string(e.f);

            if (inboundCount[e.t] == 0) {
                while (!adjList[e.t].empty()) {
                    q.push(adjList[e.t].top());
                    adjList[e.t].pop();
                }
            }
        }

        cout << output.substr(1) << endl;
    }

    return 0;
}