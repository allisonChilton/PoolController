
/*
//change it to enum if possible
int currentState;

int lastTemp;
int lastSecond;
int tempPin = A0;
int input = 0;
bool previousButtonState = false;
bool pumpOn;
bool heaterOn;

void setup() {
  lastSecond = 0;
  currentState = 0;
  pumpOn = false;
  heaterOn = true;
  pinMode(tempPin, INPUT);
  lcd.begin(16, 4);
  lastTemp = round((((5*analogRead(tempPin))/1024.0)-0.5)*180+32);
  showMenu();
}

void loop() {

  //if(currentState == 0 && (millis()/1000)%2==0)
  if(currentState == 0 && millis()/1000 != lastSecond) { //this seems more stable
    lastSecond = millis()/1000;
    updateTemp();
  }

  if(digitalRead(leftPin) == HIGH) {
    input = 1;
  } else if(digitalRead(rightPin) == HIGH) {
    input = 2;
  } else if(digitalRead(upPin) == HIGH){
    input = 3;
  } else if(digitalRead(downPin) == HIGH){
    input = 4;
  } else{
     input = 0; 
  }
  
  if(previousButtonState == 0 && input !=0) //rising edge
  {
    switch(currentState)
    {
       case 0:
          handleStart();
          break;
       case 1:
          handlePump();
          break;
       case 2:
          handleHeater();
          break;
       case 3:
          handleAddPump();
          break;
       case 4:
          handleAddHeater();
          break;
       case 5:
          handleRemovePump();
          break;
       case 6:
          handleRemoveHeater();
          break;
       case 7:
          handleRemovePumpConfirmation();
          break;
       case 8:
          handleRemoveHeaterConfirmation();
          break;
          
    }
  }
 previousButtonState = input;
 
  // print the number of seconds since reset:
  //lcd.print(millis()/1000);
}



void updateTemp(){
  
  float temperature = (((5*analogRead(tempPin))/1024.0)-0.5)*180+32;
  
  if(abs((lastTemp-temperature))<1){
    lcd.setCursor(9,3);
    lcd.print((int)temperature);
    lcd.print((char)223);
    lastTemp = temperature;
  }
}

void showMenu(){
  currentState = 0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1.Pump");
  lcd.setCursor(0,1);
  
  lcd.print("2.Heater");
  updateTemp();
}

void showPump(){
  currentState = 1;
  lcd.clear();
  lcd.setCursor(0,0);
  if(pumpOn) {
    lcd.print("1.Turn Off");
  } else {
    lcd.print("1.Turn On");
  }
  lcd.setCursor(0,1);
  lcd.print("2.Add Setting");
  lcd.setCursor(-4,2);
  lcd.print("3.Remove Setting");
  lcd.setCursor(-4,3);
  lcd.print("4.Back");
}

void showHeater(){
  currentState = 2;
  lcd.clear();
  lcd.setCursor(0,0);
  if(heaterOn){
    lcd.print("1.Turn Off");
  } else {
    lcd.print("1.Turn On");
  }
  lcd.setCursor(0,1);
  lcd.print("2.Add Setting");
  lcd.setCursor(-4,2);
  lcd.print("3.Remove Setting");
  lcd.setCursor(-4,3);
  lcd.print("4.Back");
}

void showAddPump(){
  currentState = 3; 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Add Pump");
  lcd.setCursor(0,1);
  lcd.print("1.Back");
}

void showAddHeater(){
  currentState = 4; 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Add Heater");
  lcd.setCursor(0,1);
  lcd.print("1.Back");
}

void showRemovePump(){
  currentState = 5; 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Remove Pump");
  lcd.setCursor(0,1);
  lcd.print("1.Back");
}

void showRemoveHeater(){
  currentState = 6; 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Remove Heater");
  lcd.setCursor(0,1);
  lcd.print("1.Back");
}

void turnOnPump(){
  pumpOn = true;
}

void turnOffPump(){
  pumpOn = false;
}

void turnOnHeater(){
  heaterOn = true;
}

void turnOffHeater(){
  heaterOn = false; 
}

void displayIP(){
  
}

void handleStart(){
  switch(input)
  {
     case 1:
       showPump();
       break; 
    case 2:
       showHeater();
       break;
  }
}

void handlePump() {
  switch(input)
  {
     case 1:
       if(pumpOn)
         turnOffPump();
       else
         turnOnPump();
       showPump();
       break; 
    case 2:
       showAddPump();
       break;
    case 3:
       showRemovePump();
       break;
    case 4:
       showMenu();
       break;
  }
}

void handleHeater() {
  switch(input)
  {
     case 1:
       if(heaterOn)
         turnOffHeater();
       else
         turnOnHeater();
       showHeater();
       break; 
    case 2:
       showAddHeater();
       break;
    case 3:
       showRemoveHeater();
       break;
    case 4:
       showMenu();
       break;
  }
}

void handleAddPump() {
  switch(input)
  {
     case 1:
       showPump();
       break;
  }
}

void handleAddHeater() {
  switch(input)
  {
     case 1:
       showHeater();
       break;
  } 
}

void handleRemovePump() {
  switch(input)
  {
     case 1:
       showPump();
       break;
  }
}

void handleRemoveHeater() {
  switch(input)
  {
     case 1:
       showHeater();
       break;
  }
}

void handleRemovePumpConfirmation() {
  
}

void handleRemoveHeaterConfirmation() {
  
}