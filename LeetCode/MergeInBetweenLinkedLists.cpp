#include <bits/stdc++.h>
using namespace std;

/*
Find the tail of list2, the node before a in list1, and the node after b in list1. Point the node
before a to the head of list2 and point the tail of list2 to the node after b in list1. Return the
head of list1.
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* list2Tail = list2;
        while (list2Tail->next) list2Tail = list2Tail->next;

        ListNode* aNode = list1;
        while (a-- != 1) aNode = aNode->next;

        ListNode* bNode = aNode; b -= a;
        while (b-- != -1) bNode = bNode->next;

        aNode->next = list2;
        list2Tail->next = bNode;
        return list1;
    }
};