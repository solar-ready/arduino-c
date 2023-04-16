//Solar ready
#include <Servo.h>
Servo servo;   // Crie um objeto servo para controlar o servo
int eLDRPin = A0; // Atribuir pinos aos LDR's
int wLDRPin = A1;
int eastLDR = 0; //Crie variáveis ​​para armazenar nas leituras LDRs
int westLDR = 0;
int difference = 0; //Crie uma variável para comparar os dois LDRs.
int error = 10;  // Variável para verificar se existe uma diferença notável entre os dois LDRs.
int servoSet = 130; //Variável para a posição do servo - será diferente para cada dispositivo
void setup() {
 servo.attach(9);   //Anexa o objeto servo ao pino PWM 9.
 Serial.begin(9600); 
}
void loop() {
 eastLDR = analogRead(eLDRPin); //Leia os valores dos LDRs.
 westLDR = analogRead(wLDRPin);
 if (eastLDR < 400 && westLDR < 400) {  //Verifique se há pouca luz em ambos os LDRs.
   while (servoSet <= 140 && servoSet >=15) {     //Se sim, envie os painéis de volta para o leste para o nascer do sol.
     servoSet ++;
     servo.write(servoSet);
     delay(100);
   }
 }
 difference = eastLDR - westLDR ; //Verifique a diferença
 if (difference > 10) {          //Envie o painel na direção do LDR com uma leitura mais alta.
   if (servoSet <= 140) {
     servoSet ++;
     servo.write(servoSet);
   }
 } else if (difference < -10) {
   if (servoSet >= 15) {
     servoSet --;
     servo.write(servoSet);
   }
 }
    


 Serial.print(eastLDR);
  Serial.print(", ");
  Serial.print(westLDR);
  Serial.print(", ");
  Serial.print(difference);
  Serial.println(", ");
  Serial.print(servoSet);
  Serial.print(" ");
 delay(2000);}