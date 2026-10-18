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
        ListNode dummy(0, nullptr);
        ListNode *prev = &dummy;

        int carry = 0;

        while (l1 || l2)
        {
            int lhs;
            int rhs;

            if (!l1)
            {
                lhs = 0;
                rhs = l2->val;
            }
            else if (!l2)
            {
                lhs = l1->val;
                rhs = 0;
            }
            else
            {
                lhs = l1->val;
                rhs = l2->val;
            }

            int result = lhs + rhs + carry;

            if (result >= 10)
            {
                result = result % 10;
                carry = 1;
            }
            else
                carry = 0;

            ListNode* newNode = new ListNode(result);
            prev->next = newNode;
            prev = newNode;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (carry == 1)
            prev->next = new ListNode(1, nullptr);

        return dummy.next;
    }
};
