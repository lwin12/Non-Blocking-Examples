#define RED_LED 12
#define GREEN_LED 11
#define BLUE_LED 10
#define YELLOW_LED 9
#define ORANGE_LED 8
#define PURPLE_LED 7
#define WHITE_LED 6

#define BUTTON_INPUT 2

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

void CHASER_LED()
{
	if(CURRENT_TIME - PREV_TIME >= 100)
	{
		PREV_TIME = CURRENT_TIME;
		if(GREEN_STATE == LOW && BLUE_STATE == LOW)
		{	
			RED_STATE = !RED_STATE;
			digitalWrite(RED_LED,RED_STATE? HIGH : LOW);
		}
		if(RED_STATE == LOW && BLUE_STATE == LOW)
		{	
			GREEN_STATE = !GREEN_STATE;
			digitalWrite(GREEN_LED, GREEN_STATE? HIGH:LOW);
		}
		if(RED_STATE == LOW && GREEN_STATE == LOW)
		{
			BLUE_STATE = !BLUE_STATE;
			digitalWrite(BLUE_LED, BLUE_STATE? HIGH:LOW);
		}
		
	}
}

