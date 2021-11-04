# 5 mallas , cada una 10 limones, hace 3 limonadas, usa 4 limones en cada vaso. Cuantos quedan? Juan

mallas = int(input("Mallas compradas por Juan: "))
amigos = int(input("Amigos que tiene Juan: "))

limones_iniciales = mallas * 10
limones_consumidos = amigos * 4

limones_totales= limones_iniciales - limones_consumidos

print("Limones totales: ", limones_totales)