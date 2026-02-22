//Patricia Rubio
//Maquina Expendedora con RFID
//Llamando librerias
#include <MFRC522.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <SPI.h>
//Defiendo los pines de el RFID
#define SS_PIN 53 // SDA 
#define RST_PIN 5 // RST
// PARA MEGA CONECTAMOS EL SDA O SS  EN PIN 53 , RST EN PIN 5 , MISO PIN 50 , MOSI PIN 51 , SCK PIN 52 EL IRQ NO SE CONECTA.
MFRC522 rfid(SS_PIN, RST_PIN);
#define NR_OF_READERS   1

byte ssPins[] = {SS_PIN};
void mostrarByteArray(byte* buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }}
MFRC522 mfrc522[NR_OF_READERS]; 
LiquidCrystal_I2C lcd(0x27,16,2);  // Configurando el led en 0x27 con 16 pines en 2 lineas PIN 21 SCL Y 22 SDA 
Servo servo;// Definiendo como se mandara a llamar los servos
const int D = 1;
int  a , b , c , d; // VARIABLES PARA LOS PULSADORES
void setup()  
{
  rfid.PCD_Init();//Iniciamos el RFID
  lcd.init(); // Iniciamos el LCD
  lcd.backlight();//Encendemos la luz de fondo
  lcd.setCursor(0,0);//Colocamos la posicion en pantalla de el primer Texto
  //PRIMER TEXTO MOSTRADO
  lcd.clear();
  lcd.print("Presione un");
  lcd.setCursor(1,1);
  lcd.print("boton");
  lcd.setCursor(4,1);
  delay(1500);
  //Activamos el monitor serial
  Serial.begin(9600);
while (!Serial); 
  SPI.begin();
  //Para que imprima la clave UID de la tarjeta que necesitaremos para la condicional 
  Serial.println("Lectura del UID");
 //Ponemos como entrada los pulsadores y definimos sus pines
  pinMode(INPUT, 13);
  pinMode(INPUT, 12);
  pinMode(INPUT, 11);
  pinMode(INPUT, 10);
  pinMode(OUTPUT, 7);
  pinMode(OUTPUT, 6);
  pinMode(OUTPUT, 4);
  pinMode(OUTPUT, 3);
  }
void loop(){
//Colocamos una variable a cada pulsador
a = digitalRead(13);
b = digitalRead(12);
c = digitalRead(11);
d = digitalRead(10);

switch(D){
  case 1:
  /// condicionando a //
if (a == 0)
{
  lcd.clear();
//SEGUNDOS TEXTOS MOSTRADOS
  lcd.print(" $0.25  ");
  lcd.setCursor(1,1);
   lcd.print("pase su tarjeta");
  lcd.setCursor(4,1);
  delay(1000); //TIEMPO EN PANTALLA

//Activamos el RFID para que detecte la tarjeta
if(rfid.PICC_IsNewCardPresent())
{ 
  return;}
  //Si hay tarjeta activa el Serial
  if(rfid.PICC_ReadCardSerial())
  {
    return;}
    //Lee el UID de la tarjeta
  Serial.print(F("UID de la tarjeta:"));
  mostrarByteArray(rfid.uid.uidByte, rfid.uid.size);  // Motrar el UID
  Serial.println();
  Serial.print(F("Tipo de tarjeta: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);  //Motrar el tipo
  Serial.println(rfid.PICC_GetTypeName(piccType));
  Serial.println();
  Serial.print("Card UID:");
    for(byte i =0; i < rfid.uid.size; i++){
      Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(rfid.uid.uidByte[i], HEX);}
 //Termina de leer la tarjeta
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  Serial.println();
  Serial.println(F("Proceso finalizado. Ya puedes retirar la tarjeta del lector RFID"));
while (true);
 // Condicionamos que si la clave de la tarjeta es la leida de paso a activar el Servo motor
  if("67 2D 05 62"){
  //Seleccionamos el pin para el Servo
  servo.attach(3);
  //Colocamos hacia que direccion girara en grados
  servo.write(100);
  //tiempo para los giros
  delay(1000);
  servo.write(-100);
  delay(1000);
  servo.detach();
  delay(1000);
  //limpiamos el lcd
  lcd.clear();
//Ultimo texto mostrado
  lcd.print("Tome su producto");
  lcd.setCursor(4,1);
//tiempo para limpiar pantalla
  delay(2000);
    }    
 
}
 break;
}
}




//FINAL
