/**
 * For hackathon
 * 
 * We based our project heavily on this guy's (https://www.youtube.com/watch?v=7iKR3QbRq74) and we also took the code that he used to see 
 * how it could be coded. We took several of his methods and modified some of them for our own understanding but some were odd so we left it
 * as so.
 * 
 * A lot of our understanding of how to code the LED cube came from reading this guy's code and it was also helpful for figuring out how to
 * wire the cube onto the board. 
 */


//intializing and declaring layers
int layer[4]={A3,A2,A1,A0}; 

//initializing and declaring leds, bottom right is led[0]
int led[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4};


 int time = 1000;
 
 void setup()
{
  //setting leds to output
  for(int i = 0; i< 16; i++)
  {
    pinMode(led[i], OUTPUT);
  }
  //setting layers to output
  for(int i = 0; i< 4; i++)
  {
    pinMode(layer[i], OUTPUT);
  }

  
  //seeding random for random animations
  randomSeed(analogRead(10));

}


void loop()
{
    randomLED();
    for(int i = 0; i < 3; i++)
    {
      flicker();
    }
    delay(100);
    steppingThrough();
    delay(100);
    for(int i = 0; i < 5; i++)
    {
      randomLED();
    }
    delay(100);
    ripple();
    delay(100);
    edgeLEDs();
    delay(100);
    goThroughAllLedsOneAtATime();
    delay(100);
    randomLED();
    delay(100);
    flicker();
    
}


/**
 * turn all the LEDs off
 */
void turnEverythingOff()
 {
  //this for loop steps through layers
      //another for loop for stepping through the 16 LEDs per layer
    for(int j = 0; j < 16; j++)
    {
      digitalWrite(led[j], 1); //turn it on
    }
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 0);
  }
 }
 
/**
 * turns all the LEDs on
 */
void turnEverythingOn()
{
  //this for loop steps through layers
      //another for loop for stepping through the 16 LEDs per layer
    for(int j = 0; j < 16; j++)
    {
      digitalWrite(led[j], 0); //turn it on
    }
    
   for(int i = 0; i < 4; i++)
   {
    digitalWrite(layer[i], 1);
   }
}

/**
 * Flicker the LEDs
 */
void flicker()
{
  
    turnEverythingOn(); //turn them all on
    delay(200);
    turnEverythingOff(); //turn them all off
    delay(200);
}


/**
 * around edge of the cube down
 * (NOT OURS)
 */
void aroundEdgeDown()
{
  //for loop to go through the LEDs
  for(int x = 200; x != 0; x -=50)
  {
    turnEverythingOff();

    //this counts down from the fourth layer to the first layer
    for(int i = 4; i != 0; i--)
    {
      //turn this one on
      digitalWrite(layer[i-1], 1);
      //turn these off
      digitalWrite(led[5], 0);
      digitalWrite(led[6], 0);
      digitalWrite(led[9], 0);
      digitalWrite(led[10], 0);
      
      digitalWrite(led[0], 0);
      delay(x);
      digitalWrite(led[0], 1);
      digitalWrite(led[4], 0);
      delay(x);
      digitalWrite(led[4], 1);
      digitalWrite(led[8], 0);
      delay(x);
      digitalWrite(led[8], 1);
      digitalWrite(led[12], 0);
      delay(x);
      digitalWrite(led[12], 1);
      digitalWrite(led[13], 0);
      delay(x);
      digitalWrite(led[13], 1);
      digitalWrite(led[14], 0);
      delay(x);
      digitalWrite(led[14], 1);
      digitalWrite(led[15], 0);
      delay(x);
      digitalWrite(led[15], 1);
      digitalWrite(led[11], 0);
      delay(x);
      digitalWrite(led[11], 1);
      digitalWrite(led[7], 0);
      delay(x);
      digitalWrite(led[7], 1);
      digitalWrite(led[3], 0);
      delay(x);
      digitalWrite(led[3], 1);
      digitalWrite(led[2], 0);
      delay(x);
      digitalWrite(led[2], 1);
      digitalWrite(led[1], 0);
      delay(x);
      digitalWrite(led[1], 1);
    }
  }
}

/*
 * Random things
 * (NOT OURS)
 */
void randomRain()
{
  turnEverythingOff();
  int x = 100;
  for(int i = 0; i!=60; i+=2)
  {
    int randomLed = random(0,16);
    digitalWrite(led[randomLed], 0);
    digitalWrite(layer[3], 1);
    delay(x+50);
    digitalWrite(layer[3], 0);
    digitalWrite(layer[2], 1);
    delay(x);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[1], 1);
    delay(x);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[0], 1);
    delay(x+50);
    digitalWrite(layer[0], 0);
    digitalWrite(led[randomLed], 1);
  }
}

/**
 * Light up the edge LEDs
 */

void edgeLEDs()
{
  turnEverythingOff();

  //first and fourth layer get to be all lit up
  for(int i = 0; i < 16; i++)
  {
    digitalWrite(layer[1], 1);
    digitalWrite(led[i], 0);
  }

  for(int i = 0; i < 16; i++)
  {
    digitalWrite(layer[3], 1);
    digitalWrite(led[i], 0);
  }

    for(int i = 0; i < 16; i++)
  {
    if(i == 3 || i == 4 || i == 7 || i == 8 || i == 11 || i == 12 || i == 15)
    {
           digitalWrite(layer[1], 1);
          digitalWrite(led[i], 0);
    }
  }

      for(int i = 0; i < 16; i++)
  {
    if(i == 3 || i == 4 || i == 7 || i == 8 || i == 11 || i == 12 || i == 15)
    {
           digitalWrite(layer[2], 1);
          digitalWrite(led[i], 0);
    }
  }

  delay(200);
  turnEverythingOff();

  
}
/**
 * Some more animations to go through
 */
 void ripple()
 {
  turnEverythingOff();

  //divide the leds array into 4 sets
  int set1[4] = {0,1,2,3};
  int set2[4] = {4,5,6,7};
  int set3[4] = {8,9,10,11};
  int set4[4] = {12,13,14,15};

  //for loop to step through the layers
  for(int i = 0; i < 4; i++)
  {
    turnEverythingOff();
    if(i == 0)
    {
      turnEverythingOff();
      for (int j = 0; j < 4; j++)
      {
        digitalWrite(layer[i], 1);
        digitalWrite(set1[j], 0);
        delay(100);
        digitalWrite(set2[j], 1);
      }
    }
    else if(i == 1)
    {
      turnEverythingOff();
      for (int j = 0; j < 4; j++)
      {
        digitalWrite(layer[i], 1);
        digitalWrite(set2[j], 0);
        delay(100);
        digitalWrite(set2[j], 1);
      }
    }
    else if(i == 2)
    {
      turnEverythingOff();
      for (int j = 0; j < 4; j++)
      {
        digitalWrite(layer[i], 1);
        digitalWrite(set3[j], 0);
        delay(100);
        digitalWrite(set3[j], 1);
      }
    }
    //otherwise i = 3
    else
    {
       turnEverythingOff();
      for (int j = 0; j < 4; j++)
      {
        digitalWrite(layer[i], 1);
        digitalWrite(set4[j], 0);
        delay(100);
        digitalWrite(set2[j], 1);
      }
    }
      
  }
 }
/**
 * go through all leds one at a time
 * 
 * (NOT OURS)
 */
void goThroughAllLedsOneAtATime()
{
  int x = 80;
  turnEverythingOff();
  for(int y = 0; y<5; y++)
  {
    //0-3
    for(int count = 4; count != 0; count--)
    {
      digitalWrite(layer[count-1], 1);
      for(int i = 0; i<4; i++)
      {
        digitalWrite(led[i], 0);
        delay(x);
        digitalWrite(led[i], 1);
        delay(x);
      }
    digitalWrite(layer[count-1], 0);
    }
    //4-7
    for(int count = 0; count < 4; count++)
    {
      digitalWrite(layer[count], 1);
      for(int i = 4; i<8; i++)
      {
        digitalWrite(led[i], 0);
        delay(x);
        digitalWrite(led[i], 1);
        delay(x);
      }
    digitalWrite(layer[count], 0);
    }
    //8-11
    for(int count = 4; count != 0; count--)
    {
      digitalWrite(layer[count-1], 1);
      for(int i = 8; i<12; i++)
      {
        digitalWrite(led[i], 0);
        delay(x);
        digitalWrite(led[i], 1);
        delay(x);
      }
    digitalWrite(layer[count-1], 0);
    }
    //12-15
    for(int count = 0; count < 4; count++)
    {
      digitalWrite(layer[count], 1);
      for(int i = 12; i<16; i++)
      {
        digitalWrite(led[i], 0);
        delay(x);
        digitalWrite(led[i], 1);
        delay(x);
      }
    digitalWrite(layer[count], 0);
    }
  }
 }

 void steppingThrough()
 {
  turnEverythingOff();

  //turn on layer 1
  digitalWrite(layer[0], 1);
  for(int i = 0; i < 4; i++)
  {
      digitalWrite(led[i], 0);
  }

  delay(200);

  //turn off layer 1
    digitalWrite(layer[0], 0);
  for(int i = 0; i < 4; i++)
  {
      digitalWrite(led[i], 1);
  }

  //turn on layer 2
  digitalWrite(layer[1], 1);
    for(int i = 4; i < 8; i++)
  {
      digitalWrite(led[i], 0);
  }
  
  delay(200);

  //turn on layer 2
    digitalWrite(layer[1], 0);
  for(int i = 4; i < 8; i++)
  {
      digitalWrite(led[i], 1);
  }

  //turn on layer 3
  digitalWrite(layer[2], 1);
  for(int i = 8; i < 12; i++)
  {
      digitalWrite(led[i], 0);
  }
  
  delay(200);

  //turn off layer 3
    digitalWrite(layer[2], 0);
  for(int i = 8; i < 12; i++)
  {
      digitalWrite(led[i], 1);
  }
  
  delay(200);

  //turn on layer 4
    digitalWrite(layer[3], 1);
    for(int i = 12; i < 16; i++)
  {
      digitalWrite(led[i], 0);
  }
  
  delay(200);

  //turn off layer 4
    digitalWrite(layer[3], 0);
  for(int i = 12; i < 16; i++)
  {
      digitalWrite(led[i], 1);
  }
 }
 
/**
 * Pick random parts to light up
 */
void randomLED()
{
  turnEverythingOff();
  
  //choose a number at random
  int randLayer = random(0,4);
  int randLED = random(0, 16);

  //turn on
  digitalWrite(layer[randLayer], 1);
  digitalWrite(led[randLED], 0);
  
  delay(300);

  //turn off
  digitalWrite(layer[randLayer], 0);
  digitalWrite(led[randLED], 1);
}



 


