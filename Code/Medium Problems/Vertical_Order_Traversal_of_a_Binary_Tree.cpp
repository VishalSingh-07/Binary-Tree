/*
987. Vertical Order Traveral of a Binary Tree

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.



Example 2:

Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.



Example 3:

Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000

*/
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

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(n)
// where n: number of nodes in a binary tree
/*
Remember :
1. For left child -> {vertical-1,level+1}
2. For right child -> {vertical+1,level+1}

// where vertical: columns and level: rows


    This int is for storing verticals
     ^
     |
map<int,map<int,multiset<int>>> mpp:

    
        This int is for level 
         ^
         |
    map<int,multiset<int>>
                |
                This multiset is used for multinode on same level as well as same vertical
   
*/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>> ans;
            if(root==nullptr){
                return ans;
            }
            map<int,map<int,multiset<int>>> mpp;
            queue<pair<TreeNode*,pair<int,int>>> q;
            q.push({root,{0,0}}); // q.push({root,{verticals,levels}})
            while(!q.empty()){
                  auto it=q.front();
                  q.pop();
                  TreeNode* node=it.first;
                  int vertical=it.second.first,level=it.second.second;
                  mpp[vertical][level].insert(node->val);
                  if(node->left!=nullptr){
                        q.push({node->left,{vertical-1,level+1}});
                  }
                  if(node->right!=nullptr){
                        q.push({node->right,{vertical+1,level+1}});
                  }
            }
            // where p.first=int and p.second=map<int,multiset<int>>
            for(auto p: mpp){
                  vector<int> col;
                  for(auto q: p.second){
                        // q.first -> int and q.second -> multiset<int>
                        col.insert(col.end(),q.second.begin(),q.second.end());
                  }
                  ans.push_back(col);
            }
            return ans; 
      }
};

/*
1. Question link -- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

2. Solution Link -- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/solutions/4876004/beats-100-00-of-users-with-c-easy-c-solution-optimized-approach-with-explanation

3. Video Link -- https://youtu.be/q_a6lpbKJdw
*/