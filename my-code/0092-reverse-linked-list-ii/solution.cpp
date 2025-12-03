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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || head->next==NULL || left==right)
        {
            return head;
        }
        if(head->next->next==NULL)
        {
          if(left==1 && right==2)
          {
            ListNode* temp=head->next;
            head->next=NULL;
            temp->next=head;
            return temp;
          }
        }
        int i=1;
        ListNode* temp=head;
        while(left!=1 && i!=left-1)
        {
            temp=temp->next;
            i++;
        }
        ListNode* leftnode=temp;
        ListNode* jusaftleftnode=temp->next;
        ListNode* prev=NULL;
        ListNode* current=leftnode->next;
        ListNode* succ;
        while(i!=right)
        {
          succ=current->next;
          current->next=prev;
          prev=current;
          current=succ;
          i++;
        }
        if(left==1)
        {
            jusaftleftnode->next=leftnode;
            leftnode->next=current;
            // if(current!=NULL)
            // {
            // } 
            return prev;
        }
        if(leftnode!=prev)
        {
          leftnode->next=prev; 
        }
        if(jusaftleftnode!=current)
        {
          jusaftleftnode->next=current;
        }
        return head;
    }
};
