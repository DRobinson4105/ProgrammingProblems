#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

class Compare {
public: 
    bool operator() (const pair<string, int>& a, const pair<string, int>& b) const {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    }
};

class FoodRatings  {
public:
    unordered_map<string, pair<string, int>> food_info;
    unordered_map<string, set<pair<string, int>, Compare>> cuisine_info;

    FoodRatings(vs& foods, vs& cuisines, vi& ratings) {

        for(int i = 0; i < foods.size(); i++) {
            food_info[foods[i]] = {cuisines[i], ratings[i]};
            cuisine_info[cuisines[i]].insert(make_pair(foods[i], ratings[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        pair<string, int>& f = food_info[food];
        int old_rating = f.second;

        set<pair<string, int>, Compare>& st = cuisine_info[f.first];

        st.erase({food, old_rating});

        f.second = newRating;
        st.insert(make_pair(food, newRating));
    }
    
    string highestRated(string cuisine) {
        return cuisine_info[cuisine].begin()->first;
    }
};