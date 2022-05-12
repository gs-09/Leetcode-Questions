class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        store_index={}
        for ind,item in enumerate(nums):
            if(target-item) in store_index:
                return([store_index[target-item],ind])
            store_index[item] = ind
