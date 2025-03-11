import numpy as np
import scipy.optimize as opt
import matplotlib.pyplot as plt

# Substitua pelos valores coletados
distancias = np.array([0.5, 1.0, 1.5, 2.0])  # cm
leituras = np.array([2916, 1441, 757, 470])  # Valores do sensor

# Modelo de potência: d = A * leitura^B
def modelo_potencia(x, A, B):
    return A * (x ** B)

# Ajuste de curva para encontrar os coeficientes A e B
params, _ = opt.curve_fit(modelo_potencia, leituras, distancias)

# Coeficientes ajustados
A_fit, B_fit = params
print(f"Equação ajustada: d = {A_fit:.4f} * leitura^{B_fit:.4f}")

# Gerando pontos para visualizar o ajuste da curva
leituras_pred = np.linspace(min(leituras), max(leituras), 100)
dist_pred = modelo_potencia(leituras_pred, A_fit, B_fit)

# Plotando os dados experimentais e a curva ajustada
plt.scatter(leituras, distancias, color='red', label="Dados Medidos")
plt.plot(leituras_pred, dist_pred, label=f"Ajuste: d = {A_fit:.4f} * leitura^{B_fit:.4f}", color='blue')
plt.xlabel("Leitura do Sensor")
plt.ylabel("Distância (cm)")
plt.title("Curva de Calibração do Sensor")
plt.legend()
plt.grid()
plt.show()
