from collections import defaultdict
from math import ceil

def bfs(adj, V, s):
	q = []
	q.append(s)
	V[s] = 1
	while (q):
		u = q.pop(0)							#Dequeue
		for v in adj[u]:
			if V[v] == -1:			#Like visited. if not visited then w = -1
				V[v] = 1
				q.append(v)					#Enqueue
	return u

def bfsi(adj, V, s):
	q = []
	q.append(s)
	V[s] = 0
	while q:
		u = q.pop(0)
		for v in adj[u]:
			if V[v] == -1:
				V[v] = V[u] + 1
				q.append(v)
	return V[u]

def main():
	n, m, f = map(int, input().split())
	
	adj = defaultdict(list)
	for i in range (m):
		u, v = map(int, input().split())
		adj[u].append(v)
		adj[v].append(u)

	V = {}
	for i in range (1, n+1):
		V[i] = -1;
	
	count = 1
	graph = []				#values of starting point of unconnected graphs

	for i in range(1, n+1):
		if V[i] == -1:
			graph.append(bfs(adj, V, i))
	
	for i in range (1, n+1):
		V[i] = -1;
	
	for i in graph:
		count = max(count, bfsi(adj, V, i))
	
	print(ceil((count+1)/f))

main()
