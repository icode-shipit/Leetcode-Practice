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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL )
        {
            return list2;
        }
        else if(list2==NULL)
        {
            return list1;
        }
        ListNode* p1=list1;
        ListNode* p2=list2;
        vector<ListNode*> v;
        while(p1!=NULL || p2!=NULL)
        {
          if(p1!=NULL && p2!=NULL)
          {
            if(p1->val <=p2->val)
            {
                v.push_back(p1);
                p1=p1->next;
            }
            else if(p1->val >p2->val)
            {
                v.push_back(p2);
                p2=p2->next;
            }
          }
          else if(p1!=NULL && p2==NULL)
          {
            v.push_back(p1);
                p1=p1->next;
          }
          else 
          {
            v.push_back(p2);
            p2=p2->next;
          }
        }

        int i=0;
        while(i<v.size())
        {
            if(i==v.size()-1)
            {
                v[i]->next=NULL;
                break;
            }
            v[i]->next=v[i+1];
            i++;
        }
        return v[0];
    }
};
