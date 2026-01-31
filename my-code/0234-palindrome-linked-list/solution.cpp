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
    vector<int> v;
    bool isPalindrome(ListNode* head) {
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        int p1=0;
        int p2=v.size()-1;
        while(p1<p2)
        {
            if(v[p1]!=v[p2])
            {
                return false;
            }
            p1++;
            p2--;
        }
        return true;
    }
};
