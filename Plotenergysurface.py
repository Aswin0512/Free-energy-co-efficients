import matplotlib.pyplot as plt
import numpy as np

rawdata=np.loadtxt("square_1.00_100.txt",delimiter="\t",dtype=float)
surfpnts=[]
indx=0
dim=rawdata.shape
for i in range(dim[0]):
    if rawdata[i,2]!=0:
        surfpnts.append(rawdata[i,:])

plt.figure(figsize=(7,7))
xpoints=surfpnts[:,0]
ypoints=surfpnts[:,1]
clr=surfpnts[:,2]

plt.plot(xpoints,ypoints,marker="o",markersize=1,linestyle="none",c=clr,cmap="viridis")
plt.xlabel("Kx")
plt.ylabel("ky")
#plt.savefig("square.png")
plt.show()
