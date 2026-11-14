/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *node = head;
        int cur = 0;
        int va1 = 0, va2 = 0;
        while (l1 || l2){
            ListNode *nextt = new ListNode();

            if (!l1) {va1 = 0;}
            else {va1 = l1->val; l1 = l1->next;} 
            if (!l2) {va2 = 0;}
            else {va2 = l2->val; l2 = l2->next;}

            node->val = (va1 + va2 + cur) % 10;
            cur = (va1 + va2 + cur) / 10;
            if (!(l1 || l2 || cur)) break;
            node->next = nextt;
            node = node->next;
        }
        if (cur){
            node->val = cur;
        } 
        return head;
    }
};
