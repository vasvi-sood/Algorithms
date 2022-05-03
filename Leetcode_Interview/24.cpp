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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return head;
        
        ListNode* dummy=new ListNode();
        dummy->next=head;
        head=dummy;
  auto node1=dummy,node2=dummy->next,node3=node2->next;
        while(node1!=NULL && node1->next!=NULL && node1->next->next!=NULL)
        {
            node2=node1->next,node3=node2->next;
            node2->next=node3->next;
            node1->next=node3;
            node3->next=node2;
            node1=node2;
            // node1=node2;
            // node2=node3;
            // node3=node3->next;
                
        }
        
        return head->next;
    }
};