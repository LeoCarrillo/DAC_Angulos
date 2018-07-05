//ADc_Angulos.ino
//leocarrillo
double grados =0;
int a1 = 2;
const int a=4;
const int b=14;
const int c=15;
const int d=3;
const int e=9;
const int f=5;
const int g=7;
//pines display 2
const int a2=8;
const int b2=6;
const int c2=2;
const int d2=11;
const int e2=10;
const int f2=12;
const int g2=13;
 int valor_en_ang_un=0;
 int valor_en_ang_dec=0;
 int valtotal=0;
//pin led
const int led=16;
//pin de entrada para el potenciómetro 
int sensorPin = 0;    
// variable para almacenar el valor que ofrece el sensor
int sensorValue = 0;  
// variable de valor de decenas y unidades del display
int un = 0;
int de = 0;
int cen = 0;
int angulo = 0;
double op = 0;
double hip = 0;

//Función para el display de unidades
boolean und(int x){
switch(x){
case 0: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, LOW);valor_en_ang_un=0; break;
case 1: digitalWrite(a, LOW);  digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW);valor_en_ang_un=1; break;
case 2: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, LOW); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, HIGH);valor_en_ang_un=2; break;
case 3: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, HIGH);valor_en_ang_un=3; break;
case 4: digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, HIGH);valor_en_ang_un=4; break;
case 5: digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, HIGH);valor_en_ang_un=5; break;
case 6: digitalWrite(a, HIGH);  digitalWrite(b, LOW); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH);valor_en_ang_un=6; break;
case 7: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW);valor_en_ang_un=7; break;
case 8: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH);valor_en_ang_un=8; break;
case 9: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, HIGH);valor_en_ang_un=9; break;
default: digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, HIGH); digitalWrite(d, LOW); digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, HIGH);valor_en_ang_un=0; break;
}
delay(250);
return a,b,c,d,e,f,g,valor_en_ang_un;
}
//Función para el display de decenas
boolean dec(int x){
switch(x){
case 0: digitalWrite(a2, HIGH); digitalWrite(b2, HIGH); digitalWrite(c2, HIGH); digitalWrite(d2, HIGH); digitalWrite(e2, HIGH); digitalWrite(f2, HIGH); digitalWrite(g2, LOW);valor_en_ang_dec=0; break;
case 1: digitalWrite(a2, LOW);  digitalWrite(b2, HIGH); digitalWrite(c2, HIGH); digitalWrite(d2, LOW); digitalWrite(e2, LOW); digitalWrite(f2, LOW); digitalWrite(g2, LOW);valor_en_ang_dec=10; break;
case 2: digitalWrite(a2, HIGH); digitalWrite(b2, HIGH); digitalWrite(c2, LOW); digitalWrite(d2, HIGH); digitalWrite(e2, HIGH); digitalWrite(f2, LOW); digitalWrite(g2, HIGH);valor_en_ang_dec=20; break;
case 3: digitalWrite(a2, HIGH); digitalWrite(b2, HIGH); digitalWrite(c2, HIGH); digitalWrite(d2, HIGH); digitalWrite(e2, LOW); digitalWrite(f2, LOW); digitalWrite(g2, HIGH);valor_en_ang_dec=30; break;
case 4: digitalWrite(a2, LOW); digitalWrite(b2, HIGH); digitalWrite(c2, HIGH); digitalWrite(d2, LOW); digitalWrite(e2, LOW); digitalWrite(f2, HIGH); digitalWrite(g2, HIGH);valor_en_ang_dec=40; break;
case 5: digitalWrite(a2, HIGH); digitalWrite(b2, LOW); digitalWrite(c2, HIGH); digitalWrite(d2, HIGH); digitalWrite(e2, LOW); digitalWrite(f2, HIGH); digitalWrite(g2, HIGH);valor_en_ang_dec=50; break;
case 6: digitalWrite(a2, HIGH);  digitalWrite(b2, LOW); digitalWrite(c2, HIGH); digitalWrite(d2, HIGH); digitalWrite(e2, HIGH); digitalWrite(f2, HIGH); digitalWrite(g2, HIGH);valor_en_ang_dec=60; break;
case 7: digitalWrite(a2, HIGH); digitalWrite(b2, HIGH); digitalWrite(c2, HIGH); digitalWrite(d2, LOW); digitalWrite(e2, LOW); digitalWrite(f2, LOW); digitalWrite(g2, LOW);valor_en_ang_dec=70; break;
case 8: digitalWrite(a2, HIGH); digitalWrite(b2, HIGH); digitalWrite(c2, HIGH); digitalWrite(d2, HIGH); digitalWrite(e2, HIGH); digitalWrite(f2, HIGH); digitalWrite(g2, HIGH);valor_en_ang_dec=80; break;
case 9: digitalWrite(a2, HIGH); digitalWrite(b2, HIGH); digitalWrite(c2, HIGH); digitalWrite(d2, HIGH); digitalWrite(e2, LOW); digitalWrite(f2, HIGH); digitalWrite(g2, HIGH);valor_en_ang_dec=90; break;
default: digitalWrite(a2, LOW); digitalWrite(b2, LOW); digitalWrite(c2, HIGH); digitalWrite(d2, LOW); digitalWrite(e2, LOW); digitalWrite(f2, LOW); digitalWrite(g2, HIGH);valor_en_ang_dec=0; break;
}
return a2,b2,c2,d2,e2,f2,g2,valor_en_ang_dec;

}

void setup() {
Serial.begin(9600);
pinMode(a, OUTPUT); pinMode(b, OUTPUT); pinMode(c, OUTPUT); pinMode(d, OUTPUT); pinMode(e, OUTPUT); pinMode(f, OUTPUT); pinMode(g, OUTPUT);
pinMode(a2, OUTPUT); pinMode(b2, OUTPUT); pinMode(c2, OUTPUT); pinMode(d2, OUTPUT); pinMode(e2, OUTPUT); pinMode(f2, OUTPUT); pinMode(g2, OUTPUT);
pinMode(led,OUTPUT); 
pinMode(16, INPUT);
 pinMode(17, INPUT);}

void loop() {
 if(digitalRead(17)==LOW)
 {
  a1=a1+1;
 }
 if(digitalRead(16)==LOW)
 {
  a1=a1-1;
 }
  // lee el valor del sensor:
 sensorValue = analogRead(sensorPin);
  if(Serial.available()!=0)
  {
    int k=45;
    delay(100);
    Serial.println("      ***************seleccione la opcion************ ");
    Serial.println("       ");
    Serial.println(" **** 1 para ver lado opuesto, 0 para ver la hipotenusa ****  ");
    Serial.println("                **** 3 para elimminar datos ****  ");
    delay(500);
    while(Serial.available()==0){}
    k=Serial.parseInt();
  valtotal = (valor_en_ang_un) + (valor_en_ang_dec);
 delay(100);
 grados = valtotal*(3.1415/180);
  if(k==1){
    k=45;
  op =(tan(grados)*a1)+6.4;Serial.println("el lado Opuesto tiene ");Serial.println(op);Serial.println("el lado Adyacente tiene ");Serial.println(a1);Serial.println(" tiene un algulo de ");Serial.println(valtotal);}
 if (k==0)
   { 
    k=45; hip = (a1/cos(grados));Serial.println(" la Hipoteusa tiene ");Serial.println(hip);Serial.println("el lado Adyacente tiene ");Serial.println(a1);Serial.println(" tiene un algulo de ");Serial.println(valtotal);}
 if(k == 3 ){a1 =2;}
   else{}
   k=45;
 }else{}
 //de 0 a 10
 if (sensorValue<166)
   {angulo=sensorValue*0.4348-62.1739;
   }
 // de 10 a 20 
 else if (sensorValue>166&&sensorValue<200)
  {angulo=sensorValue*0.2941-38.8235;}
 // de 20 a 30
else if (sensorValue>200&&sensorValue<233)
  {angulo=sensorValue*0.303-40.606;}  
 // de 30 a 40
 else if (sensorValue>233&&sensorValue<260)
  {angulo=sensorValue*0.3704-56.2962;}
 // de 40 a 50
  else if (sensorValue>260&&sensorValue<300)
  {angulo=sensorValue*0.25-25;}
 // de 50 a 60
  else if (sensorValue>300&&sensorValue<330)
  {angulo=sensorValue*0.3333-50;}
 // de 60 a 70 
  else if (sensorValue>330&&sensorValue<363)
  {angulo=sensorValue*0.303-40;}
 // de 70 a 80 
  else if (sensorValue>363&&sensorValue<390)
  {angulo=sensorValue*0.3704-64.4444;}
 // de 80 a 90 
  else if (sensorValue>390&&sensorValue<426)
  {angulo=sensorValue*0.2778-28.3333;}
 // de 90 a 120 
  else if (sensorValue>426&&sensorValue<523)
  {angulo=sensorValue*0.30927-41.7526;}
 // de 120 a 150 
  else if (sensorValue>523&&sensorValue<610)
  {angulo=sensorValue*0.3448-60.3448;}
 // de 150 a 180 
  else if (sensorValue>610&&sensorValue<693)
  {angulo=sensorValue*0.36144-70.4819;}
 // fuera del rango 
  else
  {angulo=0;}
 
 //angulo = (sensorValue*99)/1024;
 un= angulo % 10;
 de= (angulo/10) % 10;
 cen= (angulo/10)/10;
 
 dec(de); und(un);
 if (cen==1)
   {digitalWrite(led, HIGH);}
 else
   {digitalWrite(led, LOW);}
 
}
