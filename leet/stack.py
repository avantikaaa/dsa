'''
def tryy(pushed, popped):
	out = []
	for p in popped:
		print "ccc"
		l = len(out)-1
		while(l>=0):
			print "bbb"
			if(out[l]==p):
	                	out.pop()
			else:
        	        	break
        	        l = len(out)-1
		while (len(pushed)-1>0 and pushed[0]!=p):
			print "aa"
			out.append(pushed[0])
			pushed.pop(0)
        	        l = len(out)-1
       	print out
	if (out==[]):
		return True
	return False

pushed = input()
popped = input()
print tryy(pushed, popped)
'''

def func(pushed, popped):
	push=0
	l = len(pushed)
	while(popped!=[]):
		if(push>=l):
			return False
#		print l, push
#		print pushed[push]
#		print popped,
#		print push, pushed
		if(popped!=[] and pushed[push]!=popped[0]):
			push+=1
#			print push, pushed
		elif(pushed[push]==popped[0]):
			pushed.pop(push)
			if(push!=0):
				push-=1
#			if(pushed<0):
#				pushed=0
			l-=1
			popped.pop(0)
#		print push, pushed
	return True	
	
	
pushed = input()
popped = input()
print func(pushed, popped)
