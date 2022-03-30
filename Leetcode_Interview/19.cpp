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
    int calc_size(ListNode *head)
    {
        // 1-> 2 -> 3 ->5
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            // cout<<count<<endl;
            count++;
            temp = temp->next;
        }
        return count;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    { // n=2

        // 1-> 2 -> 3 ->5
        // ^
        // |
        // temp
        int size = calc_size(head); // 5
        int remove = size - n + 1;
        // remove 4

        if (remove == 1)
        {
            head = head->next;
            return head;
        }

        int alter = remove - 1;
        // alter 3

        int count = 1; // count 3
        ListNode *temp = head;
        while (count < alter)
        {
            temp = temp->next;
            count++;
        }

        temp->next = temp->next->next;
        return head;
    }
};