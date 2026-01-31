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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* p2=head;
        for(int i=1;i<k;i++)
        {
            temp=temp->next;
        }
        ListNode* p1=temp;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            p2=p2->next;
        }
        int a=p2->val;
        p2->val=p1->val;
        p1->val=a;
        return head;

    }
};
