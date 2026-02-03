#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keypad.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {16, 17, 18, 19};
byte colPins[COLS] = {23, 25, 26};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

#define BTN_ENTER   27
#define BTN_DELETE  32
#define BTN_LEFT    33
#define BTN_RIGHT   14
#define BTN_WAVE    12
#define BTN_CHANNEL 13
#define BTN_SCALE   15
#define BTN_POWER   4

void setup() {
  Serial.begin(115200);

  pinMode(BTN_ENTER, INPUT_PULLUP);
  pinMode(BTN_DELETE, INPUT_PULLUP);
  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);
  pinMode(BTN_WAVE, INPUT_PULLUP);
  pinMode(BTN_CHANNEL, INPUT_PULLUP);
  pinMode(BTN_SCALE, INPUT_PULLUP);
  pinMode(BTN_POWER, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Function Generator");
  display.display();
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("Keypad: ");
    display.println(key);
    display.display();
  }

  if (!digitalRead(BTN_ENTER)) showMsg("ENTER");
  if (!digitalRead(BTN_DELETE)) showMsg("DELETE");
  if (!digitalRead(BTN_LEFT)) showMsg("LEFT");
  if (!digitalRead(BTN_RIGHT)) showMsg("RIGHT");
  if (!digitalRead(BTN_WAVE)) showMsg("WAVE");
  if (!digitalRead(BTN_CHANNEL)) showMsg("CHANNEL");
  if (!digitalRead(BTN_SCALE)) showMsg("SCALE");
  if (!digitalRead(BTN_POWER)) showMsg("POWER");

  delay(150); // simple debounce for testing
}

void showMsg(const char* msg) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.println(msg);
  display.display();
}
