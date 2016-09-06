unsigned int val = 0;
unsigned char PIN = 0;
int old_sensorValue=0;
int sensorValue=0;
bool Drink = false;
bool turn = true;

void setup() {
    Serial.begin(9600);
    pinMode(PIN,INPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(8, OUTPUT);

   sensorValue = analogRead(PIN);    
}
    
void loop() {
     
    sensorValue = analogRead(PIN);
    int cali_sensorValue = (sensorValue - 150)/10;
    if(old_sensorValue == 0){
     old_sensorValue = cali_sensorValue;
    }
    if(turn == true){
        Serial.print("0.0");
        Serial.println(cali_sensorValue);
    } else if (turn == false){
        Serial.println("4h28");
    }
    if(abs(cali_sensorValue-old_sensorValue) > 4 && Drink == false){
     if (cali_sensorValue < 50){
        digitalWrite(3, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(8, HIGH);
      } else if(cali_sensorValue > 50){
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(8, LOW);
        if(cali_sensorValue < old_sensorValue){
          turn = false;
        }
        Drink = true;
      } 
    }old_sensorValue=cali_sensorValue;
    delay(500);
}
