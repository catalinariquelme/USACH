#Ingresar un número y que entregue el factorial de ese número

n = 100#int(input("Ingrese un número: "))
i = 1

while n > 0:
    
    i = i * n
    n -= 1
    
print(i)