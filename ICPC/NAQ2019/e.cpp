#include <bits/stdc++.h>

using namespace std;

string bestStr = "";
int bestVowels = -1;

unordered_map<int, pair<int, string>> memo;

int numVowels(string s) {
    int res = 0;
    for (char c : s) {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            res++;
    }

    return res;
}

string withoutVowels(string s) {
    string res;
    for (char c : s) {
        if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
            res.push_back(c);
    }

    return res;
}

pair<int, string> compute(string curr, unordered_map<string, pair<int, string>> wVowels) {
    if (curr.length() == 0) {
        return {0, ""};
    }

    if (memo.count(curr.length())) return memo[curr.length()];

    pair<int, string> best = {-1, ""};

    for (auto p : wVowels) {
        if (curr.length() >= p.first.length() && curr.substr(0, p.first.length()).compare(p.first) == 0) {
            pair<int, string> cur = compute(curr.substr(p.first.length(), curr.length() - p.first.length()), wVowels);
            cur.second = p.second.second + " " + cur.second;
            cur.first += p.second.first;
            if (cur.first > best.first)
                best = {};
        }
    }

    // cout << curr << " " << best.second << endl;

    return memo[curr.length()] = best;
}

int main() {
    int n; cin >> n;
    unordered_map<string, pair<int, string>> wVowels;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        string without = withoutVowels(s);
        int num = numVowels(s);
        if (wVowels.count(without) && wVowels[without].first > num) continue; 
        wVowels[without] = {num, s};
    }

    string s; cin >> s;
    // compute(s, "", wVowels);
    string ahh = compute(s, "", wVowels).second;
    cout << ahh.substr(0, ahh.length() - 1) << endl;
    return 0;
}