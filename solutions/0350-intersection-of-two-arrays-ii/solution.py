class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # hash map
        counter = {}

        # 1: 2, 2: 2
        for num in nums1:
            counter[num] = counter.get(num, 0) + 1

        result = []
        for num in nums2:
            if counter.get(num, 0) > 0:
                result.append(num)
                counter[num] -= 1
        
        return result




            


        
