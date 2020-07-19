class Solution(object):
    def digits(self, num):
        if(num==0):
            return 0
        return self.digits(num/10)+1
    def findNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        for i in nums:
            if(self.digits(i)%2==0):
                count+=1
        return count
l = [21,123,24,234]
print l
s = Solution()
print s.findNumbers(l)
