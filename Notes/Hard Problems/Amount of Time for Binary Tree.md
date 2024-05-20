
**[2385. Amount of Time for Binary Tree to Be Infected](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/)**


You are given the `root` of a binary tree with **unique** values, and an integer `start`. At minute `0`, an **infection** starts from the node with value `start`.

Each minute, a node becomes infected if:

- The node is currently uninfected.
- The node is adjacent to an infected node.

Return _the number of minutes needed for the entire tree to be infected._

**Example 1:**

![](https://assets.leetcode.com/uploads/2022/06/25/image-20220625231744-1.png)

```
Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2022/06/25/image-20220625231812-2.png)

```
Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 105]`.
- `1 <= Node.val <= 105`
- Each node has a **unique** value.
- A node with a value of `start` exists in the tree.

***
### Optimized Approach

### Complexity

- Time complexity: O(n)
    
- Space complexity: O(n)
    

#### Algorithm

1. **Marking Parents:**
    
    - We start by defining a function `markParents` which marks the parent of each node in the binary tree.
    - It takes the root of the binary tree and a map `mpp` which will store the parent of each node.
    - We initialize a queue `q` and push the root into it.
    - Then we iterate through the queue until it's empty:
        - Pop a node from the queue.
        - If the popped node's value matches the `start` value we're looking for, we save this node as the result.
        - If the node has a left child, we mark its parent as the current node and push the left child into the queue.
        - If the node has a right child, we do the same as above for the right child.
2. **Finding Maximum Distance:**
    
    - We define a function `findMaxDistance` which calculates the maximum distance from the given target node to all other nodes in the tree.
    - It takes a map `mpp` containing the parent-child relationships and the target node.
    - We initialize a queue `q` and push the target node into it.
    - We also initialize a map `visited` to keep track of visited nodes and mark the target node as visited.
    - We initialize a variable `maxi` to keep track of the maximum distance.
    - While the queue is not empty, we iterate through it:
        - At each level of the tree, we keep track of whether we encounter any new nodes.
        - For each node popped from the queue, we check if it has a left child, right child, or parent (using the `mpp` map) that has not been visited. If so, we mark it as visited and push it into the queue.
        - If during this iteration, we encounter any new nodes, we increment `maxi`.
    - Finally, we return `maxi`, which represents the maximum distance from the target node to all other nodes in the tree.
3. **Main Function:**
    
    - In the `amountOfTime` function:
        - We create a map `mpp` to store parent-child relationships.
        - We find the target node using the `markParents` function.
        - We calculate the maximum distance from the target node to all other nodes using the `findMaxDistance` function.
        - Finally, we return this maximum distance.

![WhatsApp Image 2024-05-19 at 21.15.38_f1405fe1.jpg](https://assets.leetcode.com/users/images/e8a75da0-bcc7-48e4-87f1-fbc0da749fc6_1716133565.9489985.jpeg)

![WhatsApp Image 2024-05-19 at 21.15.39_f264ee61.jpg](https://assets.leetcode.com/users/images/3230d9a8-027c-46ba-925e-f0d3b0c7e51d_1716133553.304412.jpeg)

### Code

```cpp
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
// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
    int findMaxDistance(map<TreeNode*,TreeNode*> &mpp, TreeNode *target){
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, int> visited;
        visited[target]=1;
        int maxi=0;
        while(!q.empty()){
            int sz=q.size();
            int fl=0;
            for(int i=0;i<sz;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left!=nullptr && !visited[node->left]){
                    fl=1;
                    visited[node->left]=1;
                    q.push(node->left);
                }
                if(node->right!=nullptr && !visited[node->right]){
                    fl=1;
                    visited[node->right]=1;
                    q.push(node->right);
                }
                if(mpp[node] && !visited[mpp[node]]){
                    fl=1;
                    visited[mpp[node]]=1;
                    q.push(mpp[node]);
                }
            }
            if(fl==1){
                maxi++;
            }
        }
        return maxi;
    }
    TreeNode* markParents(TreeNode* root, map<TreeNode*,TreeNode*> &mpp, int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *res;
        while(!q.empty()){
            TreeNode *node=q.front();
            if(node->val==start){
                res=node;
            }
            q.pop();
            if(node->left!=nullptr){
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right!=nullptr){
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> mpp;
        TreeNode* target=markParents(root,mpp,start);
        int maxi=findMaxDistance(mpp,target);
        return maxi;
    }
};
```

**Important Link**
1. **[Solution Link](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/solutions/5180113/optimized-approach-with-explanation-best-c-solution-striver-solution)**
2. **[Video Link](https://youtu.be/2r5wLmQfD6g?si=W6cVfCVZJT0j3cmS)**