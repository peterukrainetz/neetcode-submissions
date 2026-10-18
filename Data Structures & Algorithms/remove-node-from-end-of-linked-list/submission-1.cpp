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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;

        ListNode* curr = head;

        while (curr)
        {
            count++;
            curr = curr->next;
        }

        curr = head;

        for (int i = 0; i < count - n - 1; i++)
            curr = curr->next;

        if (count == n) {
            head = curr->next;
            delete curr;
        }
        else {
            ListNode* target = curr->next;

            if (curr->next)
                curr->next = curr->next->next;
            else
                curr->next = nullptr;

            delete target;
        }

        return head;
    }
};
