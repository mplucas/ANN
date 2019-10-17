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

    div = 1

    for j in range (0,len(xs)):

        if i == j:
            continue

        div = div * (xs[i] - xs[j])

    ans.append( ys[i] / div )

for i in range ( 0, len(ans) ):
  print('a'+str(i)+':',ans[i])