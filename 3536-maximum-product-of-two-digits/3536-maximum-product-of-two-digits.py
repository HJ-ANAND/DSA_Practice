class Solution:
    def maxProduct(self, n: int) -> int:
        if n < 10: 
            return n
        mx = 0
        smx = 0

        while n > 0:
            rem = n % 10
            if rem > mx:
                smx = mx
                mx = rem
            elif (rem <= mx and rem >= smx):
                smx = rem
            n //= 10

        return mx * smx