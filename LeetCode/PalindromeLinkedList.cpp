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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;

        // Find beginning and end of second half of linked list using a fast and slow pointer
        ListNode* start = head;
        ListNode* end = head;

        while (end->next) {
            start = start->next;

            end = end->next;
            if (!(end->next))
                break;
            end = end->next;
        }

        // Reverse second half of linked list
        ListNode* tmp = start->next;
        end = start;
        while (end->next) {
            end->next = tmp->next;
            tmp->next = start;

            start = tmp;
            tmp = end->next;
        }

        // Compare first and second half of linked list
        while (head != end) {
            if (head->val != start->val)
                return false;
            head = head->next;
            start = start->next;
        }

        return true;
    }
};