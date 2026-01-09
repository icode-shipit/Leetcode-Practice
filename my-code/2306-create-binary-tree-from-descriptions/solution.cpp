class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto &d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];

            if (!nodes.count(parent))
                nodes[parent] = new TreeNode(parent);
            if (!nodes.count(child))
                nodes[child] = new TreeNode(child);

            if (isLeft)
                nodes[parent]->left = nodes[child];
            else
                nodes[parent]->right = nodes[child];

            children.insert(child);
        }

        // root = node which is never a child
        for (auto &p : nodes) {
            if (!children.count(p.first))
                return p.second;
        }
        return nullptr;
    }
};

