# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[Optional[TreeNode]]
        """
        if(n==0):
            return []
        memo={}
        def generate(start,end):
            if(start,end) in memo:
                return memo[(start,end)]
            tree=[]
            if(start>end):
                tree.append(None)
                return tree
            for root_val in range(start,end+1):
                left_tree=generate(start,root_val-1)
                right_tree=generate(root_val+1,end)

                for left in left_tree:
                    for right in right_tree:
                        root=TreeNode(root_val,left,right)
                        tree.append(root)
            memo[(start,end)]=tree
            return tree
        return generate(1,n)
            

        