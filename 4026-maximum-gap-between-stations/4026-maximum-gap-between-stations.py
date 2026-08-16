class Solution:
    def maximumGap(self, skill: str, station: str) -> int:
        n = len(skill)
        m = len(station)

        if n == 1 or m == 1:
            return 0

        if n == m:
            return 1

        left = [0] * n
        right = [0] * n

        j = 0

        for i in range(n):
            while skill[i] != station[j]:
                j += 1

            left[i] = j
            j += 1

        j = m - 1

        for i in range(n - 1, -1, -1):
            while skill[i] != station[j]:
                j -= 1

            right[i] = j
            j -= 1

        ans = float('-inf')

        for i in range(n - 1):
            ans = max(ans, right[i + 1] - left[i])

        return ans