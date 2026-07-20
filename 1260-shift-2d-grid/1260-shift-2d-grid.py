class Solution:
    def solve(self, grid: list[list[int]]) -> None:
        r = len(grid)
        c = len(grid[0])
        fill = grid[0][0]
        
        for i in range(r):
            for j in range(c):
                temp = grid[i][j]
                grid[i][j] = fill
                fill = temp
                
        grid[0][0] = fill

    def shiftGrid(self, grid: list[list[int]], k: int) -> list[list[int]]:
        for _ in range(k):
            self.solve(grid)
        return grid