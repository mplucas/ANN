ns = []

try:
  while True:
    n = float(input())
    ns.append( [n] )

except:
  pass

expErro = 12
b = 12 / (len(ns))

for i in range (0,len(ns) - 1):
  for j in range (0,len(ns) - i - 1):
    ns[j].append( (pow(2, (i + 1) * b) * ns[j + 1][i] - ns[j][i]) / (pow(2, (i + 1) * b) - 1) )

print('N:', ns[0][len(ns[0]) - 1])