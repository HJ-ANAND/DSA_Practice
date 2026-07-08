class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        ans = []
        i = j = 0

        while i < len(firstList) and j < len(secondList):
            si, ei = firstList[i]
            sj, ej = secondList[j]

            start = max(si, sj)
            end = min(ei, ej)

            if start <= end:
                ans.append([start, end])

            if ei < ej:
                i += 1
            else:
                j += 1

        return ans