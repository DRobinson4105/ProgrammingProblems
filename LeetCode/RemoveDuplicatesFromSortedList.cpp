#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == nullptr) return nullptr;

        ListNode* cur = head;

        while (cur->next) {
            // Remove next node if curr node and next node are equal
            if(cur->next->val == cur->val)
                cur->next = (cur->next->next == nullptr) ? nullptr: cur->next->next;
            else
                cur = cur->next;
        }

        return head;
    }
};