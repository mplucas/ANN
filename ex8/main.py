import numpy as np

xs = []
ys = []

try:
  while True:
    x, y = map(float, input().split())
    xs.append(x)
    ys.append(y)

except:
  pass

ans = []

for i in range (0,len(ys)):
  ans.append([ys[i]])

for k in range (0,len(ans)-1):  
  for i in range (1,len(xs)-k):
    aux = (ans[i][k]-ans[i-1][k])/(xs[i]-xs[i-1])
    ans[i-1].append(aux)

# for i in range (0,len(ans)):
#   print(ans[i])

for i in range (0,len(ans[0])):
  print(ans[0][i])