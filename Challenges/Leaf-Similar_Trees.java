/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List <Integer> l1 = new ArrayList<>();
        List <Integer> l2 = new ArrayList<>();

        dfs(root1, l1);
        dfs(root2, l2);
        return l1.equals(l2);

    }
    void dfs(TreeNode node, List<Integer>leaves)
    {
        if(node == null)
        {
            return;
        }
        if(node.left == null && node.right == null)
        {
            leaves.add(node.val);
            return;
        }
        //if the node is not the null node i.e it has some nodes in left or/and right
        dfs(node.left, leaves);
        dfs(node.right, leaves);
        
    }
}
