import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D 
import math as ma


x=np.linspace(-np.pi,np.pi,10)
y=np.linspace(-np.pi,np.pi,10)
z=np.linspace(-np.pi,np.pi,10)
#creating a 3d mesh
kx,ky=np.meshgrid(x,y)

kxm=np.ones((10,10,10))
kym=np.ones((10,10,10))
kzm=np.ones((10,10,10))

for i in range(10):
    kxm[i,:,:]=kx
    kym[i,:,:]=ky

    kzz=z[i]*np.ones((10,10))
    kzm[i,:,:]=kzz


E=(Kx**2+Ky**2+Kz**2)/2

fig=plt.figure(1)
ax=fig.add_subplot(projection='3d')
Energy=ax.scatter(Kx,Ky,Kz,c=E,cmap="viridis")
plt.colorbar(Energy)
plt.show()