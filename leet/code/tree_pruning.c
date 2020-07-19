/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int postorder(struct TreeNode* node)
{
    int x, y, z;
    if(node!=NULL)
    {
        if((node->left==NULL)&&(node->right==NULL))
        {
            if(node->val==0) return 0;
            if(node->val==1) return 1;
        }
        x=postorder(node->left);
        y=postorder(node->right);
        if(x==0) node->left=NULL;
        if(y==0) node->right=NULL;
        z=x+y+node->val;
        return z;
    }
    return 0;
}

struct TreeNode* pruneTree(struct TreeNode* root){
    postorder(root);
    return root;
}

