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
    void reorderList(ListNode* head) {
        if (!head->next || !head->next->next)return;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        ListNode *tail = fast->next;
        fast->next = nullptr;
        ListNode *temp = fast;
        while (tail) {
            temp = tail;
            tail = tail->next;
            temp->next = fast;
            fast = temp;
        }
        slow = head;
        while (fast){
            tail = slow->next;
            slow->next = fast;
            temp = fast->next;
            fast->next = tail;
            fast = temp;
            slow = slow->next->next;
        }
    }
};
