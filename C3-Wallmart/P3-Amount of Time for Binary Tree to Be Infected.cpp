// Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
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
    TreeNode* findTarget(TreeNode* root,int start,unordered_map<TreeNode*, TreeNode*>& parent){
        TreeNode* target=nullptr;
        queue<TreeNode*>q;
        q.push(root);
        parent[root]=nullptr;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==start){
                target=node;
            }               
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            } 
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
        return target;
    }
    int amountOfTime(TreeNode* root, int start) {
        //first make a map with root and their parent
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*, bool> visited;

        TreeNode* target=findTarget(root,start,parent);
        visited[target]=true;
        queue<TreeNode*>q;
        q.push(target);
        int time=0;
        while(!q.empty()){
            int size=q.size();
            bool burned=false;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    visited[node->left]=true;
                    q.push(node->left);
                    burned=true;
                }

                if(node->right && !visited[node->right]){
                    visited[node->right]=true;
                    q.push(node->right);
                    burned=true;
                }

                if(parent[node] && !visited[parent[node]]){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                    burned = true;
                }
            }
            if(burned)time++;
        }
        return time;
    }
};