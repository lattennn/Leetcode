#Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

#Note:

#The solution set must not contain duplicate triplets.

#Example:

#Given array nums = [-1, 0, 1, 2, -1, -4],

#A solution set is:
#[
#  [-1, 0, 1],
#  [-1, -1, 2]
#]


class Solution:
    def threeSum(self, nums): #: List[int]):# -> List[List[int]]:
        
        res=[]
        if len(nums)<3:
            return res
        
        nums.sort()
        for i in range(len(nums)-2):
            
            if i>0 and nums[i]==nums[i-1]:
                continue #while i>0 and nums[i]==nums[i-1]:
                #i+=1!!WRONG for does the i++ so here should be continue
            
            l=i+1
            r=len(nums)-1
            
            while l<r:
                
                if (nums[i]+nums[l]+nums[r]) == 0:
                    res.append([nums[i],nums[l],nums[r]])
                    l=l+1
                    r=r-1
                    while l<r and nums[l]==nums[l-1]:
                        l=l+1
                    while l<r and nums[r]==nums[r+1]:
                        r=r-1
                
                elif (nums[i]+nums[l]) < -nums[r]:
                    l=l+1
                    while l<r and nums[l]==nums[l-1]:
                        l+=1
                else:
                    r=r-1
                    while l<r and nums[r]==nums[r+1]:
                        r-=1
                        
        return res 
