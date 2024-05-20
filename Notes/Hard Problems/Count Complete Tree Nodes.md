
**[Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/description/)**

Given the `root` of a **complete** binary tree, return the number of the nodes in the tree.

According to **[Wikipedia](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)**, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between `1` and `2h` nodes inclusive at the last level `h`.

Design an algorithm that runs in less than `O(n)` time complexity.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/01/14/complete.jpg)

```
Input: root = [1,2,3,4,5,6]
Output: 6
```

**Example 2:**

```
Input: root = []
Output: 0
```

**Example 3:**

```
Input: root = [1]
Output: 1
```
**Constraints:**

- The number of nodes in the tree is in the range `[0, 5 * 104]`.
- `0 <= Node.val <= 5 * 104`
- The tree is guaranteed to be **complete**.


*** 

### Brute Force Approach

### Complexity

- Time complexity: O(n)
    
- Space complexity: O(h)
    

where n: number of nodes in the binary tree and h: height of the tree

#### Algorithm:

**Step 1:** Start by initializing a variable to count (initial value 0) the number of nodes in the binary tree

**Step 2:** Define a recursive inorder function:

Base Case: If the current node is null, return from the void function.

Recursive Call: If the current node is not null, call the function for its left child.

1. Increment the counter by 1 for each node.
2. Recursively call the function on the right child of the current node as well.

**Step 3:** Start the inorder traversal from the root of the Binary Tree by calling the recursive function on the root node with initial count to 0.

![image.png](https://assets.leetcode.com/users/images/0ca4e800-0e24-4835-8a2c-cd01af597d24_1713088523.3111997.png)

**Step 4:** Return the final value of the count variable after the traversal representing the total number of nodes.

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

// Brute Force Approach
// Time complexity -> O(n) and Space -> O(h)
// where n: number of nodes in the binary tree and h: height of the tree
class Solution {
    int traversal(TreeNode* root, int &count){

        // Base case: If the current node is NULL, return
        if(root==nullptr){
            return 0;
        }
        // Increment count for the current node
        count++;

        // Recursively call inorder on the left subtree
        traversal(root->left,count);

        // Recursively call inorder on the right subtree
        traversal(root->right,count);
        return count;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int count=0;
        return traversal(root,count);
    }
};
```

### Optimized Approach

### Complexity

- Time complexity: O((logn)2)
    
- Space complexity: O(logn)
    

where n: number of nodes in the binary tree

![image.png](https://assets.leetcode.com/users/images/aa485ce1-1bf0-4c31-93d3-53d0d39967fb_1713088649.533548.png)

- If the left height equals right height, it indicates that the last level is completely filled.
- If the left height does not equal right height, the last level is not completely filled.

#### Algorithm:

**Step 1: Base Case** If the given node is null, we return 0 as there are no nodes to count.

**Step 2: Recursive Calls:** Recursively find the left height and right height of the Binary Tree.

**Step 3: Comparison:** If the left height is equal to the right height implies that the tree’s last level is completely filled. Return the count of nodes using the formula: return (1 << lh) - 1, where << represents the left shift operator and represents the power of 2.

![image.png](https://assets.leetcode.com/users/images/6d142947-6fa3-41e4-83bf-a0888edf6620_1713088705.420259.png)

**Step 4:** If the left height is not equal to the right height implies that the tree’s last level is not completely filled. Recursively call the function to the left and right subtree and return the final number of nodes as 1 + countNodes(root->left) + countNodes(root->right)

**Step 5:** Implement the find left height and right height functions.

1. Start with the variable height set to 0.
2. Use a while loop to traverse the left/right side of the tree incrementing the height until reaching a leaf node.
3. Return the calculated height.

![image.png](https://assets.leetcode.com/users/images/9be00c00-df61-41c3-8637-94313b10c4f3_1713088711.9918146.png)

![WhatsApp Image 2024-04-14 at 15.41.27_c6f24d42.jpg](https://assets.leetcode.com/users/images/1c63b51e-c9d5-45e2-8e03-60c0293a4b47_1713089726.3810508.jpeg)

  

![WhatsApp Image 2024-04-14 at 15.41.26_31b3acfc.jpg](https://assets.leetcode.com/users/images/e42b081c-7bbf-4ee9-87bc-bacbc496306a_1713089718.6621974.jpeg)

### Code

```cpp
// Optimized Approach
// Time complexity -> O((logn)^2) and Space -> O(logn)
// where n: number of nodes in the binary tree
class Solution {
    int findHeightLeft(TreeNode* root){
        int height=0;
        while(root!=nullptr){
            height++;
            root=root->left;
        }
        return height;
    }
    int findHeightRight(TreeNode* root){
        int height=0;
        while(root!=nullptr){
            height++;
            root=root->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {

        // Base case: If the root is NULL, there are no nodes
        if(root==nullptr){
            return 0;
        }
        // Find the left height of the tree
        int lh=findHeightLeft(root);
        // Find the right height of the tree
        int rh=findHeightRight(root);

        // Check if the last level is completely filled
        if(lh==rh){

            // If so, use the formula for total nodes in a perfect
            // binary tree ie. 2^h - 1
            return (1<<lh)-1;
            // OR
            // return pow(2,lh)-1;
        }

        // If the last level is not completely filled, recursively count 
        // nodes in left and right subtrees
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
```

**Important Link **
1. **[Video Link](https://youtu.be/u-yWemKGWO0)**
2.  **[Solution Link](https://leetcode.com/problems/count-complete-tree-nodes/solutions/5021572/2-approach-best-c-solution-brute-force-and-optimized-approach-with-explanation)**
3. **[For Detailed Solution](https://takeuforward.org/binary-tree/count-number-of-nodes-in-a-binary-tree/)**
