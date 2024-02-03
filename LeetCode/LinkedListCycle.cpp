#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        
        ListNode * slow = head;
        ListNode * fast = head->next;

        while (fast) {
            // If fast pointer has looped around and is
            // pointing to same node as slow pointer
            if (slow == fast)
                return true;

            // If end of list was reached
            if (!fast->next)
                return false;

            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
};