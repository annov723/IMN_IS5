import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np

#z.1
t = np.linspace(0, 5, 101)
y1 = np.exp(-t)

with open('../data/wyniki1.txt', 'r') as file:
    first_line = file.readline().strip()
    y2 = np.array([float(i) for i in first_line.split()])

    second_line = file.readline().strip()
    y3 = np.array([float(i) for i in second_line.split()])

    third_line = file.readline().strip()
    y4 = np.array([float(i) for i in third_line.split()])
    
t2 = np.linspace(0, 5, len(y2))
t3 = np.linspace(0, 5, len(y3))
t4 = np.linspace(0, 5, len(y4))

plt.figure()
plt.scatter(t2, y2, label='dt = 0.01')   
plt.scatter(t3, y3, label='dt = 0.1')
plt.scatter(t4, y4, label='dt = 1') 
plt.plot(t, y1, label='analitycznie', color='black')
plt.ylabel('y(t)')
plt.title('z.1 - Metoda Eulera - rozwiązanie')
plt.legend()
plt.savefig('../z11.png')

t = np.linspace(0, 5, len(y2))
y1 = np.exp(-t)
y2 = y2 - y1
   
t = np.linspace(0, 5, len(y3))
y1 = np.exp(-t)
y3 = y3 - y1

t = np.linspace(0, 5, len(y4))
y1 = np.exp(-t)
y4 = y4 - y1

plt.figure()
plt.plot(t2, y2, label='dt = 0.01')
plt.plot(t3, y3, label='dt = 0.1')
plt.plot(t4, y4, label='dt = 1')
plt.ylabel(r'$y_{num}(t) - y_{dok}(t)$', fontsize=14)
plt.title('z.1 - Metoda Eulera - błąd globalny')
plt.legend()
plt.savefig('../z12.png')

#z.2
t = np.linspace(0, 5, 101)
y1 = np.exp(-t)

with open('../data/wyniki2.txt', 'r') as file:
    first_line = file.readline().strip()
    y2 = np.array([float(i) for i in first_line.split()])

    second_line = file.readline().strip()
    y3 = np.array([float(i) for i in second_line.split()])

    third_line = file.readline().strip()
    y4 = np.array([float(i) for i in third_line.split()])
    
t2 = np.linspace(0, 5, len(y2))
t3 = np.linspace(0, 5, len(y3))
t4 = np.linspace(0, 5, len(y4))

plt.figure()
plt.scatter(t2, y2, label='dt = 0.01')   
plt.scatter(t3, y3, label='dt = 0.1')
plt.scatter(t4, y4, label='dt = 1') 
plt.plot(t, y1, label='analitycznie', color='black')
plt.ylabel('y(t)')
plt.title('z.2 - Metoda RK2 - rozwiązanie')
plt.legend()
plt.savefig('../z21.png')

y1 = np.exp(-t2)
y2 = y2 - y1
   
y1 = np.exp(-t3)
y3 = y3 - y1

y1 = np.exp(-t4)
y4 = y4 - y1

plt.figure()
fig, sub = plt.subplots(1, 2)
sub[0].plot(t2, y2, label='dt = 0.01')
sub[0].plot(t3, y3, label='dt = 0.1')
sub[0].plot(t4, y4, label='dt = 1')
sub[0].set_ylabel(r'$y_{num}(t) - y_{dok}(t)$', fontsize=14)
sub[0].set_xlim(0, 5)
sub[0].legend()

sub[1].plot(t2, y2, label='dt = 0.01')
sub[1].plot(t3, y3, label='dt = 0.1')
sub[1].set_ylabel(r'$y_{num}(t) - y_{dok}(t)$', fontsize=14)
sub[1].set_xlim(0, 5)
sub[1].legend()

fig.suptitle('z.2 - Metoda RK2 - błąd globalny')
plt.tight_layout() 
plt.savefig('../z22.png')

#z.3
t = np.linspace(0, 5, 101)
y1 = np.exp(-t)

with open('../data/wyniki3.txt', 'r') as file:
    first_line = file.readline().strip()
    y2 = np.array([float(i) for i in first_line.split()])

    second_line = file.readline().strip()
    y3 = np.array([float(i) for i in second_line.split()])

    third_line = file.readline().strip()
    y4 = np.array([float(i) for i in third_line.split()])
    
t2 = np.linspace(0, 5, len(y2))
t3 = np.linspace(0, 5, len(y3))
t4 = np.linspace(0, 5, len(y4))

plt.figure()
plt.scatter(t2, y2, label='dt = 0.01')   
plt.scatter(t3, y3, label='dt = 0.1')
plt.scatter(t4, y4, label='dt = 1') 
plt.plot(t, y1, label='analitycznie', color='black')
plt.ylabel('y(t)')
plt.title('z.3 - Metoda RK4 - rozwiązanie')
plt.legend()
plt.savefig('../z31.png')

y1 = np.exp(-t2)
y2 = y2 - y1

y1 = np.exp(-t3)
y3 = y3 - y1

y1 = np.exp(-t4)
y4 = y4 - y1

plt.figure()
fig, sub = plt.subplots(1, 2)
sub[0].plot(t2, y2, label='dt = 0.01')
sub[0].plot(t3, y3, label='dt = 0.1')
sub[0].plot(t4, y4, label='dt = 1')
sub[0].set_ylabel(r'$y_{num}(t) - y_{dok}(t)$', fontsize=14)
sub[0].set_xlim(0, 5)
sub[0].legend()

sub[1].plot(t2, y2, label='dt = 0.01')
sub[1].plot(t3, y3, label='dt = 0.1')
sub[1].set_ylabel(r'$y_{num}(t) - y_{dok}(t)$', fontsize=14)
sub[1].set_xlim(0, 5)
sub[1].legend()

fig.suptitle('z.3 - Metoda RK4 - błąd globalny')
plt.tight_layout() 
plt.savefig('../z32.png')

#z.4
with open('../data/wyniki4.txt', 'r') as file:
    line1 = file.readline().strip()
    y1I = np.array([float(i) for i in line1.split()])

    line2 = file.readline().strip()
    y1Q = np.array([float(i) for i in line2.split()])

    line3 = file.readline().strip()
    y2I = np.array([float(i) for i in line3.split()])

    line4 = file.readline().strip()
    y2Q = np.array([float(i) for i in line4.split()])
    
    line5 = file.readline().strip()
    y3I = np.array([float(i) for i in line5.split()])

    line6 = file.readline().strip()
    y3Q = np.array([float(i) for i in line6.split()])
    
    line7 = file.readline().strip()
    y4I = np.array([float(i) for i in line7.split()])

    line8 = file.readline().strip()
    y4Q = np.array([float(i) for i in line8.split()])

end = 4. * ( 2. * np.pi / ( 1. / np.sqrt( 0.1 * 0.001 ) ) )

t1 = np.linspace(0, end, len(y1I))
t2 = np.linspace(0, end, len(y2I))
t3 = np.linspace(0, end, len(y3I))
t4 = np.linspace(0, end, len(y4I))

plt.figure()
plt.plot(t1, y1Q, label=r'0.5$\omega_0$') 
plt.plot(t2, y2Q, label=r'0.8$\omega_0$')   
plt.plot(t3, y3Q, label=r'1.0$\omega_0$')
plt.plot(t4, y4Q, label=r'1.2$\omega_0$') 
plt.ylabel('Q(t)')
plt.title('z.4 - Metoda RK4, Q(t)')
plt.legend()
plt.savefig('../z41.png')

plt.figure()
plt.plot(t1, y1I, label=r'0.5$\omega_0$') 
plt.plot(t2, y2I, label=r'0.8$\omega_0$')   
plt.plot(t3, y3I, label=r'1.0$\omega_0$')
plt.plot(t4, y4I, label=r'1.2$\omega_0$') 
plt.ylabel('I(t)')
plt.title('z.4 - Metoda RK4, I(t)')
plt.legend()
plt.savefig('../z42.png')