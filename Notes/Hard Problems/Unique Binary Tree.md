
**[Unique Binary Tree](https://www.naukri.com/code360/problems/unique-binary-tree_8180906)**

##### Problem statement

Given a pair of tree traversal, return _**'true'**_ if a unique binary tree can be constructed otherwise _**'false'**_.

**Note:**

```
Each traversal is represented with an integer: preorder - 1, inorder - 2, postorder - 3.   
```
  

**Example:**

```
For 'a' = 2, ‘b’ = 3.

Answer is True.

It is also possible to construct a unique binary tree. In this case, the postorder traversal provides the root of the tree, and the inorder traversal helps determine the left and right subtrees.
```

Detailed explanation ( Input/output format, Notes, Images )

-  **Input format:** The first line contains two integers 'a' and 'b', representing the type of tree traversal.
- **Output Format:** "True" will be printed if the answer returned is 'true' else "False" will be printed.
- **Note:** You don't need to print anything, it has already been taken care of, just complete the given function.

**Sample Input 1:**

```
1 2
```

**Sample Output 1:**

```
True 
```

**Explanation of sample output 1:**

```
For 'a' = 1, ‘b’ = 2.

Answer is True.

It is possible to construct a unique binary tree. This is because the preorder traversal provides the root of the tree, and the inorder traversal helps determine the left and right subtrees.
```

**Sample Input 2:**

```
2 2
```

**Sample Output 2:**

```
False
```

**Constraints:**

```
1 <= ‘a’, ‘b’ <= 3
Time Limit: 1 sec
```

***

###  Optimized Approach

### Complexity

- Time complexity: O(1)
    
- Space complexity: O(1)
    
### Code

```cpp
int uniqueBinaryTree(int a, int b){
    // Write your code here.
    if((a==1 && b==3) || (a==3 && b==1)){
        return 0;
    }
    else if(a==b){
        return 0;
    }
    return 1;
}
```



**Important Link**
1. **[Video Link](https://youtu.be/9GMECGQgWrQ?si=FmZ0TCf7ctoqfKnb)**

