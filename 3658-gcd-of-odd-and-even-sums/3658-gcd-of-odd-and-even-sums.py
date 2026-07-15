class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        sumOdd = n * n
        sumEven = n * (n+1)

        while (sumEven != 0):
            r = sumOdd % sumEven
            sumOdd = sumEven
            sumEven = r
        
        return sumOdd