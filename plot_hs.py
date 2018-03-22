import numpy as np
import matplotlib as mat
mat.use('agg')
import matplotlib.pyplot as plt
import matplotlib.animation as animation


nx=512
ny=512
V=np.fromfile("hs.dat")
V=np.reshape(V,(nx,ny))
plt.imshow(V,extent=[-1,1,-1,1])
plt.colorbar()
plt.savefig("hs.pdf")
