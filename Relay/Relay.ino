int fan = 7; // Pin 7 controls the fan ON and OFF
int state = 0; // state at which the fan is 
float tmp = 0; // temperature reading from the temp sensor
void setup()
{
  pinMode(fan,OUTPUT); // configuring the fan pin as an output to control the fan 
  Serial.begin(9600);
}

void loop()
{
    int reading = analogRead(A0); // reading the temp sensor value
    float voltage = reading*5; // voltage multiplied by its ref value
    voltage /= 1024;  // divided by 1024(max value of analog range)
    tmp = (voltage-0.5)*100; // converting to deg C   
    Serial.print("Temperature(deg C) is : ");
    Serial.println(tmp);// printing temp
    delay (500);
    
    /************************logic starts********************/
    if(tmp>29) 
    {
       state= 1;
    }
    else
    {
      state = 0;
    }
    /**********************logic ends***********************/
  digitalWrite(fan,state); // turning the fan off or on
  if (state != 1)
  {
    Serial.println("Fan OFF"); // printing fan's state
  }
  else 
  {
    Serial.println("Fan ON"); // printing fan's state
  }
  
  
}
