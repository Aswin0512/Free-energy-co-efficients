import matplotlib.pyplot as plt
import numpy as np

surfpnts=np.loadtxt("spherical1.txt",delimiter="\t",dtype=float)

plt.figure(figsize=(7,7))
xpoints=surfpnts[:,0]
ypoints=surfpnts[:,1]

plt.plot(xpoints,ypoints,marker="o",markersize=1)
plt.xlabel("Kx")
plt.ylabel("ky")
plt.savefig("spherical_surface.png")
plt.show()
