def dfs(adj, phi, visit, leaf, u):
	if len(adj[u]) == 0:
		return
	leaf[u] = False
	for v in adj[u]:
 		phi[v] = u
 		if not visit[v]:
 			dfs(adj, phi, visit, leaf, v)
 			visit[v] = True
	return

def main():
	t = int(input())
	while(t>0):
		n, m = map(int, input().split())
		b = [map(int, input().split())]
		adj = []
		for i in range (n):
			adj.append([])
		
		for i in range (m):
			u, sign, v = input().split()
			if sign == ">":
				adj[int(v)-1].append(int(u)-1)
			else:
				adj[int(u)-1].append(int(v)-1)
		
		phi = [-2]*n
		visit = [False]*n
		leaf = [True]*n
		
		for s in range (n):
			if phi[s] == -2:
				phi[s] = -1
				dfs(adj, phi, visit, leaf, s)
				visit[s] = True
		
		print("phi:", phi)
		print("leaf:", leaf)
		
		t -= 1

main()
