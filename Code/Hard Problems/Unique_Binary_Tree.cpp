/*
Unique Binary Tree

Problem statement
Given a pair of tree traversal, return 'true' if a unique binary tree can be constructed otherwise 'false'.



Note:
Each traversal is represented with an integer: preorder - 1, inorder - 2, postorder - 3.   


Example:
For 'a' = 2, ‘b’ = 3.

Answer is True.

It is also possible to construct a unique binary tree. In this case, the postorder traversal provides the root of the tree, and the inorder traversal helps determine the left and right subtrees.



Sample Input 1:
1 2
Sample Output 1:
True 

Explanation of sample output 1:
For 'a' = 1, ‘b’ = 2.

Answer is True.

It is possible to construct a unique binary tree. This is because the preorder traversal provides the root of the tree, and the inorder traversal helps determine the left and right subtrees.
Sample Input 2:
2 2
Sample Output 2:
False
Constraints:
1 <= ‘a’, ‘b’ <= 3
Time Limit: 1 sec
*/


int uniqueBinaryTree(int a, int b){
    // Write your code here.
    if((a==1 && b==3) || (a==3 && b==1)){
        return 0;
    }
    else if(a==b){
        return 0;
    }
    return 1;
}

/*
1. Question link -- https://www.naukri.com/code360/problems/unique-binary-tree_8180906

2. Video link -- https://youtu.be/9GMECGQgWrQ?si=FmZ0TCf7ctoqfKnb
*/