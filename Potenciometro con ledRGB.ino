/******************************************************************************
* Programa que mapea a entrada dun potenciómetro a cinco cores.
* Usaremos un Led Rgb pra simulación dun control mediante potenciómetro
* de maneira que este actúe como entrada e a saida sexa un numero determinado de niveis
* 
* 
*
* Autor: Javi Figueiro
* Data: Marzo 2024
* 
****************************************************************************/

int potPin = A0;
int rPin = 3;
int gPin = 5;
int bPin = 6;

void setup() {
  pinMode(potPin, INPUT);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);
  
  int color = map(potValue, 0, 1023, 16250, 123565);
  
  int r = color >> 16;
  int g = (color & 0x00FF00) >> 8;
  int b = color & 0x0000FF;
  
  analogWrite(rPin, r);
  analogWrite(gPin, g);
  analogWrite(bPin, b);
  
  Serial.print("Decimal: ");
  Serial.print(color);
  Serial.print("  -  Hexadecimal: ");
  Serial.print(color, HEX);
  Serial.print("  -  Binario: ");
  Serial.println(color, BIN);
  
  delay(100);
}
