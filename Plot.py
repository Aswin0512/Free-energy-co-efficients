import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D 
import math as ma


x=np.linspace(-np.pi,np.pi,10)
y=np.linspace(-np.pi,np.pi,10)
z=np.linspace(-np.pi,np.pi,10)
#creating a 3d mesh
kx,ky,kz=np.meshgrid(x,y,z)

E=(kx**2+ky**2+kz**2)/2

fig=plt.figure()
ax=fig.add_subplot(projection='3d')
Energy=ax.scatter3D(kx,ky,kz)
#plt.colorbar(Energy)
plt.show()