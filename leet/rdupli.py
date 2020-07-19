def dupli(nums):
	print nums
	print type(nums)
        out = []
        out.append(nums[0])
        prev = nums[0]
        for i in nums:
        	print i,
        print
        print out
        for i in nums:
            if(i!=prev):
                out.append(i)
            prev = i
	nums = []
        nums = [i for i in out]
        print out
        print nums
        return len(nums)
        
nums = raw_input()
print dupli(nums)
print nums
