/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
  Definition for singly-linked list.
 */
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *a = nullptr, *tmp = nullptr;
        while (l1 || l2 || carry > 0)
        {
            if (l1)
            {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                carry += l2->val;
                l2 = l2->next;
            }
            if (!a)
            {
                a = new ListNode(carry % 10);
                tmp = a;
            }
            else
            {
                tmp->next = new ListNode(carry % 10);
                tmp = tmp->next;
            }
            carry = carry / 10;
        }
        return a;
    }
};
// @lc code=end
