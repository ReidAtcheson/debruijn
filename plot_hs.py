import sys
import numpy as np
import matplotlib as mat
mat.use('agg')
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib.colors import LogNorm


nx=int(sys.argv[1])
ny=int(sys.argv[2])
A=float(sys.argv[3])
V=np.fromfile("hs.dat")
V=np.reshape(V,(nx,ny))
plt.imshow(V,extent=[-A,A,-A,A],norm=LogNorm())
plt.colorbar()
plt.savefig("hs.pdf")
