#include <Adafruit_NeoPixel.h>
#define PIN      6 
#define NUMPIXELS 9
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);
#define DELAYVAL 1000 // Time (in milliseconds) to pause between pixels

//time variable to be calculated
int currMinute = 0;

//array to store color RGB
int colorArray[] = {
  100,0,0,
  100, 100, 0, 
  0, 100, 0, 
  0, 0, 100, 
  100, 0, 100, 
  100,100,100
}; 

void setup() {
  pixels.begin(); 
  Serial.begin(9600);
}

void loop(){
  pixels.clear();
  //count when number <= 59 add one at each loop
  if(currMinute <= 59){
     calculateBinary();
     currMinute += 1;
  }
   //pixels.setPixelColor(3, pixels.Color(100,100,100));
  pixels.show();   
  delay(DELAYVAL);

}

void calculateBinary(){
  int i = 5;
  Serial.println(currMinute);
  while(i >= 0){
    Serial.print(currMinute >> i & 1);
    if(currMinute >> i & 1){
       //when result is 1 means at least one number used from {1,2,4,8,16,32}
      //light on the corresponing pixel at index i and color position in colorArray
      pixels.setPixelColor(i, pixels.Color(colorArray[i*3], colorArray[i*3+1], colorArray[i*3+2]));
    }else{
      //do nothing since no number used 
    }
    --i;
  }
  Serial.println();
}