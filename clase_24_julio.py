# numero 1 para VOLTAJE
R1 = int(input("Ingrese la resistencia"))
C1= int(input("Ingrese la corriente"))

def Voltaje(Resistencia , Corriente):
    return Resistencia*Corriente

resultado = (Voltaje(R1,C1))
print ("El resultado es ", resultado , "voltios")

#numero 2 para RESISTENCIA
R1= int(input("Ingrese el Voltaje"))
C1= int(input("Ingrese la Corriente"))

def  Resistencia (Voltaje , Corriente):
    return Voltaje / Corriente

resultado = (Resistencia(R1,C1))
print ("El resultado es ", resultado , "ohmios")

#numero 3 para CORRIENTE
R1= int(input("Ingrese el Voltaje"))
C1= int(input("Ingrese la Resistencia"))

def  Corriente (Voltaje , Resistencia):
    return Voltaje / Resistencia

resultado = (Corriente(R1,C1))
print ("El resultado es ", resultado , "amperios")