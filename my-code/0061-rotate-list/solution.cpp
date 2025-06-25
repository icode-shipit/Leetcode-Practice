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
ListNode* rotateonce(ListNode* head)
    {
        ListNode* temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        ListNode* tempe=temp->next;
        //linking part
        tempe->next=head;
        temp->next=NULL;
        //assigning new head
        head=tempe;
        return head;
    }
    int lengthofLL(ListNode* head)
    {
      int i=1;
      ListNode* temp=head;
      if(head==NULL)
      {
        return 0;
      }
      while(temp->next!=NULL)
      {
        temp=temp->next;
        i++;
      }
      return i;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
        {
            return NULL;
        }
        int n=lengthofLL(head);
        int newheadp=k%n;
        for(int i=0;i<newheadp;i++)
        {
          head=rotateonce(head);  
        }
        return head;
    }
};
