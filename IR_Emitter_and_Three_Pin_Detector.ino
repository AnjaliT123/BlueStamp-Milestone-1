
int IRemitter = 3;
int IRdetector = 2;
int distance;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  pinMode(IRdetector, INPUT);
  pinMode(IRemitter, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {
  int ir = readIR();
  Serial.println(ir);
  delay(100);
  
}

int readIR(){
  tone(IRemitter, 38000, 8);
  delay(1);
  int ir = digitalRead(IRdetector);
  delay(1);
  return ir;
 
}

