class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        length = len(board)
        breadth = 0
        if length != 0:
            breadth = len(board[0])
        l = [0]*breadth
        g = ["X"]*breadth
        grid = []
        for i in range (length):
            grid.append(g[:])
        stack = set([])
        
        for i in range(1, breadth-1):
            if board[0][i] == "O":          #top row
                stack.add((0, i))
            if board[length-1][i] == "O":    #bottom row
                stack.add((length-1, i))
        for i in range (1, length-1):
            if board[i][0] == "O":          #left
                stack.add((i, 0))
            if board[i][breadth-1] == "O":  #right
                stack.add((i, breadth-1))
        while (stack):
            i, j = stack.pop()
            if grid[i][j] != "O":
                grid[i][j] = "O"
                if i > 0 and board[i-1][j] == "O":
                    stack.add((i-1, j))
                if i < length-1 and board[i+1][j] == "O":
                    stack.add((i+1, j))
                if j > 0 and board[i][j-1] == "O":
                    stack.add((i, j-1))
                if j < breadth-1 and board[i][j+1] == "O":
                    stack.add((i, j+1))
        for i in range (1, length-1):
            for j in range (1, breadth-1):
                board[i][j] = grid[i][j]
