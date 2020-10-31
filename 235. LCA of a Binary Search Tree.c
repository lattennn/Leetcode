//Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

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

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL)
        return NULL;
    if(root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right,p,q);
    if(root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left,p,q);
    return root;
}
