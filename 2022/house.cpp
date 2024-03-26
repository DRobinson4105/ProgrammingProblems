#include <bits/stdc++.h>
using namespace std;

struct node{
   int lo,hi,mid;
   long long val;
   node *left; node *right;
   node(int l, int r){
       lo = l; hi = r;
       mid = (lo+hi)/2;
       val = 0;
       if(l==r) return;
       left = new node(l,mid);
       right = new node(mid+1,r);
   }
   int query(int l, int r){
       if(l>hi||r<lo) return 0;
       if(l<=lo&&hi<=r) return val;
       return left->query(l,r) + right->query(l,r);
   }
   void update(int i, int v){
       if(lo==hi) return void(val += v);
       if(i<=mid) left->update(i, v);
       else right->update(i, v);
       val = left->val + right->val;
   }
};

int main() {
    int n; cin >> n;
    node* segtree = new node(1, n);
    
    for (int i = 1; i <= n; i++) {
        int val; cin >> val;
        segtree->update(i, val);
    }

    int t; cin >> t;

    while (t--) {
        char c; cin >> c;
        if (c == 'U') {
            int i, v; cin >> i >> v;
            segtree->update(i, v);
        } else {
            int l, r; cin >> l >> r;
            cout << segtree->query(l, r) << endl;
        }
    }

    return 0;
}