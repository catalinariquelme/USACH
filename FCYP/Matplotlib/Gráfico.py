

import matplotlib.pyplot as plotter
from numpy import arange


# Creo el vector utilizando la función arange de numpy
vector = arange(-10,10.1, 0.1)
# Realizo el calculo de la función f(x)
resultadoFuncion = vector ** 2
# Realizo el calculo de la funcion g(x)
resultadoFuncion2 = 100 - vector ** 2 - vector

# Dibujo el gráfico f(x)
grafico = plotter.plot(vector, resultadoFuncion, label="f(x)")
# Defino el estilo de f(x)
plotter.setp(grafico,'linestyle','--', 'color','r', 'linewidth',1.5)
# Dibujo el gráfico de g(x)
grafico2 = plotter.plot(vector, resultadoFuncion2, label="g(x)")
# Defino el estilo de g(x)
plotter.setp(grafico2,'linestyle','-', 'color','c', 'linewidth',2.0)
# Indico que deseo mostrar las etiquetas
plotter.legend()
# Muestro el gráfico por pantalla
plotter.show()
