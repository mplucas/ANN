import numpy as np
import math

def calcF(f, x):
    ans = 1
    
    if f[0] == 's':
        ans = math.sin(int(f[1])*x)
    elif f[0] == 'c':
        ans = math.cos(int(f[1])*x)

    if len(f) > 2:
        if f[2] == 's':
            ans = ans * math.sin(int(f[3])*x)
        elif f[2] == 'c':
            ans = ans * math.cos(int(f[3])*x)
    return ans

def integrateX(f, h, imin, imax):
    n = int((imax-imin) / (2*h))
    acum = calcF(f,imin) + calcF(f,imax)
    for k in range( 1, n ):
        acum = acum + 2 * calcF(f,imin+2*k*h)
    for k in range( 1, n+1 ):
        acum = acum + 4 * calcF(f,imin+(2*k-1)*h)
    return acum * (h/3)

def integrateExp(f, h, imin, imax):
    n = int((imax-imin) / (2*h))
    acum = np.exp(-1.19*pow(imin,2))*calcF(f,imin) + np.exp(-1.19*pow(imax,2))*calcF(f,imax)
    for k in range( 1, n ):
        acum = acum + 2 * np.exp(-1.19*pow(imin+2*k*h,2))*calcF(f,imin+2*k*h)
    for k in range( 1, n+1 ):
        acum = acum + 4 * np.exp(-1.19*pow(imin+(2*k-1)*h,2))*calcF(f,imin+(2*k-1)*h)
    return acum * (h/3)

def main():
    h = 0.01
    imin = -2
    imax = 2
    A = []
    B = []

    # Gerar matriz de formulas
    fs = ['nn','s1','c1','s2','c2','s3','c3','s4','c4','s5','c5']
    matrizf = []
    for i in range(0,11):
        matrizf.append([])
        for j in range(0,11):
            matrizf[i].append(fs[i]+fs[j])
    
    for i in range(0,11):
        B.append( integrateExp( fs[i], h, -2, 2 ) )
        A.append([])
        for j in range(0,11):
            A[i].append( integrateX( matrizf[i][j], h, -2, 2 ) )
    
    X = np.linalg.solve(A,B)

    for i in range(0, len(X)):
        print('a' + str(i) + ': ' + str(X[i]))

main()