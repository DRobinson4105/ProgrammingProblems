#include <bits/stdc++.h>
using namespace std;

/*
Find length of list. Use length of list and nth node from end to calculate distance from start. If
the target node is the first node, return the next node after head since the head needs to be
deleted. Traverse to node before it and delete the next node by setting the next pointer to the
node after the next node. Return the head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;

        while (temp) {
            temp = temp->next;
            len++;
        }
        
        temp = head;
        if (len - n == 0) return head->next;
        
        for (int i = 0; i < len - n - 1; i++)
            temp = temp->next;

        temp->next = temp->next->next;
        return head;
    }
};