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
        ListNode* dummy = new ListNode();
        ListNode* mergedCurr = dummy;
        ListNode* l1Curr = list1;
        ListNode* l2Curr = list2;

        while (l1Curr || l2Curr)
        {
            if (l1Curr && (!l2Curr || l1Curr->val <= l2Curr->val))
            {
                mergedCurr->next = l1Curr;
                l1Curr = l1Curr->next;
            }
            else
            {
                mergedCurr->next = l2Curr;
                l2Curr = l2Curr->next;
            }

            mergedCurr = mergedCurr->next;
        }

        return dummy->next;
    }
};
