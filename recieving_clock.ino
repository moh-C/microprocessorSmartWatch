#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include<SoftwareSerial.h>

char* time_data = "";

// WiFi network
const char* ssid     = "Hello";
const char* password = "12345678";

ESP8266WebServer server (80);

char htmlResponse[3000];

void handleRoot() {

  snprintf ( htmlResponse, 3000,
"<!DOCTYPE html>\
<html lang=\"en\">\
  <head>\
    <meta charset=\"utf-8\">\
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\
  </head>\
  <body>\
          <h1>Time</h1>\
          <input type='text' name='date_hh' id='date_hh' size=2 autofocus> hh \
          <input type='text' name='date_mm' id='date_mm' size=2 autofocus> mm \
          <div>\
          <br><button id=\"save_button\">Save</button>\
          </div>\
    <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js\"></script>\    
    <script>\
      var hh;\
      var mm;\
      $('#save_button').click(function(e){\
        e.preventDefault();\
        hh = $('#date_hh').val();\
        mm = $('#date_mm').val();\      
        $.get('/save?hh=' + hh + '&mm=' + mm, function(data){\
          console.log(data);\
        });\
      });\      
    </script>\
  </body>\
</html>"); 

   server.send ( 200, "text/html", htmlResponse );  

}


void handleSave() {
  
  Serial.write(server.arg("hh")[0]);
  Serial.write(server.arg("hh")[1]);
  Serial.write(server.arg("mm")[0]);
  Serial.write(server.arg("mm")[1]);
  Serial.println();
}


void setup() {
  Serial.begin(9600);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on ( "/", handleRoot );
  server.on ("/save", handleSave);

  server.begin();
  Serial.println ( "HTTP server started" );
}

void loop() {
  server.handleClient();
  time_data = "";
}