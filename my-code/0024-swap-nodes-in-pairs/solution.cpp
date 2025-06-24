class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)
        {
            return head;
        }
        else if(head!=nullptr && head->next==nullptr)
        {
            return head;
        }
        else 
        {
            ListNode* prev=NULL;
            ListNode* temp=head;
            ListNode* temp1;
            while(temp->next!=NULL)
            {
               temp1=temp->next;
               temp->next=temp1->next;
               temp1->next=temp;
               if(prev!=NULL)
               {
               prev->next=temp1;
               }
               if(prev==NULL)
               {
               head=temp1; 
               }
               prev=temp;
               temp=temp->next;   
               if(temp==NULL)
               {
                break;
               }
            }
        }
        return head;
    }
};
