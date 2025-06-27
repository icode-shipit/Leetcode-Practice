class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        stack<ListNode*> s;
        ListNode* temp=head;
        s.push(temp);
        while(temp!=NULL)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                return head;
            }
            if(s.top()->val!=temp->val)
            {
            s.pop();
            s.push(temp);
            }
            else
            {
               ListNode* prev=s.top();
               ListNode* current=temp;
               ListNode* after=temp->next;
               // Deletion of Node
               prev->next=after;
            } 
        }
        return head;
    }
};
