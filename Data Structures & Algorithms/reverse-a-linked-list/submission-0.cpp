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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr){return head;}
        ListNode* nastepny = head->next;
        ListNode* pozniej;
        ListNode* teraz = head;
        teraz->next = nullptr;
        while (nastepny != nullptr){
            pozniej = nastepny->next;
            nastepny->next = teraz;
            teraz = nastepny;
            nastepny = pozniej;
        }
        return teraz;
    }
};
