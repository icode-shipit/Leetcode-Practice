/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        {
            return NULL;
        }
        unordered_map<Node*,Node*> m;
        Node* temp=head;
        Node* current = new Node(head->val);
        Node* ans=current;
        if(temp->random==NULL)
        {
            current->random=NULL;
        }
        else if(temp->random==temp)
        {
            current->random=current;
        }
        else
        {
            current->random= new Node(temp->random->val);
            m[temp->random]=current->random;
        }
        m[temp]=current;
        while(temp->next!=NULL)
        {
            // linking already created nodes to a new node in deep copied list
            if(!m.contains(temp->next))
            {
              current->next= new Node(temp->next->val);
              m[temp->next]=current->next;
            }
            else if(m.contains(temp->next))
            {
                current->next=m[temp->next];
            }
            // here we take care of random ptr of next node of current after linking is done
            if(temp->next->random==NULL)
            {
              current->next->random=NULL;
            }
            else if(m.contains(temp->next->random))
            {
               current->next->random=m[temp->next->random];
            }
            else
            {
               current->next->random= new Node(temp->next->random->val);
               m[temp->next->random]=current->next->random;
            }
            temp=temp->next;
            current=current->next;
        }
        return ans;
    }
};
