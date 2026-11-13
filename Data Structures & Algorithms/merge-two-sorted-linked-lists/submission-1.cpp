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


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* odp;
        ListNode* tail;
        if (list1->val <= list2->val){
            odp = list1;
            tail = list1;
            list1 = list1->next;
        }else{
            odp = list2;
            tail = list2;
            list2 = list2->next;
        }
        while (list1 != nullptr || list2 != nullptr){
            while (list1 == nullptr && list2 != nullptr){
                tail->next = list2;
                tail = list2; 
                list2 = list2->next;
                return odp;
            }
            while (list2 == nullptr && list1 != nullptr){
                tail->next = list1;
                tail = list1; 
                list1 = list1->next;
                return odp;
            }
            if (list1->val <= list2->val){
                tail->next = list1;
                tail = list1; 
                list1 = list1->next;
            }else{
                tail->next = list2;
                tail = list2; 
                list2 = list2->next;
            }
        }
        return odp;
    }
};
