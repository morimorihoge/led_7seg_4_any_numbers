int IO_DIGIT_A  = 13;
int IO_DIGIT_B  = 12;
int IO_DIGIT_C  = 11;
int IO_DIGIT_D  = 10;
int IO_DIGIT_E  = 9;
int IO_DIGIT_F  = 8;
int IO_DIGIT_G  = 7;
int IO_DIGIT_DP = 6;

int IO_DIGIT_1 = 5;
int IO_DIGIT_2 = 4;
int IO_DIGIT_3 = 3;
int IO_DIGIT_4 = 2;

int IO_DIGIT_PORTS[] = {
  IO_DIGIT_A,
  IO_DIGIT_B,
  IO_DIGIT_C,
  IO_DIGIT_D,
  IO_DIGIT_E,
  IO_DIGIT_F,
  IO_DIGIT_G,
  IO_DIGIT_DP,
};

int IO_DIGITS[] = {
  IO_DIGIT_1,
  IO_DIGIT_2,
  IO_DIGIT_3,
  IO_DIGIT_4,  
};

int LED_ON = LOW;
int LED_OFF = HIGH;

int IO_DIGIT_PORT_COUNT = 8;
int IO_DIGIT_COUNT = 4;

// 1桁を光らせるのに止めるwaitミリ秒
int DIGIT_WAIT = 1;

int NUMBER_ARRAY[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0}, // 9  
};

int NUM_SEGMENTS = 8;

void setup() {
  for(int i = 0;i < IO_DIGIT_PORT_COUNT;i++){
    pinMode(IO_DIGIT_PORTS[i], OUTPUT);
  }
  for(int i = 0;i < IO_DIGIT_COUNT;i++){
    pinMode(IO_DIGITS[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0;i < 10000; i++){
    show4DigitNumber(i, 1000);  
  }
}

void show4DigitNumber(int number, int wait){
  int digit_1 = (number / 1000) % 10;
  int digit_2 = (number / 100) % 10;
  int digit_3 = (number / 10) % 10;
  int digit_4 = number % 10;
  for(int i = 0;i < wait / (DIGIT_WAIT * 4);i++){
    digitalWrite(IO_DIGITS[0], LED_OFF);
    showNumber(digit_1);
    delay(DIGIT_WAIT);
    clearNumber();
    digitalWrite(IO_DIGITS[0], LED_ON);
    digitalWrite(IO_DIGITS[1], LED_OFF);
    showNumber(digit_2);
    delay(DIGIT_WAIT);
    clearNumber();
    digitalWrite(IO_DIGITS[1], LED_ON);
    digitalWrite(IO_DIGITS[2], LED_OFF);
    showNumber(digit_3);
    delay(DIGIT_WAIT);
    clearNumber();
    digitalWrite(IO_DIGITS[2], LED_ON);
    digitalWrite(IO_DIGITS[3], LED_OFF);
    showNumber(digit_4);
    delay(DIGIT_WAIT);
    clearNumber();
    digitalWrite(IO_DIGITS[3], LED_ON);
  }
}

void showNumber(int number){
  for(int i = 0;i < NUM_SEGMENTS;i++){
    if(NUMBER_ARRAY[number][i] == 0){
      digitalWrite(IO_DIGIT_PORTS[i], LED_OFF);
    }else{
      digitalWrite(IO_DIGIT_PORTS[i], LED_ON);
    }
  }
}

void clearNumber(){
  for(int i = 0;i < NUM_SEGMENTS;i++){
    digitalWrite(IO_DIGIT_PORTS[i], LED_OFF);
  }
}

