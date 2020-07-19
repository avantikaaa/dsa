class Solution(object):
    def replaceElements(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        l = len(arr)-1
        max = -1
        arr.append(-1)
        i = l
        while(i>=0):   
            if(arr[i]<max):
                arr[i]=max
            elif (arr[i]>max):
                max = arr[i]
            i -= 1
        arr.pop(0)
        return arr
arr = [17,18,5,4,6,1]
s = Solution()
print s.replaceElements(arr)
