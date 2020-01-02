//Buttons for floor 1 to 4
const int buttonPin1 = 52;
const int buttonPin2 = 54;
const int buttonPin3 = 56;

//DC Motor the only one that needs analog goes into digital PWN
int Enable = 2;
int DirectionA = 3;
int DirectionB = 4;

//Limit Switch
int Limit1 = 30;
int Limit2 = 32;
int Limit3 = 34;

//Display Number Configurations in an array for 7-Segment Display
/*The array in Num_Display in a '4' means from 0 to 3 Display Numbers
The array in Num_Display in a '7' means 7 Pins in a Seven-Segment Displays. */
int Num_Display[4][7] = {{1,1,1,1,1,1,0}, //0
                         {0,1,1,0,0,0,0}, //1
                         {1,1,0,1,1,0,1}, //2
                         {1,1,1,1,0,0,1}}; //3
      
//Function for a 7-Segment Display of 2 Dimension Arrays
void Num_Shown(int Number)
{
  int pin = 33;
  for (int j = 0; j < 7; j++)
  {
    digitalWrite(pin, Num_Display[Number][j]);
  }
}
  
//Display LEDs
int LED_Red = 5;
int LED_Yellow = 6;
int LED_Blue = 7;


//Function to Bring out Both Display and Led For Each Floor
void fl1_DNL()
{
  digitalWrite(LED_Red, HIGH);
  digitalWrite(LED_Yellow, LOW); 
  digitalWrite(LED_Blue, LOW);
  delay(1000);
  digitalWrite(LED_Red, LOW);
}

void fl2_DNL()
{
  digitalWrite(LED_Red, LOW);
  digitalWrite(LED_Yellow, HIGH); 
  digitalWrite(LED_Blue, LOW);
  delay(1000);
  digitalWrite(LED_Yellow, LOW);
}
void fl3_DNL()
{
  digitalWrite(LED_Red, LOW);
  digitalWrite(LED_Yellow, LOW); 
  digitalWrite(LED_Blue, HIGH);
  delay(1000);
  digitalWrite(LED_Blue, LOW);
}
void Motor_RunsUp()
{
  analogWrite(Enable, 255); // enable is turned on
  for (int a = 0; a < 359; a++){
  digitalWrite(DirectionA, HIGH); // To go down the floor had to go down one way
  digitalWrite(DirectionB, LOW);
  }
}
void Motor_RunsDown()
{
  analogWrite(Enable, 255); // enable is turned on
  for (int a = 0; a < 359; a++)
  {
  digitalWrite(DirectionA, LOW); // To go down the floor had to go down one way
  digitalWrite(DirectionB, HIGH);
  }
}
void setup()
{
//DC Motor are all Output, to turn it on, rotate clock-wise and, counter-clockwise
pinMode(DirectionA, OUTPUT);
pinMode(DirectionB, OUTPUT);
pinMode(Enable, OUTPUT);
//LED to let the elevator know where the elevator is at.
pinMode(LED_Red, OUTPUT);
pinMode(LED_Yellow, OUTPUT);
pinMode(LED_Blue, OUTPUT);
//All OF the PUSH-Buttons are INPUTS
pinMode(buttonPin1, INPUT);
//Limit Switches as INPUT, Let the Elevator know where it should stop at
pinMode(Limit1, INPUT);
//The Seven-Segment Displays Pins
pinMode(31, OUTPUT);
pinMode(33, OUTPUT);
pinMode(35, OUTPUT);
pinMode(37, OUTPUT);
pinMode(39, OUTPUT);
pinMode(41, OUTPUT);
pinMode(43, OUTPUT);
}

void loop()
{
  int buttonStatus1 = digitalRead(buttonPin1);
  int buttonStatus2 = digitalRead(buttonPin2);
  int buttonStatus3 = digitalRead(buttonPin3);

  //Loop for PUSH BUTTON FOR FIRST FLOOR
  while(buttonStatus1 = HIGH)
  {
    if(Limit1 == HIGH) //IF YOU REMAIN ON THE FIRST FLOOR.
    {
      Num_Shown(1);
      fl1_DNL();
    }
    else if (Limit2 == HIGH || Limit3 == HIGH)
    {
      
      Motor_RunsDown(); //MOTOR WILL TURN COUNTER-CLOCKWISE IN ORDER TO GO DOWN
      
      if (Limit2 == HIGH && Limit3 == LOW)
      {
        Num_Shown(2);
        fl2_DNL();
        
      }
      else
      {
        Num_Shown(3);
        fl3_DNL();
      }
    }
     Num_Shown(1);  
  }
  //PUSH BUTTON FOR SECOND FLOOR
  while(buttonStatus2 = HIGH)
  {
    if(Limit1 == HIGH)
    {
      Num_Shown(1);
      Motor_RunsUp();//MOTOR WILL TURN CLOCKWISE IN ORDER TO GO UP
    }
    else if (Limit3 == HIGH)
    {
      Num_Shown(3);
      fl3_DNL();
      Motor_RunsDown();
    }
    else
    {
      fl2_DNL();
    }
     Num_Shown(2);
  }
}
