class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        
        j = len(citations)-1
        end = j
        while j >= 0:
            if citations[j] > end - j:
                j = j-1
            else:
                break
        return end-j

if __name__ == "__main__":
    s = Solution()
    print s.hIndex([10])