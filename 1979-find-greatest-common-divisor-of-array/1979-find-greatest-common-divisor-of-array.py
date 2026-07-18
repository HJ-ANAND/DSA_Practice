class Solution:
    def gcd(a, b):
        if(a == 0):
            return b
        if(b == 0):
            return a

        return gcd(a%b, b)

    def findGCD(self, nums: List[int]) -> int:
        hg = max(nums)
        low = min(nums)

        return gcd(hg, low)