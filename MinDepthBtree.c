
//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root){
    int l,r;
    
    if(root==NULL)
        return 0;
    
    l=minDepth(root->left);
    r=minDepth(root->right);
    
    if( (l<r && l!=0) || r==0 )
        return 1+l;
    else
        return 1+r;
    //return 1 + (l<r)?l:r ;
    
}
