#Examen de Python P3A ( PATRICIA RUBIO 2ECA )
""" Ejercicio 1: Resolver un algoritmo encargado de determinar si un número dado es par e imprimir el mensaje
Es par o por el contrario si es impar deberás imprimir Es impar. Este proceso se deberá repetir
para cada numero de 1 Hasta 100 """

print ("NUMEROS")

num=int (input('Escribe un numero del 1 al 100'))

if num % 2 == 0 :
    print ("Este numero es par")

if num % 2 != 0:
        print ("Este numero es impar")

""" Ejercicio 2: Escribir un programa que pregunte al usuario el nombre y la edad y este determine si es mayor
de edad y que imprima los datos en consola """
print("EDAD")
print ("Introduce tu nombre")
nombre = input()
num = int(input("Introduce tu edad"))

for i in range ( num >= 18):
    print("Usted es mayor de edad")

""" Ejercicio 3 :Escriba un programa que pida dos números enteros y que calcule su división, 
escribiendo si la división es exacta o no """
print ("DIVISOR")
num_1 = int(input("Escriba un dividendo"))
num_2 = int(input(" Escriba un divisor"))
if num_1 % num_2 == 0:
    print("Esta division es exacta")
if num_1 % num_2 != 0:
    print("Esta division es inexacta")

""" Ejercicio 4 :Escriba un programa que pregunte primero si se quiere calcular el área de un triángulo o
la de un círculo. Si se contesta que se quiere calcular el área de un triángulo (escribiendo T o t), el
programa tiene que pedir entonces la base y la altura y escribir el área. Si se contesta que se
quiere calcular el área de un círculo (escribiendo C o c), el programa tiene que pedir entonces el
radio y escribir el área. Se recuerda que el área de un triángulo es base por altura dividido por 2 y
que el área de un círculo es Pi (aproximadamente 3,141592) por el radio al cuadrado
 Nota: Utilice como valor de pi el valor 3.141592."""
print ("AREAS GEOMETRICAS")
import math
print("Calcular Áreas de figuras Geométricas.\n")
print("T : triangulo\nC : Circulo.\n ")
pregunta= input("Escoja la figura con 1 o 2 en el siguiente apartado escriba OK para proceder")
x = int (input("Escriba 1 si quiere triangulo y Escriba 2 si quiere circulo"))

if (x == 1):
            b = int(input("Ingrese su base :"))
            A = int(input("Ingrese su altura"))
            Area_T = b*A/2
            print ("Su area es ",Area_T)
      
if (x == 2): 
            r = int(input("Ingrese un radio"))
            pi = 3.141592
            Area_C = pi*r*r
            print ("Su area es " ,Area_C)
#Lo hice con numeros porque no pude con letras me estaba tardando demasiado y se me acabaria el tiempo :c
""" Ejercicio 5 :Mostrar suma - Mejore el programa anterior haciendo que el programa escriba la suma realizada"""
print ("MUESTRA SUMA")
print("SUMA DE VALORES.\n")
print("Escriba un entero positivo")
num_1= int(input(""))
print("Escriba otro entero positivo")
num_2 = int(input(""))

for total in [num_1 + num_2]:
    print("Este es tu resultado", total)

for range in (num_1,num_2):
    print("suma = ", num_1 ," + ",  num_2 , "=", total)