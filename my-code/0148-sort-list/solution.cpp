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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        // Now we have to point slow to null (splitting)
        ListNode* head2=slow->next;
        slow->next=NULL;
        ListNode* leftsplit=sortList(head);
        ListNode* rightsplit=sortList(head2);
        ListNode* newhead; // head of merged list
        ListNode* temp; //used only for linking
        if(leftsplit->val<rightsplit->val)
        {
            temp=leftsplit;
            newhead=leftsplit;
            leftsplit=leftsplit->next;
        }
        else
        {
            temp=rightsplit;
            newhead=rightsplit;
            rightsplit=rightsplit->next;
        }
        while(leftsplit!=NULL || rightsplit!=NULL)
        {
            if(leftsplit!=NULL && rightsplit!=NULL)
            {
               if(leftsplit->val<=rightsplit->val)
            {
                temp->next=leftsplit;
                leftsplit=leftsplit->next;
            }
            else
            {
                temp->next=rightsplit;
                rightsplit=rightsplit->next;
            }
            }
            else if(leftsplit!=NULL)
            {
                temp->next=leftsplit;  
                leftsplit=leftsplit->next;
            }
            else
            {
                temp->next=rightsplit;
                rightsplit=rightsplit->next;
            }
            temp=temp->next;
        }
        return newhead;
    }
};
