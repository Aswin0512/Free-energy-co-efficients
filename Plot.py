import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D 
import math as ma

l=25
Ev=1
x=np.linspace(-np.pi,np.pi,l)
y=np.linspace(-np.pi,np.pi,l)
z=np.linspace(-np.pi,np.pi,l)
#creating a 3d mesh
kx,ky,kz=np.meshgrid(x,y,z)
m=0
#float E = 0 
for i in range(l):
    for j in range(l):
        for k in range(l):
            #if E=(kx[i,j,k]**2+ky[i,j,k]**2+kz[i,j,k]**2)/2 - Ev <= 0.0001:

#E=(kx**2+ky**2+kz**2)/2

fig=plt.figure()
ax=fig.add_subplot(projection='3d')
Energy=ax.scatter3D(np.ravel(kx),np.ravel(ky),np.ravel(kz),c=np.ravel(E),cmap='viridis')
plt.colorbar(Energy)
plt.show()