import string

l = ['h', 'e', 'l', 'l', 'o']
m = l.copy()
l.reverse()
l.append("hello")
print(max(l))
print(m)
# Mutation
# l.sort()
# l.reverse()
# l=sorted(l)
# l=list(reversed(l))
#swallow copy and deep copy