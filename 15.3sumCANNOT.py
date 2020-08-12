#Time exceed the limit

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        l=[]
        if len(nums)<3: 
            return l
        
        for i in range(len(nums)-2):
            re = 0 - nums[i]
            d={}
            for j in range(i+1,len(nums)):
                if d.has_key(nums[j]):
                    
                    index = d.get(nums[j])
                    tmp=[nums[i],nums[index],nums[j]]
                    
                    repeat=0
                    for n in l:
                        n.sort()
                        tmp.sort()
                        if n==tmp:
                            repeat=1
                            break
                    
                    if repeat!=1:
                        l.append(tmp)
                else:
                    d[re-nums[j]]=j
                    
        #l=list(l)
        return l  

        
        
        
