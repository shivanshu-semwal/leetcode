class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        l1 = [0] * 101
        l2 = [0] * 101
        l3 = [0] * 101
        
        for i in nums1:
            l1[i] = 1
        for i in nums2:
            l2[i] = 1
        for i in nums3:
            l3[i] = 1
            
        for i in range(len(l1)):
            l1[i] = l1[i] + l2[i] + l3[i]
        
        ans = []
        
        for i in range(len(l1)):
            if l1[i] >= 2:
                ans.append(i)
        
        return ans
