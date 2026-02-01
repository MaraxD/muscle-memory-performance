const int ECG_PIN = 34;      // Semnal analogic ECG
const int LO_PLUS = 33;      // Detectie deconectare electrozi LO+
const int LO_MINUS = 32;     // Detectie deconectare electrozi LO-

void setup() {
Serial.begin(9600);  

pinMode(LO_PLUS, INPUT);
pinMode(LO_MINUS, INPUT);
}


void loop() {
int loPlusState = digitalRead(LO_PLUS);
int loMinusState = digitalRead(LO_MINUS);  

  // Verificam daca electrozii sunt deconectati

if (loPlusState == HIGH || loMinusState == HIGH) {
  Serial.println("!!! ELECTROZI DECONTECTATI !!!");
  } else {

  // Citim semnalul ECG
  int ecgValue = analogRead(ECG_PIN);
  Serial.println(ecgValue); // pentru Serial Plotter
  }

delay(100); // ritm de esantionare rapid
}