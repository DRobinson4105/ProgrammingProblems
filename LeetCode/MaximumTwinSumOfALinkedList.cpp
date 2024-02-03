#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        // Get length of linked list
        int len = 0;
        ListNode* tmp = head;
        
        while (tmp) {
            len++;
            tmp = tmp->next;
        }

        // Divide len by 2 to iterate through twins
        len /= 2;
        
        vi twins(len);
        int max = 0;

        // Add first half of list to vector
        for (int i = 0; i < len; i++) {
            twins[i] = head->val;
            head = head->next;
        }

        // Take sum of each pair of twins and find maximum of the sums
        for (int i = len - 1; i >= 0; i--) {
            if (twins[i] + head->val > max)
                max = twins[i] + head->val;
            head = head->next;
        }

        return max;
    }
};