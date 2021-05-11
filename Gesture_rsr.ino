/*
Code By RADEARSR
*/
const int R_trig = 5;
const int R_echo = 4;
const int L_trig = 3;
const int L_echo = 2;
int jarak,jarak_R,jarak_L;
long waktu;

void setup() {
  Serial.begin(9600);
  pinMode(R_trig, OUTPUT);
  pinMode(R_echo, INPUT);
  pinMode(L_trig, OUTPUT);
  pinMode(L_echo, INPUT);
}

void loop() {
 // Sensor HC-SR04 KANAN
 digitalWrite(R_trig,LOW);
 delayMicroseconds(2);
 digitalWrite(R_trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(R_trig,LOW);
 waktu = pulseIn(R_echo,HIGH);
 jarak = waktu/58.8;
 jarak_R = jarak;
 /*Serial.print("SENSOR KANAN : ");
 Serial.println(jarak_R);
 delay(500);*/
 
// Sensor HC-SR04 KIRI
 digitalWrite(L_trig, LOW);
 delayMicroseconds(2);
 digitalWrite(L_trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(L_trig,LOW);
 waktu = pulseIn(L_echo,HIGH); 
 jarak = waktu/58.8;
 jarak_L = jarak;
/* Serial.print("SENSOR KIRI : ");
 Serial.println(jarak_L);
 delay(1000);*/

 // Fungsi Sensor Pause/Play
 if ((jarak_L >= 20 && jarak_R >= 20 ) && (jarak_L <= 40 && jarak_R <= 40)){
  Serial.println("PAUSE/PLAY");
  delay(2000);
 } 
 // Fungsi Volume
 else if((jarak_R >= 2) && (jarak_R <= 13)){
  Serial.println("VolUp");
  delay(100);
}
else if ((jarak_R >= 14) && (jarak_R <= 25)){
  Serial.println("VolDown");
  delay(100);
}
// Fungsi Mempercepat
else if ((jarak_L >= 2) && (jarak_L <= 16)){
  Serial.println("maju");
  delay(100);
}
else if ((jarak_L >= 17) && (jarak_L <=25)){
  Serial.println("mundur");
  delay(100);
}
}
