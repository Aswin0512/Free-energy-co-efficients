import matplotlib.pyplot as plt
import numpy as np

rawdata=np.loadtxt("square_0.00_100.txt",delimiter="\t",dtype=float)
dim=rawdata.shape
dindx=[]
for i in range(dim[0]):
    if rawdata[i,2]==0:
        dindx.append(i)

surfpnts=np.delete(rawdata,dindx,0)
plt.figure(figsize=(7,7))
xpoints=surfpnts[:,0]
ypoints=surfpnts[:,1]
clr=surfpnts[:,2]

#plt.plot(xpoints,ypoints,marker="o",markersize=1,linestyle="none")
plt.scatter(xpoints,ypoints,c=clr,marker="o",s=1)
plt.xlabel("Kx")
plt.ylabel("ky")
plt.xlim(-np.pi,np.pi)
plt.ylim(-np.pi,np.pi)
plt.title("Cos kx+ Cos ky =0")
plt.savefig("square1.png")
plt.show()
