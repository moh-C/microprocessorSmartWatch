#include <Wire.h>              // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
#include "RTClib.h"            // Library for RTC Time Module
#include <dht.h>               // Humidity Sensor

RTC_DS1307 rtc; // Initializing the rtc module
dht DHT;        // Humidity sensor init
// After finding LCD's I2C address, we initialize it via it's library's constructor
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4); // Change to (0x27,16,2) for 16x2 LCD.

#define DHT11_PIN 11

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; // Days of the week for RTC Module

// Requirements for Serial Communication
const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;

// Decoder Inputs
int A_BCD = 2;
int B_BCD = 3;
int C_BCD = 4;
int D_BCD = 5;

// Decoder Enables
int H01_Enable = 6;
int H02_Enable = 7;
int M01_Enable = 8;
int M02_Enable = 9;

// Setup
void setup()
{
    Serial.begin(115200);
    Serial.println("<Arduino is ready>");

    pinMode(A_BCD, OUTPUT);
    pinMode(B_BCD, OUTPUT);
    pinMode(C_BCD, OUTPUT);
    pinMode(D_BCD, OUTPUT);

    pinMode(H01_Enable, OUTPUT);
    pinMode(H02_Enable, OUTPUT);
    pinMode(M01_Enable, OUTPUT);
    pinMode(M02_Enable, OUTPUT);

    //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    lcd.init();
    lcd.backlight();
}

// Main loop
void loop()
{
    rtc_to_lcd();
    showTime();
    recvWithStartEndMarkers();
    showNewData();
}

// Showing the time and date on LCD
void rtc_to_lcd()
{
    DateTime now = rtc.now();

    int humidity = 10;
    int temperature = 12;

    if (now.minute() == 8)
        rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));

    lcd.setCursor(5, 0);             // Set the cursor on the first column and first row.
    lcd.print(convert_to_date(now)); // Print the string "Hello World!"
    lcd.setCursor(6, 3);             //Set the cursor on the third column and the second row (counting starts at 0!).
    lcd.print(convert_to_time(now));
    lcd.setCursor(3, 1); //Set the cursor on the third column and the second row (counting starts at 0!).

    if (now.second() % 4 == 0)
    {
        DHT.read11(DHT11_PIN);
        humidity = DHT.humidity;
        temperature = DHT.temperature;
    }

    lcd.print(humidity_sensor("Humidity: ", humidity));
    lcd.setCursor(1, 2); //Set the cursor on the third column and the second row (counting starts at 0!).
    lcd.print(humidity_sensor("Temperature: ", temperature));
}

String humidity_sensor(String type_, int num)
{
    String res = type_;
    res += String(num);
    return res;
}

// Showing time on seven segments
void showTime()
{
    DateTime now = rtc.now();
    int hour_ = now.hour();
    int minute_ = now.minute();

    digitalWrite(H01_Enable, HIGH);
    digitalWrite(H02_Enable, LOW);
    digitalWrite(M01_Enable, LOW);
    digitalWrite(M02_Enable, LOW);
    //Serial.println("Hour_H");
    DecimalToBCDDecoder(hour_ / 10);
    delay(25);

    digitalWrite(H01_Enable, LOW);
    digitalWrite(H02_Enable, HIGH);
    digitalWrite(M01_Enable, LOW);
    digitalWrite(M02_Enable, LOW);
    //Serial.println("Hour_L");
    DecimalToBCDDecoder(hour_ % 10);
    delay(25);

    digitalWrite(H01_Enable, LOW);
    digitalWrite(H02_Enable, LOW);
    digitalWrite(M01_Enable, HIGH);
    digitalWrite(M02_Enable, LOW);
    //Serial.println("Minute_H");
    DecimalToBCDDecoder(minute_ / 10);
    delay(25);

    digitalWrite(H01_Enable, LOW);
    digitalWrite(H02_Enable, LOW);
    digitalWrite(M01_Enable, LOW);
    digitalWrite(M02_Enable, HIGH);
    //Serial.println("Minute_L");
    DecimalToBCDDecoder(minute_ % 10);
    delay(25);
}

void DecimalToBCDDecoder(int inp)
{
    String outPut = binaryConvertor(inp);
    int D_inp = outPut[0] - '0';
    int C_inp = outPut[1] - '0';
    int B_inp = outPut[2] - '0';
    int A_inp = outPut[3] - '0';
    digitalWrite(A_BCD, A_inp);
    digitalWrite(B_BCD, B_inp);
    digitalWrite(C_BCD, C_inp);
    digitalWrite(D_BCD, D_inp);

    /*Serial.print(" D: ");
    Serial.print(D_inp);
    Serial.print(" C: ");
    Serial.print(C_inp);
    Serial.print(" B: ");
    Serial.print(B_inp);
    Serial.print(" A: ");
    Serial.println(A_inp);*/
}

// Converting the time to be shown on LCD
String convert_to_time(DateTime now)
{
    String res = "";

    res += zero_padding(now.hour());
    res += ":";
    res += zero_padding(now.minute());
    res += ":";
    res += zero_padding(now.second());

    return res;
}

// Converting the date to be shown on LCD
String convert_to_date(DateTime now)
{
    String res = "";

    res += zero_padding(now.year());
    res += "/";
    res += zero_padding(now.month());
    res += "/";
    res += zero_padding(now.day());

    return res;
}

// Zero padding for LCD
String zero_padding(int next)
{
    if (next == 0)
        return "00";
    if (next <= 9 && next >= 0)
    {
        return ('0' + String(next));
    }
    return String(next);
}

// Zero padding for Binary conversion of decimal.
String zero_padding(String toBePadded)
{
    while (toBePadded.length() != 4)
    {
        toBePadded = '0' + toBePadded;
    }
    return toBePadded;
}

// Binary converter!
String binaryConvertor(int number)
{
    uint8_t bitsCount = sizeof(number) * 8;
    char str[bitsCount + 1];
    itoa(number, str, 2);
    return zero_padding(str);
}

void recvWithStartEndMarkers()
{
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && newData == false)
    {
        rc = Serial.read();

        if (recvInProgress == true)
        {
            if (rc != endMarker)
            {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars)
                {
                    ndx = numChars - 1;
                }
            }
            else
            {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker)
        {
            recvInProgress = true;
        }
    }
}

void showNewData()
{
    if (newData == true)
    {
        Serial.println(receivedChars);
        String hell_ = String(receivedChars);
        int year_ = hell_.substring(10, 14).toInt();
        int month_ = hell_.substring(14, 16).toInt();
        int day_ = hell_.substring(16, 18).toInt();
        int hour_ = hell_.substring(18, 20).toInt();
        int minute_ = hell_.substring(20, 22).toInt();
        rtc.adjust(DateTime(year_, month_, day_, hour_, minute_, 0));
        newData = false;
    }
}