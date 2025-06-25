class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # 0 - 1000 -> nums1[i], nums2[i]
        # nums1 = [1,2,2,1], nums2 = [2,2]
        
        intersection = []
        for i in range(len(nums1)):
            if nums1[i] in nums2 and nums1[i] not in intersection:
                intersection.append(nums1[i])
        
        return intersection
