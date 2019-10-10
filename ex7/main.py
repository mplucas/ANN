import numpy as np

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

ans = np.linalg.solve(xs,ys)

for i in range (0,len(ans)):
  print('a'+str(i)+':',ans[i])
