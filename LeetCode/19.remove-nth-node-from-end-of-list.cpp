/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head, *fast = head;
        while (n--)
        {
            fast = fast->next;
        }
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if (fast)
        {
            fast = slow->next;
            slow->next = slow->next->next;
            delete fast;
        }
        else
        {
            fast = head;
            head = head->next;
            delete fast;
        }

        return head;
    }
};
// @lc code=end
