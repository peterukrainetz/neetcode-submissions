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
        int nodeCount = 0;

        ListNode* curr = head;

        while (curr) {
            nodeCount++;
            curr = curr->next;
        }

        curr = head;

        for (int i = 0; i < nodeCount / 2; i++) {
            curr = curr->next;
        }

        ListNode* newHead = curr;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        newHead = prev;

        curr = head;
        ListNode* curr2 = newHead;
        ListNode* next2 = nullptr;

        while (curr || curr2) {
            if (curr) {
                next = curr->next;
                curr->next = curr2;
                curr = next;
            }

            if (curr2)
            {
                next2 = curr2->next;
                curr2->next = curr;
                curr2 = next2;
            }
        }
    }
};
