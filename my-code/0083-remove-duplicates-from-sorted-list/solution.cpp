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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
        {
            return head;
        }
        else
        {
       ListNode* temp1=head;
       ListNode* temp2=head->next;
       while(temp2!=nullptr)
       {
       if(temp1->val==temp2->val) //condition checking in iteration
       {
        ListNode* tempp=temp2;
        temp2=temp2->next;
        temp1->next=tempp->next;
        tempp->next=nullptr;
        delete tempp;
       }
    else
    {
        // updating positions
       temp1=temp1->next;
       temp2=temp2->next;
    }
       }
       return head;
        }
    }
};
