import numpy as np
import matplotlib.pyplot as plt

m = 16 * 16 - 15
n_ = np.array(list(range(10, 240 + 1)))
x_ = (m - n_ + 3) / (n_ - 2)
omega_ = x_ * 10 + 3
pb_ = 1 / omega_
pa_ = 2 * x_ * pb_
pc_ = (4 * x_ + 0.6) * pb_

fig, ax = plt.subplots()
ax.plot(n_, pa_, 'r-', label='P(A)')
ax.plot(n_, pb_, 'b-', label='P(B)')
ax.plot(n_, pc_, 'g-', label='P(C)')
ax.legend()
plt.show()
