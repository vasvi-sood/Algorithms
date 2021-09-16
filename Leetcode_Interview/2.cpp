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

    ListNode *func(ListNode *dabba_link, ListNode *h1, ListNode *h2, int carry)
    {

        if (h1->next == NULL || h2->next == NULL)
        {

            int a = h1->val;
            int b = h2->val;
            dabba_link->val = (a + b + carry) % 10;
            // cout<<a<<b<<carry<<" "<< dabba_link->val<<endl;
            if ((a + b + carry) / 10 == 1)
            {
                ListNode *la = new ListNode();
                dabba_link->next = la;
                la->val = 1;
            }
            return dabba_link;
        }
        int a = h1->val;
        int b = h2->val;

        dabba_link->val = (a + b + carry) % 10;
        // cout<<a<<b<<carry<<" "<< dabba_link->val<<endl;
        ListNode *la = new ListNode();

        dabba_link->next = la;
        func(la, h1->next, h2->next, (a + b + carry) / 10);
        return dabba_link;
    }

public:
    ListNode *addTwoNumbers(ListNode *h1, ListNode *h2)
    {

        ListNode *la = new ListNode();
        // la->val=h1->val+h2->val;
        // la->next=NULL;
        // ListNode* head=la;
        int a = 0, b = 0;
        auto l1 = h1, l2 = h2;
        while (l1->next != NULL || l2->next != NULL)
        {
            if (l1->next != NULL)
            {
                a++;
                l1 = l1->next;
            }
            if (l2->next != NULL)
            {
                b++;
                l2 = l2->next;
            }
        }

        if (a > b)
        {
            for (int i = 0; i < a - b; i++)
            {
                ListNode *la = new ListNode(0);
                l2->next = la;
                l2 = la;
            }
        }
        else if (b > a)
        {
            for (int i = 0; i < b - a; i++)
            {
                ListNode *la = new ListNode(0);
                l1->next = la;
                l1 = la;
            }
        }
        // l2=h2;
        //  while(l2!=NULL)
        //  {
        //      cout<<l2->val;
        //        l2=l2->next;
        //  }

        return func(la, h1, h2, 0);
        // return &la;
    }
};