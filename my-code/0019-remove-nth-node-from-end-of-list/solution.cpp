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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // first counting the total no of nodes in the list
        ListNode* temp=head;
        int total=0;
        while(temp!=nullptr)
        {
            temp=temp->next;
            total++;
        }
        if(total==0)
        {
            return head;
        }
        else if(total==1)
        {
            delete head;
            return nullptr;
        }
        else if(total==2)
        {
            if(n==1)
            {
                ListNode* temp=head->next;
                head->next=nullptr;
                delete temp;
                return head;
            }
            else
            {
                ListNode* temp=head->next;
                head->next=nullptr;
                delete head;
                head=temp;
                return head;
            }
        }
        else 
        {
            if(total==n)
            {
                ListNode* temp = head->next;
                head->next=nullptr;
                delete head;
                head=temp;
                return head;
            }
        else
        {
        int i=total-n-1;
        int j=0;
        ListNode* tempp=head;
        while(j<i)
        {
            tempp=tempp->next;
            j++;
        }
        temp=tempp->next;
        tempp->next=temp->next;
        temp->next=nullptr;
        delete temp;
        return head;
        }
        return {};
        }
    }
};
