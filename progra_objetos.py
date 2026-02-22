class Saludo :
      mensaje = "saludo"
      
      def saludar (self, nombre):
            print(self.mensaje + nombre)
            return

s = Saludo()
s.saludar("Patricia")

class Tarjeta:

      def __init__(self , id , cantidad = 0 ):
          self.id = id
          self.saldo = cantidad

      def mostrar_saldo(self):
            print('El saldo es ' , self.saldo, '$')
            return
t = Tarjeta ('111111111111111111', 1000)
t.muestra_saldo()
