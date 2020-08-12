class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        #d={}
        l=[]
        for i in range(len(nums)-2):
            re = 0 - nums[i]
            d={}
            for j in range(i+1,len(nums)):
                # Find all elements after i
                # if i!=j :
                if d.has_key(nums[j]):
                    index = d.get(nums[j])
                    tmp=[nums[i],nums[index],nums[j]]
                    
                    repeat=0
                    for n in l:
                        if n[0] in tmp and n[1] in tmp and n[2] in tmp:
                            repeat=1
                            break
                        
                    if repeat!=1:
                        l.append(tmp)
                else:
                    d[re-nums[j]]=j
                    
        #l=list(l)
        print (l)    
        
