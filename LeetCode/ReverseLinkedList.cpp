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
    ListNode* solve(ListNode* head, ListNode* curr, ListNode* old) {
        // If list reversal is finished, return head
        if (head->next == nullptr) return old;
        
        // Move next node to head of reversed sublist
        head->next = curr->next;
        curr->next = old;

        // Reverse next node
        return solve(head, head->next, curr);
    }

    ListNode* reverseList(ListNode* head) {
        // If list does not need to be reversed
        if (head == nullptr || head->next == nullptr) return head;

        return solve(head, head->next, head);
    }
};