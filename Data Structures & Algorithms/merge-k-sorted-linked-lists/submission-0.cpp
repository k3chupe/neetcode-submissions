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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>> nastepny;
        ListNode* odp = nullptr;
        for (ListNode* a : lists){
            if (a != nullptr) {
                nastepny.push({-(a->val),a});
            }
        }
        ListNode* kolejny = nullptr;
        while (!nastepny.empty()){
            ListNode* teraz = nastepny.top().second;
            if (odp == nullptr){
                odp = teraz;
                kolejny = teraz;
            }else{
                kolejny->next = teraz;
                kolejny = teraz;
            }
            nastepny.pop();
            if (teraz->next != nullptr){
                nastepny.push({-(teraz->next->val),teraz->next});
            }
        }
        return odp;
    }
};
