#define RED_LED 12
#define GREEN_LED 11
#define BLUE_LED 10
#define YELLOW_LED 9
#define ORANGE_LED 8
#define PURPLE_LED 7
#define WHITE_LED 6

#define BUTTON_INPUT 2
#define SPEED_INPUT 5

bool BUTTON_CURRENT = HIGH;
bool BUTTON_PREVIOUS = LOW;
bool OUTPUT_SIG = false;

unsigned long CURRENT_TIME = 0;
unsigned long PREV_TIME = 0;

unsigned long RED_PREV_TIME = 0;
unsigned long GREEN_PREV_TIME = 0;
unsigned long BLUE_PREV_TIME = 0;
unsigned long YELLOW_PREV_TIME = 0;
unsigned long ORANGE_PREV_TIME = 0;
unsigned long PURPLE_PREV_TIME = 0;
unsigned long WHITE_PREV_TIME = 0;

bool RED_STATE = LOW;
bool GREEN_STATE = LOW;
bool BLUE_STATE = LOW;
bool YELLOW_STATE = LOW;
bool ORANGE_STATE = LOW;
bool PURPLE_STATE = LOW;
bool WHITE_STATE = LOW;



void setup() {
for(int pin = 6; pin < 13; pin++)
{
	pinMode(pin,OUTPUT);
}

pinMode(BUTTON_INPUT, INPUT_PULLUP);
pinMode(SPEED_INPUT, INPUT);

Serial.begin(9600);
}


void loop() {
CURRENT_TIME = millis();
//BUTTON();
CHASER_LED();



}

void LED(unsigned long RED_F)
{
  
unsigned long GREEN_F  = RED_F    * 2;
unsigned long BLUE_F   = GREEN_F  * 2;
unsigned long YELLOW_F = BLUE_F   * 2;
unsigned long ORANGE_F = YELLOW_F * 2;
unsigned long PURPLE_F = ORANGE_F * 2;
unsigned long WHITE_F  = PURPLE_F * 2;

  if(OUTPUT_SIG == true)
  {
      
      if(CURRENT_TIME - RED_PREV_TIME >= RED_F)
      {
        RED_PREV_TIME = CURRENT_TIME;
        RED_STATE = !RED_STATE;
        digitalWrite(RED_LED, RED_STATE? HIGH : LOW );
      }
      
      if(CURRENT_TIME - GREEN_PREV_TIME >= GREEN_F)
      {
        GREEN_PREV_TIME = CURRENT_TIME;
        GREEN_STATE = !GREEN_STATE;
        digitalWrite(GREEN_LED, GREEN_STATE? HIGH : LOW );
      }

      if(CURRENT_TIME - BLUE_PREV_TIME >= BLUE_F)
      {
        BLUE_PREV_TIME = CURRENT_TIME;
        BLUE_STATE = !BLUE_STATE;
        digitalWrite(BLUE_LED, BLUE_STATE? HIGH : LOW);
      }

      if(CURRENT_TIME - YELLOW_PREV_TIME >= YELLOW_F)
      {
        YELLOW_PREV_TIME = CURRENT_TIME;
        YELLOW_STATE = !YELLOW_STATE;
        digitalWrite(YELLOW_LED, YELLOW_STATE? HIGH : LOW);
      }

      if(CURRENT_TIME - ORANGE_PREV_TIME >= ORANGE_F)
      {
        ORANGE_PREV_TIME = CURRENT_TIME;
        ORANGE_STATE = !ORANGE_STATE;
        digitalWrite(ORANGE_LED, ORANGE_STATE? HIGH : LOW );
      }

      if(CURRENT_TIME - PURPLE_PREV_TIME >= PURPLE_F)
      {
        PURPLE_PREV_TIME = CURRENT_TIME;
        PURPLE_STATE = !PURPLE_STATE;
        digitalWrite(PURPLE_LED, PURPLE_STATE? HIGH : LOW);
      }

      if(CURRENT_TIME - WHITE_PREV_TIME >= WHITE_F)
      {
        WHITE_PREV_TIME = CURRENT_TIME;
        WHITE_STATE = !WHITE_STATE;
        digitalWrite(WHITE_LED, WHITE_STATE? HIGH : LOW);
      }

  }
}


void BUTTON()
{
	BUTTON_CURRENT = digitalRead(BUTTON_INPUT);

	if(BUTTON_CURRENT == LOW && BUTTON_PREVIOUS == HIGH)
	{
		OUTPUT_SIG = !OUTPUT_SIG;
		
	}
	BUTTON_PREVIOUS = BUTTON_CURRENT;

	if(OUTPUT_SIG == false)
	{
		digitalWrite(RED_LED, LOW);
		digitalWrite(GREEN_LED, LOW);
		digitalWrite(BLUE_LED, LOW);
		digitalWrite(YELLOW_LED, LOW);
		digitalWrite(ORANGE_LED, LOW);
		digitalWrite(PURPLE_LED, LOW);
		digitalWrite(WHITE_LED, LOW);

		RED_STATE = LOW;
		GREEN_STATE = LOW;
		BLUE_STATE = LOW;
		YELLOW_STATE = LOW;
		ORANGE_STATE = LOW;
		PURPLE_STATE = LOW;
		WHITE_STATE = LOW;

		RED_PREV_TIME = CURRENT_TIME;
		GREEN_PREV_TIME = CURRENT_TIME;
		BLUE_PREV_TIME = CURRENT_TIME;
		YELLOW_PREV_TIME = CURRENT_TIME;
		ORANGE_PREV_TIME = CURRENT_TIME;
		PURPLE_PREV_TIME = CURRENT_TIME;
		WHITE_PREV_TIME = CURRENT_TIME;
	}
}
int INDEX = 0;
int SPEED = 0;
bool DIRECTION = true;
void CHASER_LED() 
{
  	SPEED = analogRead(SPEED_INPUT);

	if(CURRENT_TIME - PREV_TIME >= SPEED) 
	{
		Serial.print("Current Speed: ");
		Serial.println(SPEED);
		PREV_TIME = CURRENT_TIME;

		RED_STATE    = (INDEX == 0);
		GREEN_STATE  = (INDEX == 1);
		BLUE_STATE   = (INDEX == 2);
		YELLOW_STATE = (INDEX == 3);
		ORANGE_STATE = (INDEX == 4);
		PURPLE_STATE = (INDEX == 5);
		WHITE_STATE  = (INDEX == 6);

    /*
    I will just explain this part "RED_STATE    = (INDEX == 0);"
    Here we are setting the bool variable RED_STATE to either true or false, based on the condtion on the right hand side, which is "INDEX == 0".
    In simple bro terms, it goes something like this. 
    Bro 1: "Hey man, is the value of INDEX currently 0?"
    Bro 2: "Oh, no its currently not 0."
    Bro 1: "Oh okay, since its not 0, I will set the RED_STATE variable to false. Thank you."
    */

		digitalWrite(RED_LED,   RED_STATE ? HIGH : LOW);
		digitalWrite(GREEN_LED, GREEN_STATE ? HIGH : LOW);
		digitalWrite(BLUE_LED,  BLUE_STATE ? HIGH : LOW);
		digitalWrite(YELLOW_LED,   YELLOW_STATE ? HIGH : LOW);
		digitalWrite(ORANGE_LED, ORANGE_STATE ? HIGH : LOW);
		digitalWrite(PURPLE_LED,  PURPLE_STATE ? HIGH : LOW);
		digitalWrite(WHITE_LED, WHITE_STATE ? HIGH: LOW);
		
		DIRECTION ? INDEX++ : INDEX--;
		/*
		What does "DIRECTION ? INDEX++ : INDEX--;" means?
		It means that if the variable DIRECTION is true, the variable INDEX will start to go up by 1.
		
		Now, if lets say that the variable DIRECTION is false, then the variable INDEX will start to decrease by 1.

    In simple bro terms, it goes something like this.
    Bro 1: Hey man. Currently, whats the value for the bool variable DIRECTION?
    Bro 2: Oh hey! Currently, the value for bool variable DIRECTION is true.
    Bro 1: Oh okay, thanks bro! Since the value is true, I will increase the variable INDEX by 1.

    Sometimes later...
    Bro 1: Hey bro, is the value for DIRECTION still true?
    Bro 2: Oh bro, it changed to false.
    Bro 1: Oh shit, thanks man. Since the value is now false, i will decrease the variable INDEX by 1.
		
		This is called Ternary Operator, you may read up more about it from the link below.
		https://www.geeksforgeeks.org/c/conditional-or-ternary-operator-in-c/
		*/

		if(INDEX == 6)
		{
			DIRECTION = false;
		}
		if(INDEX == 0)
		{
			DIRECTION = true;
		}
		/*
		if(INDEX == 6)
		{
			DIRECTION = false;
		}
		if(INDEX == 0)
		{
			DIRECTION = true;
		}
		
		So this part of the code is basically, changing the direction of how we want the LED
		to go, at the start you will notice that the LED Starts from RED followed by GREEN, BLUE, YELLOW....
    so basically, if the variable INDEX is currently at 6 which means the last LED just lit up, then the variable DIRECTION
    will be set to false, when its false it will start to lit up backward. This works together with "DIRECTION ? INDEX++ : INDEX--;".

    Now you know :)
		*/	
    
	}
}

