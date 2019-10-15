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

for i in range (1,len(ans)):  
  for j in range (1,i+1):
    aux = (ans[i][j-1]-ans[i-1][j-1])/(xs[i]-xs[i-j])
    ans[i].append(aux)

for i in range ( 0, len(ans) ):
  print('a'+str(i)+':',ans[i][i])