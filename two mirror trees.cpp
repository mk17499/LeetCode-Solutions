class Solution
{
    int height(Node* node)
    {
        if (node == NULL)
            return 0;
        else {
            /* compute the height of each subtree */
            int lheight = height(node->left);
            int rheight = height(node->right);
 
            /* use the larger one */
            if (lheight > rheight) {
                return (lheight + 1);
            }
            else {
                return (rheight + 1);
            }
        }
    }
    void traverse_left(Node* root,vector<int> &v)
    {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
            printCurrentLevelLeft(root, i,v);
    }
    void printCurrentLevelLeft(Node* root, int level,vector<int> &v)
    {
        if (root == NULL)
        {
            v.push_back(-1);
            return;
        }
        if (level == 1)
            v.push_back(root->data);
        else if (level > 1)
        {
            printCurrentLevelLeft(root->left, level - 1,v);
            printCurrentLevelLeft(root->right, level - 1,v);
        }
    }
    void traverse_right(Node* root,vector<int> &v)
    {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
            printCurrentLevelRight(root, i,v);
    }
    void printCurrentLevelRight(Node* root, int level,vector<int> &v)
    {
        if (root == NULL)
        {
            v.push_back(-1);
            return;
        }
        if (level == 1)
            v.push_back(root->data);
        else if (level > 1)
        {
            printCurrentLevelRight(root->right, level - 1,v);
            printCurrentLevelRight(root->left, level - 1,v);
        }
    }
    
    public:
    int areMirror(Node* a, Node* b) 
    {
        // Your code here
        vector<int> left;
        vector<int> right;
        
        traverse_left(a,left);
        traverse_right(b,right);
        
        
        if(left.size()!=right.size())
            return 0;
        else
        {
            for(int i = 0;i<left.size();i++)
                if(left[i] != right[i])
                    return 0;
            return 1;
        }
    }

};
