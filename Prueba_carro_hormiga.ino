const int Trigger  = 9 ;//Variable que contiene el n�mero del pin al cual conectamos la se�al "trigger"
const int Echo =  8 ;  //Variable que contiene el n�mero del pin al cual conectamos la se�al "echo"

void setup() {
Serial.begin(9600);//Configuramos la comunicaci�n serial
pinMode(Trigger, OUTPUT); //pin como salida
pinMode(Echo, INPUT);  //pin como entrada
digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}

void loop()
{
long t; //timepo que demora en llegar el eco
long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);            //Nos mantenemos en esta l�nea durante 100ms antes de terminar el loop
}
