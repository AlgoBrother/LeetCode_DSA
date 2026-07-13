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
    ListNode* mergeLL(ListNode* l1, ListNode* l2){
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val < l2->val){
            l1->next = mergeLL(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeLL(l1, l2->next);
            return l2;
        }
        return NULL;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        while(lists.size() > 1){
            vector<ListNode*> temp;
            for(size_t i = 0; i < lists.size(); i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
                temp.push_back(mergeLL(l1, l2));
            }
            lists = move(temp);
        }
        return lists[0];
    }
};