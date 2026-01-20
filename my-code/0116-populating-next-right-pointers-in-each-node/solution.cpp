/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void levelorder(Node* root)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
        int levelsize=q.size();
        for(int i=0;i<levelsize;i++)
        {
            if(q.front()->left!=NULL)
           {
            q.push(q.front()->left);
            q.push(q.front()->right);
           }
           if(levelsize-i>1)
           {
            Node* front1=q.front();
            q.pop();
            Node* front2=q.front();
            front1->next=front2;
           }
           else if(levelsize-i==1)
           {
            q.front()->next=NULL;
            q.pop();
           }
        }
        }
        return;
    }
    Node* connect(Node* root) {
        if(root==NULL)
        {
            return root;
        }
        else
        {
            levelorder(root);
            return root;
        }
    }
};
