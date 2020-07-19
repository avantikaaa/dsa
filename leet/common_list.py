class Solution(object):
    def check(self, nums1, nums2):
        out = []
        for i in nums1:
            if i in nums2:
            	if i not in out:
	                out.append(i)
        	        nums2.remove(i)
        return out
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        l1 = len(nums1)
        l2 = len(nums2)
        if(l1<l2):
            return self.check(nums1, nums2)
        return self.check(nums2, nums1)
l1 = [1,2,2,1]
l2 = [2]
s = Solution()
print s.intersect(l1, l2)
