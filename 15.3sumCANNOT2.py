
#exceed time limit
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        res=[]
        if len(nums)<3:
            return res
        
        nums.sort()
        for i in range(len(nums)-2):
            
            l=i+1
            r=len(nums)-1

            while(l<r):
                if (nums[l]+nums[r]+nums[i]) == 0:
                    tmp = [nums[l],nums[r],nums[i]]
                    tmp.sort()
                    if tmp not in res:
                        res.append(tmp)

                elif (nums[l]+nums[r]) > -nums[i]:
                    r-=1
                else:
                    l+=1
                    
        return res
