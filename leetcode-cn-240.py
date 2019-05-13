class Solution(object):
    def searchList(self, l, target):
        left = 0
        right = len(l)-1
        while left <= right:
            mid = (left+right)/2
            if l[mid] == target:
                return True
            elif l[mid] < target:
                left = mid+1
            else:
                right = mid-1

        return False

    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        height = len(matrix)
        if height <= 0:
            return False
        width = len(matrix[0])
        if width <= 0:
            return False
        for i in range(height):
            l = matrix[i]
            if l[0] <= target and target <= l[width-1]:
                re = self.searchList(l, target)
                if re:
                    return True
        return False
if __name__ == "__main__":
    matrix = [[1,   4,  7, 11, 15],[2,   5,  8, 12, 19],[3,   6,  9, 16, 22],[10, 13, 14, 17, 24],[18, 21, 23, 26, 30]]
    
    s = Solution()
    print s.searchList(matrix[0], 2)
    print s.searchMatrix(matrix, 15)

    pass