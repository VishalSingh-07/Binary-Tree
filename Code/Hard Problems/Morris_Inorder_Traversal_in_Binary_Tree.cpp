#include <bits/stdc++.h>
using namespace std;
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

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Optimized Approach [Morris Traversal]
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode *curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode *prev=curr->left;
                while(prev->right!=nullptr && prev->right !=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};


/*
1. Question Link -- https://leetcode.com/problems/binary-tree-inorder-traversal/

2. Solution Link -- https://leetcode.com/problems/binary-tree-inorder-traversal/solutions/4381728/3-approach-best-c-solution-brute-force-better-and-optimized-approach

3. Video link -- https://youtu.be/80Zug6D1_r4?si=r50k4rbrbJwsHLss
*/