/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    int minDepth(TreeNode* root) {
        
        if (root==nullptr) return 0;
        
        queue<TreeNode> q = new LinkedList<>(); 
        int step = 1;
        
        q.offer(root);
        while(!q.isEmpty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode node = q.poll();
                if(node->left==nullptr&&node->right==nullptr){
                    return step;
                }
                if(node->left!=nullptr)
                    q.offer(node->left);
                if(node->right!=nullptr)    
                    q.offer(node->right);
            }
            step++;
        }
        
    }
};
