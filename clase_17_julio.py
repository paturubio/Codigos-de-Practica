def voltaje (corriente,resistencia):
    return corriente*resistencia

resultado = (voltaje (12,10))
print (resultado)

def hola ():
    print('hola')
    return

def swap (x,y):
    temp = x
    x = y 
    y = temp 
x= 2
y= 3
swap (x,y)
print(x)
print(y)

def greet ():
    print('!Hola amigos!')
    return
    greet

greet()
def greet (nombre, apellido):
    print ('Hola' + nombre + '!')
    return
greet ('Alif', 'Solo')

def iva (precio, impuesto = 21):
    return precio + precio * impuesto /100
    print (iva(25,13))
    print (iva(100))

def cAlCorriente():
    return

def cAlResistencia():
    return
def cAlVoltaje():
    return

R1 = int(input("Ingrese la resistencia"))
C1= int(input("Ingrese la corriente"))

def Voltaje(Resistencia , Corriente):
    return Resistencia*Corriente

resultado = (Voltaje(R1,C1))
print ("El resultado es ", resultado , "v")
