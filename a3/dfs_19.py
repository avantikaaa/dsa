import math
def getLength(phi, i):
	count = 1
	while(phi[i] != -1):
		count += 1
		i = phi[i]
	return count

def maxLength(phi, leaf, n, f):
	l = 1
	for i in range(n):
		if leaf[i]:
			l = max(l, getLength(phi, i))
	return max(l//f, 1)

def bfs(adj, phi, visit, leaf, s):
	queue = [s]
	phi[s] = -1
	visit[s] = True
	leaf[s] = 1
	while queue:
		u = queue.pop(0)							#dequeue
		for v in adj[u]:
			if not visit[v]:
				queue.append(v)					#enqueue
				phi[v] = u
				visit[v] = True
				leaf[v] = leaf[u] + 1
	return leaf[u]
#	print("phi:", phi)

def main():
	n, m, f = map(int, input().split())

	adj = []
	num = []
	for i in range (n):
		adj.append([])
		num.append(i)

	#create adj list
	for i in range (m):
		u, v = map(int, input().split())
		adj[u-1].append(v-1)
		adj[v-1].append(u-1)

	phi = [-2]*n
	visit = [False]*n
	leaf = [-1]*n
	count = 1
	for s in range(n):
		if phi[s] == -2:
			count = max(count, bfs(adj, phi, visit, leaf, s))
	print (math.ceil((count+1)/f))
	#print (maxLength(phi, leaf, n, f))

main()


