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

# calculando hs
hs = []

for i in range (0,len(xs) - 1):
  hs.append(xs[i + 1] - xs[i])

# calculando diagonal de hs
diag_hs = []

# primeira linha da matriz
aux = [1]
for i in range (0,len(xs) - 1):
  aux.append(0)
diag_hs.append(aux[:])

# linhas do meio
for i in range (0,len(hs) - 1):
  aux.clear()
  for j in range (0,len(xs)):
    if j == i:
      aux.append(hs[i])
    elif j == (i + 1):
      aux.append(2 * (hs[i] + hs[i + 1]))
    elif j == (i + 2):
      aux.append(hs[i + 1])
    else:
      aux.append(0)
  diag_hs.append(aux[:])

# ultima linha da matriz
aux.clear()
for i in range (0,len(xs) - 1):
  aux.append(0)
aux.append(1)
diag_hs.append(aux[:])

#calcular vetor de as e hs
ashs = []

#primeira linha
ashs.append(0)

for i in range(1, len(xs) - 1):
  ashs.append( ((3 / hs[i]) * (ys[i + 1] - ys[i])) - ((3 / hs[i - 1]) * (ys[i] - ys[i - 1])) )

#ultima linha
ashs.append(0)

# calculando cs
cs = np.linalg.solve(diag_hs,ashs)

# calculando ds
ds = []

for i in range(0, len(cs) - 1):
  ds.append( ((cs[i + 1] - cs[i]) / (3 * hs[i])) )

# calculando bs
bs = []

for i in range(0, len(cs) - 1):
  bs.append( ((ys[i + 1] - ys[i]) / hs[i]) - ((hs[i] / 3) * (cs[i + 1] + (2 * cs[i]))) )


for i in range ( 0, len(ys) ):
  print('a'+str(i)+':',ys[i])
print()
for i in range ( 0, len(bs) ):
  print('b'+str(i)+':',bs[i])
print()
for i in range ( 0, len(cs) ):
  print('c'+str(i)+':',cs[i])
print()
for i in range ( 0, len(ds) ):
  print('d'+str(i)+':',ds[i])