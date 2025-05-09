class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) - 1 

        while low <= high: 
            index = (low + high) // 2 
            if nums[index] > target:
                high = index - 1
            elif nums[index] < target:
                low = index + 1
            else:
                return index
        return low



        
