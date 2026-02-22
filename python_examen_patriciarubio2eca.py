#Patricia Alejandra Rubio Barahona 2ECA
#Ejercicio 1
A = int(input("Ingrese un dato diferente de cero para sumarlo automaticamente por si mismo, Ingrese cero para detener el programa"))

def Suma (A):
       return A + A

if (A > 0):
    Resultado = (A + A)
    print("El resultado de tu suma es " ,Resultado)

if (A== 0): 
    Resultado = (A + A)
    print("Finalizaste tu suma de numeros tu resultado es " , Resultado)
# Ejercicio 2
# La salida es (9,10)

#Ejercicio 3
num = int(input("Ingrese un numero para verificar que es primo"))
def primo(num):
 if num < 2: 
   return False
 for i in range(2, num): 
   if num % i == 0: 
    return False
 return True 
print(primo(num))

#Ejercicio 4
x=int(input("Un número: "))
y=int(input("Otro número: "))
def maximo(x,y):
 if x > y : 
     return x
 else:
     return y
         
def minimo(x,y):
 if (x < y):
     return x
 else:
     return y

print(maximo(x-3, minimo(x+2, y-5))) 
#Se debia poner x y y en ves de a y b en la funcion
#Ejercicio 5
#Imprime 20
