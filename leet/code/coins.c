////online solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int myDistCoins(struct TreeNode* root, int* moves) {
    int lmoves = 0, rmoves = 0; 
    if (!root)
        return 0;
    
    lmoves = myDistCoins(root->left, moves);
    rmoves = myDistCoins(root->right, moves);
    *moves += abs(lmoves) + abs(rmoves);
    
    return (root->val + lmoves + rmoves - 1);
}

int distributeCoins(struct TreeNode* root){
    int moves = 0;

    myDistCoins(root, &moves);
    
    return moves;
}


////solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int ab(int x)
{
    if(x>=0)
        return x;
    else
        return (-x);
}

int* postorder(struct TreeNode* node, int* count)
{
    int* arr=(int *)malloc(2*sizeof(int)); arr[0]=0; arr[1]=0;
    int* x;
    int* y;
    if(node!=NULL)
    {
        if((node->left==NULL)&&(node->right==NULL))
        {
            arr[0]=node->val;
            arr[1]=1;
            (*count)+=ab(arr[0]-arr[1]);
            return arr;
        }
        x=postorder(node->left, count);
        y=postorder(node->right, count);
        arr[0]=x[0]+y[0]+node->val;
        arr[1]=x[1]+y[1]+1;
        (*count)+=ab(arr[0]-arr[1]);
        return arr;
    }
    return arr;
}

int distributeCoins(struct TreeNode* root)
{
    int count=0;
    postorder(root, &count);
    return count;
}


