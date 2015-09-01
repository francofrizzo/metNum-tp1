#!/usr/bin/python

import numpy as np
import scipy as sp
from scipy.interpolate import interp1d

x1 = sorted([1., 0.88, 0.67, 0.50, 0.35, 0.27, 0.18, 0.11, 0.08, 0.04, 0.04, 0.02])
y1 = [0., 13.99, 27.99, 41.98, 55.98, 69.97, 83.97, 97.97, 111.96, 125.96, 139.95, 153.95]

x = np.array(x1)
y = np.array(y1)

new_length = 25
new_x = np.linspace(x.min(), x.max(), new_length)
new_y = sp.interpolate.interp1d(x, y, kind='cubic')(new_x)

print(new_y);