int pinAnalogicoCapacitive = A0;   // Entrada analogica sensor capacitivo
int pinAnalogicoLluvia = A1;      // Entrada analogica sensor de lluvia
int valorDigitalCapacitivo = 0;  // almacen valor digital analogico ya en digital 
int valorDigitalLluvia = 0;     // almacen valor digital analogico ya en digital
int valorSeco = 650;           // CAMBIAR tras calibrar (valor al aire = seco )
int valorMojado = 400;        // CAMBIAR tras calibrar (en agua = humedo)
int humedad = 0;
int lectura;

void setup() {
  Serial.begin(9600); // Inicia comunicación serie
}

void loop() {
  // SENSOR CAPACITIVO
  int lecturaCap = analogRead(pinAnalogicoCapacitive);
  humedad = map(lecturaCap, valorSeco, valorMojado, 0, 100);
  humedad = constrain(humedad, 0, 100);

  // SENSOR LLUVIA
  int lecturaLluvia = analogRead(pinAnalogicoLluvia);

  // ENVÍO LIMPIO PARA RASPBERRY
  Serial.print("SOIL=");
  Serial.print(humedad);
  Serial.print(",RAIN=");
  Serial.println(lecturaLluvia);

  delay(1000);
}
