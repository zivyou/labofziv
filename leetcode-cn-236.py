# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def search(self, root, p, re, found):
        if root == None:
            return
        re.append(root)
        if root == p:
            found[0] = True
            return

        if root.left != None and found[0] == False:
            self.search(root.left, p, re, found)
        
        if not found[0]:
            while re[len(re)-1] != root:
                re.pop()

        if root.right != None and found[0] == False:
            self.search(root.right, p, re, found)

        if not found[0]:
            while re[len(re)-1] != root:
                re.pop()
            

    def path(self,  root, p):
        re = []
        found = [False]
        self.search(root, p, re, found)

        if found[0] == True:
            return re
        else:
            return []

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        re = None
        re1 = []
        re2 = []
        re1 = self.path(root, p)
        re2 = self.path(root, q)
        

        for i in range(min(len(re1), len(re2))):
            if re1[i] == re2[i]:
                re = re1[i]
            else:
                break
        return re
        
if __name__ == "__main__":
    root = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left.left = TreeNode(6)
    root.left.right = TreeNode(2)
    root.left.right.left = TreeNode(7)
    root.left.right.right = TreeNode(4)
    root.right.left = TreeNode(0)
    root.right.right = TreeNode(8)
    s = Solution()
    re = s.lowestCommonAncestor(root, root.left, root.left.right.right)
    print "result: ", re.val