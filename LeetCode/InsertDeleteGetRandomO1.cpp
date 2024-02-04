#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class RandomizedSet {
    unordered_map<int, int> mp;
    vi nums;
    int size;
    
    public:
        RandomizedSet() {
            size = 0;
        }
        
        bool insert(int val) {
            if (mp.find(val) != mp.end()) return false;

            nums.emplace_back(val);
            mp[val] = size++;
            return true;
        }
        
        bool remove(int val) {
            if (mp.find(val) == mp.end()) return false;

            mp[nums.back()] = mp[val];
            nums[mp[val]] = nums.back();
            nums.pop_back();
            mp.erase(val);
            size--;
            return true;
        }

        int getRandom() {
            return nums[rand() % size];
        }
};