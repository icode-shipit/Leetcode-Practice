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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* current1=l1;
        ListNode* current2=l2;
        int carry=0;
        // just for storing the first value in new LL
        ListNode* newhead= new ListNode((current1->val+current2->val)%10);
        carry=(current1->val+current2->val)/10;
        current1=current1->next;
        current2=current2->next;
        ListNode* newcurrent=newhead;
        while(current1!=NULL || current2!=NULL)
        {
            int n1,n2=0;
            if(current1!=NULL && current2==NULL)
            {
                n2=0;
                n1=current1->val;
               if((n1+n2+carry)>9)
               {
                 newcurrent->next= new ListNode((n1+n2+carry)%10);
                 carry=(n1+n2+carry)/10;
                 newcurrent=newcurrent->next;
               }
               else
               {
                newcurrent->next= new ListNode((n1+n2+carry));
                carry=0;
                newcurrent=newcurrent->next;
               }
               current1=current1->next;
            }
            else if(current1==NULL && current2!=NULL)
            {
                n2=current2->val;
                n1=0;
               if((n1+n2+carry)>9)
               {
                 newcurrent->next= new ListNode((n1+n2+carry)%10);
                 carry=(n1+n2+carry)/10;
                 newcurrent=newcurrent->next;
               }
               else
               {
                newcurrent->next= new ListNode((n1+n2+carry));
                carry=0;
                newcurrent=newcurrent->next;
               }
               current2=current2->next;
            }
            else if(current1!=NULL && current2!=NULL)
            {
                n1=current1->val;
                n2=current2->val;
                if((n1+n2+carry)>9)
                {
                   newcurrent->next= new ListNode((n1+n2+carry)%10);
                   carry=(n1+n2+carry)/10;
                   newcurrent=newcurrent->next;
                }
                else
                {
                    newcurrent->next= new ListNode((n1+n2+carry));
                    carry=0;
                    newcurrent=newcurrent->next;
                }
            current1=current1->next;
            current2=current2->next;
            }
        }
        if(carry!=0)
        {
            newcurrent->next= new ListNode(carry);
        }
        return newhead;
    }
};
