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