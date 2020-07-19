class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n-1:
            return -1
        #create adjecency list
        adj = []
        for i in range (n):
            adj.append([])
        
        for u, v in connections:
            adj[u].append(v)
            adj[v].append(u)
        
        phi = [-2]*n
        visit = [False]*n
        count = -1
        for s in range (n):
            if phi[s] == -2:
                count += 1
                stack = set(adj[s])
             #   stack = stack.union(adj[s])
                phi[s] = -1
                visit[s] = True
                while stack:
                    v = stack.pop()
                    if not visit[v]:
                        phi[v] = s
                        visit[v] = True
                        stack = stack.union(adj[v])
        return count
