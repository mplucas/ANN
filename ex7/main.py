import numpy as np

#--

A = np.array([[1,1],[-3,1]])
B = np.array([[6],[2]])

A_inversa = np.linalg.inv(A)
x = np.linalg.solve(A,B)

#--

xs = []
ys = []

try:
  while True:
    um, dois = map(float, input().split())
    xs.append([1,um])
    ys.append(dois)

except:
  pass

for i in range (0,len(xs)):
  for j in range (2,len(xs)):
    xs[i].append(pow(xs[i][1],j))

# for i in range (0,len(xs)):
#   print(xs[i])

# for i in range (0,len(ys)):
#   print(ys[i])

ans = np.linalg.solve(xs,ys)

for i in range (0,len(ans)):
  print('a'+str(i)+':',ans[i])

# xs_inversa = np.linalg.inv(xs)
# ans = np.dot(xs_inversa,ys)
# print()

# for i in range (0,len(ans)):
#   print(ans[i])