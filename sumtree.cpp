class Solution
{
    public:
    int sum(Node *root)
    {
        if(root == NULL)
            return 0;
        else if(root->right == NULL && root->left == NULL)
            return root->data;
        else
        {
            int l = sum(root->left);
            int r = sum(root->right);
            if(l == -1 || r == -1)
                return -1;
            if(root->data == l + r)
            {
                root->data = root->data + l + r;
                return root->data;
            }
            else if(root->data != r + l)
                return -1;
        }
    }
    bool isSumTree(Node* root)
    {
        // Your code here
        int ans = sum(root);
        if(ans == -1)
            return 0;
        else
            return 1;
    }
};
