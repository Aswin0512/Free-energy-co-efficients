import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D 
import math as ma

l=50
Ev=2
x=np.linspace(-np.pi,np.pi,l)
y=np.linspace(-np.pi,np.pi,l)
z=np.linspace(-np.pi,np.pi,l)
#creating a 3d mesh
kx,ky,kz=np.meshgrid(x,y,z)
x=[]
y=[]
z=[]
e=[]
m=[]
#float E = 0 
for i in range(l):
    for j in range(l):
        for k in range(l):
            E=(kx[i,j,k]**2+ky[i,j,k]**2+kz[i,j,k]**2)/2
            if abs(E - Ev )<= 0.01:
                p=i*l**2+j*l+k
                x.append(kx[i,j,k])
                y.append(ky[i,j,k])
                z.append(kz[i,j,k])
                e.append(E)

fig=plt.figure()
ax=fig.add_subplot(projection='3d')
#Energy=ax.scatter3D(np.ravel(kx),np.ravel(ky),np.ravel(kz),c=np.ravel(E),cmap='viridis')
Energy=ax.scatter3D(x,y,z,c=e,cmap='viridis')
plt.colorbar(Energy)
plt.show()