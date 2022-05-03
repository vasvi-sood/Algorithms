/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *slow = head, *fast = head;
        while (true)
        {
            if (fast->next == NULL || fast->next->next == NULL)
                return NULL;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                slow = head;
                while (fast != slow)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }

        return NULL;
    }
};