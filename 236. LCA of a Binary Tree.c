

//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

//“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 

//(where we allow a node to be a descendant of itself).”


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int find(struct TreeNode* root,struct TreeNode* p,struct TreeNode* q){
    int l,r;
    if(root==NULL)
        return 0;
    l=find(root->left,p,q);
    r=find(root->right,p,q);
    if(root->val==p->val ||root->val==q->val)
        return l+r+1;
    return l+r;
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *l,*r;

    if(root==NULL)
        return NULL;

    l=lowestCommonAncestor(root->left,p,q);
    r=lowestCommonAncestor(root->right,p,q);
    if(l==NULL && r==NULL){
        if(find(root,p,q)==2)
            return root;
        else
            return NULL;
    }
    return (l!=NULL)?l:r;
}
