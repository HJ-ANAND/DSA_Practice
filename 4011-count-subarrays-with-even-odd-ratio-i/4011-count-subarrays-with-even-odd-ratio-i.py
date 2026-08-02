class Solution:
    def countRatioSubarrays(self, nums: list[int], a: int, b: int) -> int:
        n = len(nums)
        div = a / b

        count = 0

        for i in range(n):
            even = 0.0
            odd = 0.0
            for j in range(i, n):
                if nums[j] % 2 == 0:
                    even += 1
                else:
                    odd += 1

                if odd > 0 and (even / odd) <= div:
                    count += 1

        return count