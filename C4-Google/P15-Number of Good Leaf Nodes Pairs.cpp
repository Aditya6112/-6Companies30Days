// Link: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/
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
    void makeGraph(TreeNode* root,TreeNode* parent,unordered_map<TreeNode*,vector<TreeNode*>>& adj,unordered_set<TreeNode*>& leaves){
        if(root==NULL)return;
        if(!root->left && !root->right){
            leaves.insert(root);
        }
        if(parent!=NULL){
            adj[root].push_back(parent);
            adj[parent].push_back(root);
        }
        makeGraph(root->left,root,adj,leaves);
        makeGraph(root->right,root,adj,leaves);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,vector<TreeNode*>>adj;
        unordered_set<TreeNode*>leaves;
        TreeNode* parent=NULL;
        makeGraph(root,parent,adj,leaves);

        //do bfs on each leaf node and if distance is less than or equal from another leaf node then count++;
        int count=0;
        for(auto& leaf:leaves){
            queue<TreeNode*>q;
            unordered_set<TreeNode*>visited;
            q.push(leaf);
            visited.insert(leaf);
            for(int lvl=0;lvl<=distance;lvl++){
                int size=q.size();
                while(size--){
                    TreeNode* front=q.front();
                    q.pop();
                    if(front!=leaf && leaves.count(front)){
                        count++;
                    }
                    for(auto nbr: adj[front]){
                        if(!visited.count(nbr)){
                            q.push(nbr);
                            visited.insert(nbr);
                        }
                    }
                }
            }
        }
        return count/2;
    }
};