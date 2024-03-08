#include <bits/stdc++.h>
using namespace std;

/*
Find middle of the linked list and then traverse to it.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* tmp = head;
        while (tmp) {
            tmp = tmp->next;
            len++;
        }

        len /= 2;
        while (len--) {
            head = head->next;
        }

        return head;
    }
};