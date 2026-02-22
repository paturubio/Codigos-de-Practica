//Patricia Rubio 2ECA 
//Maquina Expendedora con RFID
//Llamando librerias
#include <MFRC522.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <SPI.h>
//Defiendo los pines de el RFID
#define SS_PIN 53
#define RST_PIN 5
MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27,16,2);  // Configurando el led en 0x27 con 16 pines en 2 lineas
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
  SPI.begin();
  //Para que imprima la clave UID de la tarjeta que necesitaremos para la condicional 
  Serial.println("Lectura del UID");
 //Ponemos como salida los pulsadores y definimos sus pines
  pinMode(OUTPUT, 13);
  pinMode(OUTPUT, 12);
  pinMode(OUTPUT, 11);
  pinMode(OUTPUT, 10);
  }
void loop()
{

//Colocamos una variable a cada pulsador
a = digitalRead(13);
b = digitalRead(12);
c = digitalRead(11);
d = digitalRead(10);
switch (D){
case 1 :
  /// condicionando a //
if (a == 0)
{
  lcd.setCursor(0,0);
  lcd.clear();
//SEGUNDOS TEXTOS MOSTRADOS
  lcd.print(" $0.25  ");
  lcd.setCursor(1,1);
   lcd.print("pase su tarjeta");
  lcd.setCursor(4,1);
  delay(3000); //TIEMPO EN PANTALLA
 
//Activamos el RFID para que detecte la tarjeta
if(rfid.PICC_IsNewCardPresent())
{
  //Si hay tarjeta activa el Serial
  if(rfid.PICC_ReadCardSerial())
  {
    //Lee el UID de la tarjeta
    Serial.print("Card UID:");
    for(byte i =0; i < rfid.uid.size; i++){
      Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(rfid.uid.uidByte[i], HEX);
    }
  Serial.println();
 //Termina de leer la tarjeta
  rfid.PICC_HaltA();
 // Condicionamos que si la clave de la tarjeta es la leida de paso a activar el Servo motor
  if("67 2D 05 62"){
  //Seleccionamos el pin para el Servo
  servo.attach(3);
  //Colocamos hacia que direccion girara en grados
  servo.write(-100);
  //tiempo para los giros
  delay(1000);
  servo.detach();
  delay(1000);
  //limpiamos el lcd
  lcd.clear();
//Ultimo texto mostrado
  lcd.print("Tome su producto");
//tiempo para limpiar pantalla
  delay(2000);
    }    
  }
}
} 
break;
}

}
//FINAL
