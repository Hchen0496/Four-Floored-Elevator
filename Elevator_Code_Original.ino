const int buttonPin1 = 2; //Button pressed for floor 1
const int buttonPin2 = 3; //Button Pressed for floor 2
const int buttonPin3 = 4; //Button Pressed for floor 3
const int buttonPin4 = 5; //Button Pressed for floor 4 

/*This variable is going to read the pushbutton status*/
int buttonState1 = 0; 
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

/*The DC Motor where pins are set to*/
int en = 9;
int DirectA = 10;
int DirectB = 11;

/*Elevator starts at First floor*/
int i = 1;

void setup() {
 pinMode(en, OUTPUT);
 pinMode(DirectA, OUTPUT);
 pinMode(DirectB, OUTPUT);
 Serial.begin(9600);
  
 pinMode(buttonPin1, INPUT); 
 pinMode(buttonPin2, INPUT);
 pinMode(buttonPin3, INPUT);
 pinMode(buttonPin4, INPUT);
}

void loop() {
  // Read the state of the pushbutton value
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  //Pressing the pushbutton on the fourth floor
  if(buttonState4 == HIGH){
    while (i < 4){ // When called to the fourth floor, it will only go up
      i++;
      up(); // The up function
    Serial.print(" You are on the ");
    Serial.print(i);
    Serial.print(" Floor."); 
    }
    i = 4;    
  }

  //Pressing the pushbutton on the 3rd floor to go down from the fourth floor
  else if(buttonState3 == HIGH){
    if(i>3){ 
    while (i > 3){
      i--;
      down();
      Serial.print("You are on ");
      Serial.print(i);
      Serial.println(" Floor.");
    }
   }
   //Waiting on the First or Second floor to go up to the 3rd floor
   else if(i < 3) {
      while (i < 3){
      i++;
      up();
      Serial.print("You are on ");
      Serial.print(i);
      Serial.println(" Floor."); 
    }
   }
   i = 3;
  }

  //Pressing the pushbutton on the 2nd floor to go down from the 3rd or 4th floor
  else if(buttonState2 == HIGH){
    if(i > 2){
      while(i > 2){
        i--;
        down();
        Serial.print("You are on ");
        Serial.print(i);
        Serial.println(" Floor.");
    }
  }
  //Waiting to go up from the first floor
   else if(i < 2){
      while (i < 2){
        i++;
        up();
        Serial.print("You are on ");
        Serial.print(i);
        Serial.println(" Floor.");
      }
    }
    i = 2;
  }
  //Pressing the pushbutton on the first floor, it's going down from the 2nd, 3rd or 4th floor
  else if(buttonState1 == HIGH){
    if(i > 1){
      while(i > 1){
        i--;
        down();
        Serial.print("You are on ");
        Serial.print(i);
        Serial.println(" Floor.");
      }
    }
    i = 1;
  }  
 }

/*Function to go up*/
void up(){
  analogWrite(en, 255); // enable is turned on
  for (int b = 0; b < 359; b++){
    digitalWrite(DirectA, HIGH); // To go up The floor has to go one way up
    digitalWrite(DirectB, LOW);
    analogWrite(en,100);
    delay(1);// a delay of 50ms
    digitalWrite(DirectA, HIGH);
    digitalWrite(DirectB, HIGH);
  }
}
/*Function to go down*/
void down(){
  analogWrite(en, 255); // enable is turned on
  for (int a = 0; a < 359; a++){
    digitalWrite(DirectA, LOW); // To go down the floor had to go down one way
    digitalWrite(DirectB, HIGH);
    analogWrite(en, 100);
    delay(1); //a delay of 50ms for each stop
    digitalWrite(DirectA, HIGH);
    digitalWrite(DirectB, HIGH);
 }
}
