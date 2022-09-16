#include <Arduino.h>
#include <stdio.h>
int speeed = 54, spd, x = 0, cm1, cml1, timeerr = 0, ind, timeell = 0, cmr1, tt = 0, cdl, cdr, cm2, cml2, ss, sss, cmr2, old_d = 0, old_millis, v = 0, ii = 0, d, p, I = 0, ch[100], chr[100], o, D, milllis, b = 0, tiime, o_time, Time[100], shoort[100], Timer[100], Timel[100], shoortR[100], TimesR[100], sl, sr;
String A = ";";
float kp = 0.0025, kd = 0, ki = 0;
int moode = 0;
#define push_button PA2
#define in1 PB5
#define in2 PB4
#define enA PB7
#define in11 PB3
#define in22 PA15
#define enAA PB6
#define anaIRSensorm1 PA6
#define anaIRSensormleft1 PA5
#define anaIRSensormright1 PA4
#define digIRSensorm1 PA9
#define digIRSensormleft1 PA8
#define digIRSensormright1 PA10
#define anaIRSensorm2 PB0
#define anaIRSensormleft2 PA7
#define anaIRSensormright2 PA1
#define anaIRSensordirleft PB1
#define anaIRSensordirright PA0
#define digIRSensorm2 PB15
#define digIRSensormleft2 PB14
#define digIRSensormright2 PB8
#define digIRSensordirleft PB13
#define digIRSensordirright PB9
void rotation()
{
  cm1 = sensorm1();
  cmr1 = sensormr1();
  cml1 = sensorml1();
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enAA, 45);
  analogWrite(enA, 45);
  while (cml1 != 0)
  {
    delay(1);

    cml1 = sensorml1();
  }
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in11, HIGH);
  digitalWrite(in22, LOW);
  analogWrite(enAA, 200);
  analogWrite(enA, 200);
  delay(15);
  analogWrite(enA, 0);
  analogWrite(enAA, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in11, LOW);
  digitalWrite(in22, HIGH);

  cdr = sensordr();
  cdl = sensordl();
  cml1 = sensorml1();
  cml2 = sensorml2();
  cm1 = sensorm1();
  cm2 = sensorm2();
  cmr1 = sensormr1();
  cmr2 = sensormr2();
  while (cdl == 0 || cdr == 0 || cmr1 != 0 || cml1 != 0 || cm1 != 0 || cm2 != 0)
  {
    cdr = sensordr();
    cdl = sensordl();
    cml1 = sensorml1();
    cml2 = sensorml2();
    cm1 = sensorm1();
    cm2 = sensorm2();
    cmr1 = sensormr1();
    cmr2 = sensormr2();
    forward(speeed);
    delayMicroseconds(10);
  }
}
void right()
{
  //Lecture des capteurs:
  cmr1 = sensormr1();
  cmr2 = sensormr2();
  cml2 = sensorml2();
  cm1 = sensorm1();
  //Initialisation des mouvments des moteurs
  analogWrite(enA, 55);
  analogWrite(enAA, 0);
  digitalWrite(in11, HIGH);
  digitalWrite(in22, LOW);
  analogWrite(enAA, 200);
  delay(80);
  digitalWrite(in11, LOW);
  digitalWrite(in22, HIGH);
  analogWrite(enAA, 0);
  //Boucle pour attendre que tous les capteurs avant soient en zone blanche
  while (cm1 == 0 || cmr2 == 0 || cml2 == 0 || cmr1 == 0 || cml1 == 0)
  {
    delay(5);
    cmr1 = sensormr1();
    cml1 = sensorml1();

    cmr2 = sensormr2();
    cml2 = sensorml2();
    cm1 = sensorm1();
  }
  //On attend que le capteur centrale soit de nouveau sur la ligne noir
  while (cmr1 != 0)
  {
    delay(1);
    cmr1 = sensormr1();
  }
//On lance le moteur gauche en inverse pour un breve instant pour arreter la rotation
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 240);
  delay(30);
  analogWrite(enA, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in11, LOW);
  digitalWrite(in22, HIGH);
  cdl = sensordl();
  cdr = sensordr();
  cm1 = sensorm1();
  //On lace un mouvement en avant jusqu'a ce que le robot soit en bonne orientation:
  while (cdl == 0 || cdr == 0 || cmr1 != 0 || cml1 != 0 || cm1 != 0 || cm2 != 0)
  {
    cdr = sensordr();
    cdl = sensordl();
    cml1 = sensorml1();
    cml2 = sensorml2();
    cm1 = sensorm1();
    cm2 = sensorm2();
    cmr1 = sensormr1();
    cmr2 = sensormr2();
    forward(speeed);
    delayMicroseconds(10);
  }
}

void left()
{  //Lecture des capteurs::
  cml1 = sensorml1();
   cml2 = sensorml2();
  cmr2 = sensormr2();
  cmr1 = sensormr1();
  cm1 = sensorm1();
  //On initialize le mouvement des roues
  analogWrite(enAA, 55);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  delay(80);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 0);



  while (cm1 == 0 || cmr2 == 0 || cml2 == 0 || cmr1 == 0 || cml1 == 0)
  {
    delay(5);
    cmr1 = sensormr1();
    cml1 = sensorml1();

    cmr2 = sensormr2();
    cml2 = sensorml2();
    cm1 = sensorm1();
  }
  while (cml1 != 0)
  {
    delay(1);
    cml1 = sensorml1();
  }
  digitalWrite(in11, HIGH);
  digitalWrite(in22, LOW);
  analogWrite(enAA, 240);
  delay(30);
  digitalWrite(in11, LOW);
  digitalWrite(in22, HIGH);
  analogWrite(enAA, 0);
  cdl = sensordl();
  cdr = sensordr();
  cm1 = sensorm1();
  while (cdl == 0 || cdr == 0 || cmr1 != 0 || cml1 != 0 || cm1 != 0 || cm2 != 0)
  {
    cdr = sensordr();
    cdl = sensordl();
    cml1 = sensorml1();
    cml2 = sensorml2();
    cm1 = sensorm1();
    cm2 = sensorm2();
    cmr1 = sensormr1();
    cmr2 = sensormr2();
    forward(speeed);
    delayMicroseconds(10);
  }
}
void stoop()
{
  spd = speeed;
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in11, HIGH);
  digitalWrite(in22, LOW);
  analogWrite(enAA, 255);
  analogWrite(enA, 255);
  delay(speeed / 2);
  analogWrite(enAA, 0);
  analogWrite(enA, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in11, LOW);
  digitalWrite(in22, HIGH);
}
void forward(int speeed)
{
  milllis = millis();
  cmr1 = sensormr1();
  cml1 = sensorml1();
  cmr2 = sensormr2();
  cml2 = sensorml2();
  cm1 = sensorm1();

  if (cml1 > 1500)
  {
    cml1 = 1500;
  }
  if (cml2 > 1500)
  {
    cml2 = 1500;
  }
  if (cmr1 > 1500)
  {
    cmr1 = 1500;
  }
  if (cmr2 > 1500)
  {
    cmr2 = 1500;
  }

  if (cm1 > 1500)
  {
    cm1 = 1500;
  }
  p = 3 * cmr1 + cmr2 - 3 * cml1 - cml2;
  //   if(cml2==0 && cm1>0){
  //    p=2*cmr1+cmr2+4*cml1+3*cm1-cml2;

  // }
  // else if (cmr2==0 && cm1>0)
  // {
  //   p=cmr2-4*cmr1-2*cml1-3*cm1-cml2;
  // }

  I = I + p;
  if (milllis - old_millis > 1)
  {

    d = (old_d - d);
    o = (kp * p + kd * d + ki * I);

    old_d = d;
    old_millis = milllis;
    I = 0;
  
  if (speeed - o < 0)
  {
    analogWrite(enA, 0);
  }
  else if (speeed - o > 255)
  {
    analogWrite(enA, 255);
  }
  else
  {
    analogWrite(enA, speeed - o);
  }
  if (speeed + o < 0)
  {
    analogWrite(enAA, 0);
  }
  else if (speeed + o > 255)
  {
    analogWrite(enAA, 255);
  }
  else
  {
    analogWrite(enAA, speeed + o);
  }}
  

  //   if( cm ==0 && cml==0 && cmr==0 )  {

  //    analogWrite(enA,speeed);

  //    Serial.print("s");
  //    analogWrite(enAA,speeed);
  //   }
  //  if( cmr!= 0 && cml==0 && cm==0)  {

  //    analogWrite(enA,speeed/1.5);
  //    Serial.print("L");
  //    analogWrite(enAA,speeed);

  //   }
  //  if( cml!= 0 && cm==0 && cmr==0)  {
  //    analogWrite(enA,speeed);
  //    Serial.print("R");
  //    analogWrite(enAA,speeed/1.5);
  //   }
}
int sensorm1()
{
  int am1, cm1, bm1;
  digitalWrite(digIRSensorm1, HIGH); // Turning ON LED
  delayMicroseconds(500);            //wait
  am1 = analogRead(anaIRSensorm1);   //take reading from photodiode :noise+signal
  digitalWrite(digIRSensorm1, LOW);  //turn Off LED
  delayMicroseconds(500);            //wait
  bm1 = analogRead(anaIRSensorm1);   // again take reading from photodiode :noise
  cm1 = bm1 - am1;                   //taking differnce:[ (noise+signal)-(noise)] just signal
  if (cm1<2000) cm1=0;
  return cm1;
}
int sensorml1()
{
  int aml1, cml1, bml1;

  //////////////////////////////midle sensor left st
  digitalWrite(digIRSensormleft1, HIGH); // Turning ON LED
  delayMicroseconds(500);                //wait
  aml1 = analogRead(anaIRSensormleft1);  //take reading from photodiode :noise+signal
  digitalWrite(digIRSensormleft1, LOW);  //turn Off LED
  delayMicroseconds(500);                //wait
  bml1 = analogRead(anaIRSensormleft1);  // again take reading from photodiode :noisae
  cml1 = bml1 - aml1;
   if (cml1<2000) cml1=0;                    //taking differnce:[ (noise+signal)-(noise)] just signal
  return cml1;
}
int sensormr1()
{
  int amr1, bmr1, cmr1;
  //////////////////////////////midle sensor right stm
  digitalWrite(digIRSensormright1, HIGH); // Turning ON LED
  delayMicroseconds(500);                 //wait
  amr1 = analogRead(anaIRSensormright1);  //take reading from photodiode :noise+signal
  digitalWrite(digIRSensormright1, LOW);  //turn Off LED
  delayMicroseconds(500);                 //wait
  bmr1 = analogRead(anaIRSensormright1);  // again take reading from photodiode :noise
  cmr1 = bmr1 - amr1;  
   if (cmr1<3000) cmr1=0;                   //taking differnce:[ (noise+signal)-(noise)] just signal
  return cmr1;
}
int sensorm2()
{
  int cm2, am2, bm2;
  //////////////////////////////midle sensor motor
  digitalWrite(digIRSensorm2, HIGH); // Turning ON LED
  delayMicroseconds(500);            //wait
  am2 = analogRead(anaIRSensorm2);   //take reading from photodiode :noise+signal
  digitalWrite(digIRSensorm2, LOW);  //turn Off LED
  delayMicroseconds(500);            //wait
  bm2 = analogRead(anaIRSensorm2);   // again take reading from photodiode :noise
  cm2 = bm2 - am2; 
   if (cm2<2000) cm2=0;                  //taking differnce:[ (noise+signal)-(noise)] just signal
  return cm2;
}
int sensorml2()
{
  int cml2, bml2, aml2;

  //////////////////////////////midle sensor left motor
  digitalWrite(digIRSensormleft2, HIGH); // Turning ON LED
  delayMicroseconds(500);                //wait
  aml2 = analogRead(anaIRSensormleft2);  //take reading from photodiode :noise+signal
  digitalWrite(digIRSensormleft2, LOW);  //turn Off LED
  delayMicroseconds(500);                //wait
  bml2 = analogRead(anaIRSensormleft2);  // again take reading from photodiode :noise
  cml2 = bml2 - aml2;    
   if (cml2<2000) cml2=0;                //taking differnce:[ (noise+signal)-(noise)] just signal
  return cml2;
}
int sensormr2()
{
  int cmr2, bmr2, amr2;

  //////////////////////////////midle sensor right motor
  digitalWrite(digIRSensormright2, HIGH); // Turning ON LED
  delayMicroseconds(500);                 //wait
  amr2 = analogRead(anaIRSensormright2);  //take reading from photodiode :noise+signal
  digitalWrite(digIRSensormright2, LOW);  //turn Off LED
  delayMicroseconds(500);                 //wait
  bmr2 = analogRead(anaIRSensormright2);  // again take reading from photodiode :noise
  cmr2 = bmr2 - amr2;   
   if (cmr2<2300) cmr2=0;                  //taking differnce:[ (noise+signal)-(noise)] just signal
  return cmr2;
}
int sensordr()
{
  int cdr, bdr, adr;
  //////////////////////////////direction sensor right
  digitalWrite(digIRSensordirright, HIGH); // Turning ON LED
  delayMicroseconds(500);                  //wait
  adr = analogRead(anaIRSensordirright);   //take reading from photodiode :noise+signal
  digitalWrite(digIRSensordirright, LOW);  //turn Off LED
  delayMicroseconds(500);                  //wait
  bdr = analogRead(anaIRSensordirright);   // again take reading from photodiode :noise
  cdr = bdr - adr; 
   if (cdr<2000) cdr=0;                        //taking differnce:[ (noise+signal)-(noise)] just signal

  return cdr;
}
int sensordl()
{
  int cdl, bdl, adl;

  //////////////////////////////direction sensor left
  digitalWrite(digIRSensordirleft, HIGH); // Turning ON LED
  delayMicroseconds(500);                 //wait
  adl = analogRead(anaIRSensordirleft);   //take reading from photodiode :noise+signal
  digitalWrite(digIRSensordirleft, LOW);  //turn Off LED
  delayMicroseconds(500);                 //wait
  bdl = analogRead(anaIRSensordirleft);   // again take reading from photodiode :noise
  cdl = bdl - adl;
   if (cdl<2000) cdl=0;
  return cdl;
}
void LH()
{
  cdr = sensordr();
  cdl = sensordl();
  cml1 = sensorml1();
  cml2 = sensorml2();
  cm1 = sensorm1();
  cm2 = sensorm2();
  cmr1 = sensormr1();
  cmr2 = sensormr2();
  o_time == millis();
  while (cdr != 0 || cm2 != 0 || cdl != 0 || cm1 != 0 || cmr1 != 0 || cml1 != 0 || cml2 != 0 || cmr2 != 0)
  {
    cdr = sensordr();
    cdl = sensordl();
    cml1 = sensorml1();
    cml2 = sensorml2();
    cm1 = sensorm1();
    cm2 = sensorm2();
    cmr1 = sensormr1();
    cmr2 = sensormr2();

    if (cdl == 0 && (cmr2 != 0 || cml2 != 0))
    {
      delay(2);
      cdl = sensordl();

      if (cdl == 0)
      {
        ii = 0;
        tiime = millis();
        Time[b] = tiime - o_time;
        o_time = tiime;
        left();
        ch[b] = 3;
        b++;
        v = 0;
      }
    }
    else if (cm1 == 0 || cml1 == 0 || cmr1 == 0)
    {
      if (cdr == 0)
      {
        delay(2);
        cdr = sensordr();
        cdl = sensordl();
        if (cdr == 0 && cdl != 0 && (cmr2 != 0 || cml2 != 0))
        {
          tiime = millis();
          Time[b] = tiime - o_time;
          o_time = tiime;
          ch[b] = 1;
          b++;
          while (cdr == 0)
          {
            forward(speeed);

            delay(1);
            cdr = sensordr();
          }
          v = 0;
          ii = 0;
        }
      }
      //      else if(cdr==0 && ii!=0){
      //      forward(speeed);
      //      v=0;

      //      }
      else
      {
        forward(speeed);
        v = 0;
        ii = 0;
      }
    }
    else if (cdr == 0 && (cmr2 != 0 || cml2 != 0))
    {
      delay(10);
      cdr = sensordr();
      cdl = sensordl();
      ii = 0;
      if (cdl != 0 && cdr == 0)
      {
        v = 0;
        tiime = millis();
        Time[b] = tiime - o_time;
        o_time = tiime;
        right();
        ch[b] = 2;
        b++;
      }
    }
    else if (cm2 != 0 && cm1 != 0)
    {
      stoop();
      //      delay(20);
      tiime = millis();
      Time[b] = tiime - o_time;
      o_time = tiime;
      rotation();
      ch[b] = 0;
      v = 0;
      b++;
    }
    else if (cm1 != 0 && cmr2 != 0 && cml2 != 0)
    {
      analogWrite(enA, 45);
      analogWrite(enAA, 45);
    }
  }
  stoop();
}
void translatel()
{
  int i = 0;
  cdr = sensordr();
  cdl = sensordl();
  cml1 = sensorml1();
  cml2 = sensorml2();
  cm1 = sensorm1();
  cm2 = sensorm2();
  cmr1 = sensormr1();
  cmr2 = sensormr2();
  while (cdr != 0 || cm2 != 0 || cdl != 0 || cm1 != 0 || cmr1 != 0 || cml1 != 0 || cml2 != 0 || cmr2 != 0)
  {
    cdr = sensordr();
    cdl = sensordl();
    cml1 = sensorml1();
    cml2 = sensorml2();
    cm1 = sensorm1();
    cm2 = sensorm2();
    cmr1 = sensormr1();
    cmr2 = sensormr2();

    
    if ((cdr == 0 || cdl == 0) && (cmr2 != 0 || cml2 != 0))
    {
      delay(2);
      cdr = sensordr();
      cdl = sensordl();
      if (cdr == 0 || cdl == 0)
      {
        if (shoort[i] == 3)
        {
          left();
          i++;
        }
        else if (shoort[i] == 1)
        {
          i++;
          while (cdr == 0 || cdl == 0)
          {
            forward(speeed);
            delay(1);
            cdr = sensordr();
            cdl = sensordl();
          }
        }
        else if (shoort[i] == 2)
        {
          right();
          i++;
        }
      }
    }
    else
    {
      forward(speeed);
    }
  }
  stoop();
}
void translater()
{
  int i = 0;
  cdr = sensordr();
  cdl = sensordl();
  cml1 = sensorml1();
  cml2 = sensorml2();
  cm1 = sensorm1();
  cm2 = sensorm2();
  cmr1 = sensormr1();
  cmr2 = sensormr2();
  while (cdr != 0 || cm2 != 0 || cdl != 0 || cm1 != 0 || cmr1 != 0 || cml1 != 0 || cml2 != 0 || cmr2 != 0)
  {
    cdr = sensordr();
    cdl = sensordl();
    cml1 = sensorml1();
    cml2 = sensorml2();
    cm1 = sensorm1();
    cm2 = sensorm2();
    cmr1 = sensormr1();
    cmr2 = sensormr2();

    
    if ((cdr == 0 || cdl == 0) && (cmr2 != 0 || cml2 != 0))
    {
      delay(2);
      cdr = sensordr();
      cdl = sensordl();
      if (cdr == 0 || cdl == 0)
      {
        if (shoortR[i] == 3)
        {
          left();
          i++;
        }
        else if (shoortR[i] == 1)
        {
          i++;
          while (cdr == 0 || cdl == 0)
          {
            forward(speeed);
            delay(1);
            cdr = sensordr();
            cdl = sensordl();
          }
        }
        else if (shoortR[i] == 2)
        {
          right();
          i++;
        }
      }
    }
    else
    {
      forward(speeed);
    }
  }
  stoop();
}
void translatelf()
{
  int i = 0;
  cdr = sensordr();
  cdl = sensordl();
  cml1 = sensorml1();
  cml2 = sensorml2();
  cm1 = sensorm1();
  cm2 = sensorm2();
  cmr1 = sensormr1();
  cmr2 = sensormr2();
  while (cdr != 0 || cm2 != 0 || cdl != 0 || cm1 != 0 || cmr1 != 0 || cml1 != 0 || cml2 != 0 || cmr2 != 0)
  { int iddd=0, to, tn, tt;
    cdr = sensordr();
    cdl = sensordl();
    cml1 = sensorml1();
    cml2 = sensorml2();
    cm1 = sensorm1();
    cm2 = sensorm2();
    cmr1 = sensormr1();
    cmr2 = sensormr2();

    
    if ((cdr == 0 || cdl == 0) && (cmr2 != 0 || cml2 != 0))
    {
      delay(2);
      cdr = sensordr();
      cdl = sensordl();
      if (cdr == 0 || cdl == 0)
      {
        if (shoort[i] == 3)
        {
          left();
          i++;
          iddd=0;
        }
        else if (shoort[i] == 1)
        {
          i++;
          iddd=0;
          while (cdr == 0 || cdl == 0)
          {
            forward(speeed);
            delay(1);
            cdr = sensordr();
            cdl = sensordl();
          }
        }
        else if (shoort[i] == 2)
        {
          right();
          i++;
          iddd=0;
        }
      }
    }
    else
    {if(Timel[i]>2000 && iddd==0 && i!=0){to=millis();
    tt=0;
      while(tt<Timel[i]/40){
        forward(65);
        delay(1);
        tn=millis();
        tt=tn-to;
      }
      iddd=7;

    }
     else{ forward(50);}
    }
  }
  stoop();
}
void translaterf()
{
  int i = 0;
  cdr = sensordr();
  cdl = sensordl();
  cml1 = sensorml1();
  cml2 = sensorml2();
  cm1 = sensorm1();
  cm2 = sensorm2();
  cmr1 = sensormr1();
  cmr2 = sensormr2();
  while (cdr != 0 || cm2 != 0 || cdl != 0 || cm1 != 0 || cmr1 != 0 || cml1 != 0 || cml2 != 0 || cmr2 != 0)
  {
    cdr = sensordr();
    cdl = sensordl();
    cml1 = sensorml1();
    cml2 = sensorml2();
    cm1 = sensorm1();
    cm2 = sensorm2();
    cmr1 = sensormr1();
    cmr2 = sensormr2();

    
    if ((cdr == 0 || cdl == 0) && (cmr2 != 0 || cml2 != 0))
    {
      delay(2);
      cdr = sensordr();
      cdl = sensordl();
      if (cdr == 0 || cdl == 0)
      {
        if (shoortR[i] == 3)
        {
          left();
          i++;
        }
        else if (shoortR[i] == 1)
        {
          i++;
          while (cdr == 0 || cdl == 0)
          {
            forward(speeed);
            delay(1);
            cdr = sensordr();
            cdl = sensordl();
          }
        }
        else if (shoortR[i] == 2)
        {
          right();
          i++;
        }
      }
    }
    else
    {
      forward(speeed);
    }
  }
  stoop();
}
void short_path(int v[], int tiime[], int taille)
{
  int path[taille];
  int timee[taille];
  int j = 0;
  int m = 0;
  for (int i = 0; i < taille - 1; i++)
  {
    if (v[i] == 3 && v[i + 1] == 0 && v[i + 2] == 2)
    {
      path[j] = 0;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 3 && v[i + 1] == 0 && v[i + 2] == 3)
    {
      path[j] = 1;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 2 && v[i + 1] == 0 && v[i + 2] == 2)
    {
      path[j] = 1;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 2 && v[i + 1] == 0 && v[i + 2] == 3)
    {
      path[j] = 0;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 2 && v[i + 1] == 0 && v[i + 2] == 1)
    {
      path[j] = 3;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 3 && v[i + 1] == 0 && v[i + 2] == 1)
    {
      path[j] = 2;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 3)
    {
      path[j] = 2;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 2)
    {
      path[j] = 3;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 1)
    {
      path[j] = 0;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else
    {
      path[j] = v[i];
      timee[j] = tiime[i];
      j++;
    }
  }
  for (int i = 0; i < j; i++)
  {
    if (path[i] != v[i])
    {
      m = 4;
    }
  }
  if (m == 0)
  {
    sl = j + 1;
    for (int i = 0; i < j; i++)
    {
      shoort[i] = path[i];
      Timel[i] = timee[i];
    }
  }
  else
  {
    short_path(path, timee, j + 2);
  }
}
void short_pathR(int v[], int tiime[], int taille)
{
  int path[taille];
  int timee[taille];
  int j = 0;
  int m = 0;
  for (int i = 0; i < taille - 1; i++)
  {
    if (v[i] == 3 && v[i + 1] == 0 && v[i + 2] == 2)
    {
      path[j] = 0;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 3 && v[i + 1] == 0 && v[i + 2] == 3)
    {
      path[j] = 1;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 2 && v[i + 1] == 0 && v[i + 2] == 2)
    {
      path[j] = 1;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 2 && v[i + 1] == 0 && v[i + 2] == 3)
    {
      path[j] = 0;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 2 && v[i + 1] == 0 && v[i + 2] == 1)
    {
      path[j] = 3;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 3 && v[i + 1] == 0 && v[i + 2] == 1)
    {
      path[j] = 2;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 3)
    {
      path[j] = 2;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 2)
    {
      path[j] = 3;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 1)
    {
      path[j] = 0;
      timee[j] = tiime[i];
      i = i + 2;
      j++;
    }
    else
    {
      path[j] = v[i];
      timee[j] = tiime[i];
      j++;
    }
  }
  for (int i = 0; i < j; i++)
  {
    if (path[i] != v[i])
    {
      m = 4;
    }
  }
  if (m == 0)
  {
    sr = j + 1;
    for (int i = 0; i < j; i++)
    {
      shoortR[i] = path[i];
      TimesR[i] = timee[i];
    }
  }
  else
  {
    short_pathR(path, timee, j + 1);
  }
}
void RH()

{
  cdr = sensordr();
  cdl = sensordl();
  cml1 = sensorml1();
  cml2 = sensorml2();
  cm1 = sensorm1();
  cm2 = sensorm2();
  cmr1 = sensormr1();
  cmr2 = sensormr2();
  o_time == millis();
  while (cdr != 0 || cm2 != 0 || cdl != 0 || cm1 != 0 || cmr1 != 0 || cml1 != 0 || cml2 != 0 || cmr2 != 0)
  {
    cdr = sensordr();
    cdl = sensordl();
    cml1 = sensorml1();
    cml2 = sensorml2();
    cm1 = sensorm1();
    cm2 = sensorm2();
    cmr1 = sensormr1();
    cmr2 = sensormr2();

    if (cdr == 0 && (cmr2 != 0 || cml2 != 0))
    {
      delay(2);
      cdr = sensordr();

      if (cdr == 0)
      {
        ii = 0;
        tiime = millis();
        Timer[b] = tiime - o_time;
        o_time = tiime;
        right();
        chr[b] = 2;
        b++;
        v = 0;
      }
    }
    else if (cm1 == 0 || cml1 == 0 || cmr1 == 0)
    {
      if (cdl == 0)
      {
        delay(2);
        cdl = sensordl();
        cdr = sensordr();
        if (cdl == 0 && cdr != 0 && (cmr2 != 0 || cml2 != 0))
        {
          tiime = millis();
          Timer[b] = tiime - o_time;
          o_time = tiime;
          chr[b] = 1;
          b++;
          while (cdl == 0)
          {
            forward(speeed);

            delay(1);
            cdl = sensordl();
          }
          v = 0;
          ii = 0;
        }
      }
      //      else if(cdr==0 && ii!=0){
      //      forward(speeed);
      //      v=0;
      //      }
      else
      {
        forward(speeed);
        v = 0;
        ii = 0;
      }
    }
    else if (cdl == 0 && (cmr2 != 0 || cml2 != 0))
    {
      delay(30);
      cdr = sensordr();
      cdl = sensordl();
      ii = 0;
      if (cdr != 0 && cdl == 0)
      {
        v = 0;
        tiime = millis();
        Timer[b] = tiime - o_time;
        o_time = tiime;
        left();
        chr[b] = 3;
        b++;
      }
    }
    else if (cm2 != 0 && cm1 != 0)
    {
      stoop();
      //      delay(20);
      tiime = millis();
      Timer[b] = tiime - o_time;
      o_time = tiime;
      rotation();
      chr[b] = 0;
      v = 0;
      b++;
    }
    else if (cm1 != 0 && cmr1 != 0 && cml1 != 0)
    {
      analogWrite(enA, 45);
      analogWrite(enAA, 45);
    }
  }
  stoop();
}
void increment()
{ // when it will be y=0  it runs right hand and then we give another y it will run another program
  moode++;
}
void setup()
{
  pinMode(push_button, INPUT);
  attachInterrupt(digitalPinToInterrupt(PA2), increment, FALLING);
  pinMode(anaIRSensorm1, INPUT);
  pinMode(anaIRSensormleft1, INPUT);

  pinMode(anaIRSensormright1, INPUT);
  pinMode(anaIRSensordirleft, INPUT);
  pinMode(anaIRSensordirright, INPUT);
  pinMode(digIRSensorm1, OUTPUT);
  pinMode(digIRSensormleft1, OUTPUT);
  pinMode(digIRSensormright1, OUTPUT);
  pinMode(digIRSensordirleft, OUTPUT);
  pinMode(digIRSensordirright, OUTPUT);

  pinMode(anaIRSensorm2, INPUT);
  pinMode(anaIRSensormleft2, INPUT);
  pinMode(anaIRSensormright2, INPUT);

  pinMode(digIRSensorm2, OUTPUT);
  pinMode(digIRSensormleft2, OUTPUT);
  pinMode(digIRSensormright2, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enA, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  pinMode(in11, OUTPUT);
  pinMode(in22, OUTPUT);

  pinMode(enAA, OUTPUT);
  digitalWrite(enA, LOW);
  digitalWrite(enAA, LOW);
  digitalWrite(in11, LOW);
  digitalWrite(in22, LOW);

  delay(2000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in11, LOW);
  digitalWrite(in22, HIGH);
}
void loop()
{
   if (x == 0)
  {
    old_millis = millis();
    cm1 = sensorm1();
    cmr1 = sensormr1();
    cml1 = sensorml1();
    cmr2 = sensormr2();
    cml2 = sensorml2();
    cdl = sensordl();
    cdr = sensordr();
    LH();
    delay(1000);
    short_path(ch, Time, b + 1);
    moode = 0;
    tt=0;
    while(tt==0){
    while (moode == 0)
    {
      delay(500);
      // LH();
    }
    delay(10000);
    if (moode < 20)
    {
      RH();
      x++;
      short_pathR(chr, Timer, b + 1);
      tt=7;
    }
    else if (moode > 20)
    {
      translatel();
      tt=0;
      moode=0;
    }}
    moode = 0;
    tt=0;
    while (tt == 0)
    {
      delay(100);
      if (moode > 0)
      {
        delay(10000);
        if (moode < 20)
        {
          for (int i = 0; i < sl; i++)
          {
            timeell = timeell + Timel[i];
          }
          for (int i = 0; i < sr; i++)
          {
            timeerr = timeerr + TimesR[i];
          }
          if (timeell < timeerr)
          {
            translatel();
            ind=1;
          }
          else
          {
            translater();
            ind=2;
          }

          tt = 17;
        }
        else if (moode > 10)
        {
          RH();
          x++;
          moode = o;
          short_pathR(chr, Timer, b + 1);
          tt = 0;
        }
      }
    }

    // for (int i = 0; i < b; i++)
    // {
    //   Serial.print(shoort[i]);
    // }
    // Serial.print("   not short:");
    // for (int i = 0; i < b; i++)
    // {
    //   Serial.print(ch[i]);
    // }
    // Serial.print("\n");

    x=17;
    moode=0;
    
    // while(moode==0){
    //   for(int i=0; int<sl+1; i++){
    //     Serial.print(Timel[i]);
    //   }
    //   Serial.print("\n");
    // }
  
  }
  else{
    if(moode>0){
      if(ind==1){
        delay(3000);
        translatel();
        moode=0;
      }
      else{
        delay(3000);
        translater();
        moode=0;
      }
    }
    else{delay(100);}
  }

}
