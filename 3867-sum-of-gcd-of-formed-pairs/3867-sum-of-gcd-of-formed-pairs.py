class Solution:
    def gcd(self, a, b):
        while b != 0:
            r = a % b
            a = b
            b = r
        return a
        
    def gcdSum(self, nums: list[int]) -> int:
        n = len(nums)
        mx = float('-inf')
        preGCD = []

        for i in range(n):
            mx = max(mx, nums[i])
            preGCD.append(self.gcd(nums[i], mx))

        preGCD.sort()

        n = len(preGCD)
        total = 0

        for i in range(n // 2):
            if i == n - 1 - i:
                continue
            total += self.gcd(preGCD[i], preGCD[n - 1 - i])

        return total