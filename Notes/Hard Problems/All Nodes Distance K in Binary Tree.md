
**[863. All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)**

Given the `root` of a binary tree, the value of a target node `target`, and an integer `k`, return _an array of the values of all nodes that have a distance_ `k` _from the target node._

You can return the answer in **any order**.

**Example 1:**

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png)

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
```

**Example 2:**

```
Input: root = [1], target = 1, k = 3
Output: []
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 500]`.
- `0 <= Node.val <= 500`
- All the values `Node.val` are **unique**.
- `target` is the value of one of the nodes in the tree.
- `0 <= k <= 1000`

***

### Optimized Approach

### Complexity

- Time complexity: O(n)
    
- Space complexity: O(n)
    

#### Algorithm

##### Step 1: Mark Parent Nodes

First, we need to create a mapping of each node to its parent node. This helps us later to move up the tree (towards the root) as well as down (towards the leaves).

1. Start from the root node.
2. Use a queue to perform a level-order traversal (BFS).
3. For each node, if it has a left child, map the left child to the current node (as its parent) and add the left child to the queue.
4. Similarly, if it has a right child, map the right child to the current node (as its parent) and add the right child to the queue.

##### Step 2: Find Nodes at Distance K

Next, we need to find all nodes that are exactly `k` edges away from the target node.

1. Use a queue to perform a BFS starting from the target node.
2. Keep track of visited nodes to avoid revisiting them using a `visited` map.
3. Initialize the distance counter to 0.
4. While the queue is not empty:
    - If the current distance equals `k`, break out of the loop because we've reached the required distance.
    - Otherwise, increment the distance.
    - For each node at the current level, add its unvisited left child, right child, and parent node (using the parent mapping) to the queue and mark them as visited.
5. After reaching the required distance, all nodes left in the queue are exactly `k` distance away from the target node.
6. Collect these nodes' values and return them.

##### Step 3: Combine Both Steps

In the `distanceK` function, we combine the above two steps to get the result.

1. Create a parent mapping by calling `markParents`.
2. Use the `findDistance` function to get all nodes that are `k` distance away from the target node.
3. Return the result obtained from `findDistance`.

#### Example

Consider a binary tree:

```
    1
   / \
  2   3
 / \
4   5
```

Target node is `2` and `k` is `1`.

**Mark Parent Nodes:**

- `2` -> `1`
- `4` -> `2`
- `5` -> `2`
- `3` -> `1`

**Find Distance K:**

- Start BFS from `2`.
- Distance `0`: Node `2`
- Distance `1`: Nodes `1`, `4`, `5` (reachable from `2`)

**Result:**

- Nodes at distance `1` from `2`: `[1, 4, 5]`

---

![WhatsApp Image 2024-05-19 at 20.18.50_0cc7052a.jpg](https://assets.leetcode.com/users/images/33d194a6-52e0-4598-9d7e-c2dcc86ee1f9_1716130148.1606088.jpeg)

![WhatsApp Image 2024-05-19 at 20.18.49_7cc30b89.jpg](https://assets.leetcode.com/users/images/3843bb79-a975-4b3f-a794-e33179278cbe_1716130159.9145403.jpeg)

---

### Code

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
    vector<int> findDistance(TreeNode *target, unordered_map<TreeNode*, TreeNode*> &parentTrack, int k){
        unordered_map<TreeNode*,int> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=1;
        int distance=0;
        while(!q.empty()){
            int sz=q.size();
            if(distance==k){
                break;
            }
            distance++;
            for(int i=0;i<sz;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left!=nullptr && !visited[node->left]){
                    visited[node->left]=1;
                    q.push(node->left);
                }
                if(node->right!=nullptr && !visited[node->right]){
                    visited[node->right]=1;
                    q.push(node->right);
                }
                if(parentTrack[node] && !visited[parentTrack[node]]){
                    visited[parentTrack[node]]=1;
                    q.push(parentTrack[node]);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode *curr=q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;
    }
    void markParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parentTrack){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(node->left!=nullptr){
                parentTrack[node->left]=node;
                q.push(node->left);
            }
            if(node->right!=nullptr){
                parentTrack[node->right]=node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        markParents(root,parentTrack);
        return findDistance(target,parentTrack,k);
    }
};
```

**Important Links**
1. **[Solution Link](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/solutions/5179862/optimized-approach-with-explanation-best-c-solution-beats-100-00-of-users-with-c)**
2. **[Video Link](https://youtu.be/i9ORlEy6EsI?si=K_optysQriHMKIMD)**