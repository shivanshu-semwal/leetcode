class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        if A > B:
            if B-A+B >= 0:
                ans = "aab"*(A-B) + "ab"*(B-A+B)
            else:
                ans = "aab"*B +"a"*(A-2*B)
        else:
            if A-B+A >= 0:
                ans = "bba"*(B-A) + "ba"*(A-B+A)
            else:
                ans = "bba"*A + "b"*(B-2*A)
        return ans
