/*
 Author: Lwin Moe Aung
 Date  : 11/08/2025
*/
#define RED_LED 12
#define GREEN_LED 11
#define BLUE_LED 10
#define BUTTON_INPUT 2

bool BUTTON_CURRENT = HIGH;  //This is to store the current state of button.
bool BUTTON_PREVIOUS = LOW;  //This variable will store the previous state of button. 
bool OUTPUT_SIG = false; //This variable acts like a flag to begin the LED blinking function.
//For the button, we are using a non latching push button. 

int CURRENT_TIME = 0; //Think of this as a scared time line in Marvel, it will always keep going forward. 1,2,3,4,5,6...Eventually it will get bigger.

int RED_PREV_TIME = 0; //This variable is to store the previous time the event has happened.
int GREEN_PREV_TIME = 0; 
int BLUE_PREV_TIME = 0;

bool RED_STATE = LOW;  //This varible is to store the current state of the LED.
bool GREEN_STATE = LOW;
bool BLUE_STATE = LOW;

void setup() {
for(int pin = 10; pin < 13; pin++)
{
	pinMode(pin,OUTPUT);
}

pinMode(BUTTON_INPUT, INPUT_PULLUP); 
/*
I have set the button to be input pull up, this means the button's neutral state will always be high. 
There for in order to have a change, the button will have to be hooked to GND line of the MCU.
*/
}


void loop() 
{
BUTTON();
LED(1000, 10, 10);
}

void BUTTON()
{
	BUTTON_CURRENT = digitalRead(BUTTON_INPUT);         //GETS THE CURRENT STATE OF BUTTON

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
	}
}

void LED(int RED_F, int GREEN_F, int BLUE_F)
{
  if(OUTPUT_SIG == true)
  {
      CURRENT_TIME = millis();
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
        digitalWrite(	GREEN_LED, GREEN_STATE? HIGH : LOW );
      }

      if(CURRENT_TIME - BLUE_PREV_TIME >= BLUE_F)
      {
        BLUE_PREV_TIME = CURRENT_TIME;
        BLUE_STATE = !BLUE_STATE;
        digitalWrite(	BLUE_LED, BLUE_STATE? HIGH : LOW);
      }
  }
}
