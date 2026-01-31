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
        if(head->next==NULL && n==1)
        {
            return NULL;
        }
        ListNode* dummy= new ListNode();
        dummy->next=head;
        ListNode* p1=dummy;
        ListNode* p2=head;
        for(int i=1;i<=n;i++)
        {
           p2=p2->next;
        }
        while(p2!=NULL)
        {
           p1=p1->next;
           p2=p2->next;
        }
        p1->next=p1->next->next;
        return dummy->next;
    }
};
