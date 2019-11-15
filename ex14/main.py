import numpy as np

def integrateX(expX, h, imin, imax):
    acum = pow(imin,expX) + pow(imax,expX)

    for i in range( imin+h, imax, h ):
        acum = acum + 2 * pow(i,expX)
    
    return acum * (h/2)

def integrateExp(expX, h, imin, imax):
    acum = np.exp(-1.473*pow(imin,2))*pow(imin,expX) + np.exp(-1.473*pow(imax,2))*pow(imax,expX)

    for i in range( imin+h, imax, h ):
        acum = acum + 2 * np.exp(-1.473*pow(i,2))*pow(i,expX)
    
    return acum * (h/2)

def main():
    exps = list(range(0,10))
    h = 0.01
    imin = -2
    imax = 2
    A = []
    B = []

    for i in range(0,10):
        B.append( integrateExp( i, h, -2, 2 ) )
        A.append([])
        for j in range(0,10):
            A[i].append( integrateX( i+j, h, -2, 2 ) )

    print(A)
    print(B)

main()