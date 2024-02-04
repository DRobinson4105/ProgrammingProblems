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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode * first = head->next;
        ListNode * second = head;

        // Swap nodes
        second->next = first->next;
        first->next = second;

        // Swap rest of linked list
        second->next = swapPairs(second->next);

        // Have previous node point to first
        return first;
    }
};