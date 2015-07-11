/**
License

THE BEER-WARE LICENSE" (Revision 42):
[phk@FreeBSD.ORG]() wrote this file. As long as you retain this notice you
can do whatever you want with this stuff. If we meet some day, and you think
this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
**/

#define pinLDR 0
#define pinRed 11
#define pinGreen 10
#define pinBlue 9

float RGB1[3];
float RGB2[3];
float INC[3];

int ambientLight;
int red, green, blue;

void setup()
{
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, LOW);
  digitalWrite(pinBlue, LOW);
  
  randomSeed(analogRead(1));
  
  RGB1[0] = 0;
  RGB1[1] = 0;
  RGB1[2] = 0;
  
  RGB2[0] = random(256);
  RGB2[1] = random(256);
  RGB2[2] = random(256);
}

void loop()
{
  randomSeed(analogRead(1));  
  ambientLight = analogRead(pinLDR);
    
  for(int x=0; x<3; x++)
  {
    INC[x] = (RGB1[x] - RGB2[x]) / 256;
  }
  
  for(int x=0; x< 256; x++)
  {
    red = int(RGB1[0]);
    green = int(RGB1[1]);
    blue = int(RGB1[2]);
    
    if(ambientLight > 600)
    {   
      analogWrite(pinRed, red);
      analogWrite(pinGreen, green);
      analogWrite(pinBlue, blue);
      delay(50);
    }
    else
    {
      digitalWrite(pinRed, LOW);
      digitalWrite(pinGreen, LOW);
      digitalWrite(pinBlue, LOW);
    }
    
    RGB1[0] -= INC[0];
    RGB1[1] -= INC[1];
    RGB1[2] -= INC[2];
  }
  
  for(int x=0; x<3; x++)
  {
    RGB2[x] = random(556) - 300;
    RGB2[x] = constrain(RGB2[x], 0, 255);
    delay(200);
  }
}
