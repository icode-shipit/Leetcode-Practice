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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy= new ListNode();
        ListNode* temp1=dummy;
        int temp=0;
        while(head!=NULL)
        {
            if(head->val!=0)
            {
                temp+=head->val;
                head=head->next;
            }
            else
            {
                if(temp!=0)
                {
                ListNode* newnode= new ListNode(temp);
                temp1->next=newnode;
                temp1=temp1->next;
                temp=0;
                }
                head=head->next;
            }
        }
        return dummy->next;
    }
};
