class Solution:
    def maximumValue(self, n: int, s: int, m: int) -> int:
        ups = n // 2

        if ups == 0:
            return s

        return s + ups * m - (ups - 1)