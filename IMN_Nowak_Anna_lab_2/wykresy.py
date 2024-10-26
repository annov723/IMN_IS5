import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np

#z.1

with open('../data/wyniki1.txt', 'r') as file:
    first_line = file.readline().strip()
    y1 = np.array([float(i) for i in first_line.split()])

    second_line = file.readline().strip()
    y2 = np.array([float(i) for i in second_line.split()])

    third_line = file.readline().strip()
    y3 = np.array([float(i) for i in third_line.split()])
    
    forth_line = file.readline().strip()
    y4 = np.array([float(i) for i in forth_line.split()])
    
    fifth_line = file.readline().strip()
    y5 = np.array([float(i) for i in fifth_line.split()])
    
    sixth_line = file.readline().strip()
    y6 = np.array([float(i) for i in sixth_line.split()])
    
x12 = np.linspace(0, 100, len(y1))
x34 = np.linspace(0, 100, len(y3))
x56 = np.linspace(0, 100, len(y5))

plt.figure()
plt.plot(x12, y1, label='u(t)')
plt.plot(x12, y2, label='z(t)')
plt.xlabel('t')
plt.ylabel('u(t), z(t)')
plt.title('Metoda Picarda')
plt.legend()
plt.savefig('../z1.png')

plt.figure()
plt.plot(x34, y3, label='u(t)')
plt.plot(x34, y4, label='z(t)')
plt.xlabel('t')
plt.ylabel('u(t), z(t)')
plt.title('Metoda Newtona')
plt.legend()
plt.savefig('../z2.png')

#z.2
plt.figure()
plt.plot(x56, y5, label='u(t)')
plt.plot(x56, y6, label='z(t)')
plt.xlabel('t')
plt.ylabel('u(t), z(t)')
plt.title('Niejawna RK2')
plt.legend()
plt.savefig('../z3.png')