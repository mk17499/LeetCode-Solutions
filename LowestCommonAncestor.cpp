class Solution
{
    public:
    Node* point(Node *root,int target)
    {
        if(root == NULL)
            return NULL;
        else 
        {
            if(root->data == target)
                return root;
            else
            {
                Node * left = point(root->left,target);
                Node * right = point(root->right,target);
                if(left == NULL && right!=NULL)
                    return right;
                else if(left!=NULL && right == NULL)
                    return left;
                else 
                    return NULL;
            }
        }
    }
    void find(Node *root,vector<int> &v, int target,int *sign)
    {
        if(root == NULL)
            return ;
        else
        {
            v.push_back(root->data);
            if(root->data == target)
            {
                *sign = 1;
                return;
            }
            else
            {
                if(!root->left && !root->right)
                {
                    v.pop_back();
                    return;
                }
                else
                {
                    find(root->left,v,target,sign);
                    if(*sign == 1)
                        return;
                    find(root->right,v,target,sign);
                    if(*sign == 1)
                        return;
                    else
                    {
                        v.pop_back();
                        return;
                    }
                }
            }
        }
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       vector<int> x;
       vector<int> y;
       int s1 = 0,s2 = 0;
       int *p = &s1,*q = &s2;
       
       find(root,x,n1,p);
       find(root,y,n2,q);
       
       int ans;
       if(x.size() == 0 || y.size() == 0)
            return NULL;
            
       int flag = 0;
       for(int i = 0;i<min(x.size(),y.size());i++)
       {
            if(x[i]!=y[i])
            {
                flag = 1;
                ans = x[i-1];
                break;
            }
       }
        if(flag == 0)
            ans = x[min(x.size(),y.size())-1];
        
        Node *r = point(root,ans);
        return r;
    }
};
