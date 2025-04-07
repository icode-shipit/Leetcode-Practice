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
            int i=0;
            ListNode* temphead;
            ListNode* current=head;
            ListNode* prev=nullptr;
            ListNode* next=current->next;
            while(current!=nullptr && next!=nullptr)
            {
                current->next=next->next; //linking
                next->next=current;
                if(prev!=nullptr)
                {
                    prev->next=next;
                }
                    if(i==0)
                    {
                        temphead=next;
                    }
                    // updating positions
                    prev=current;
                    current=current->next;
                    if(current!=nullptr)
                    {
                        next=current->next;
                    }
                        i++;
            }
            return temphead;
        }
    }
};
