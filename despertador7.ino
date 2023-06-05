const int ledVermelha = 4; 
const int ledAmarela = 5;
const int ledVerde = 6;
const int buzzerPin = 7;     
const int button = 8; 
const int buttonVermelho = 10; 
const int buttonAmarelo = 12;
const int buttonVerde = 13;

int ldrValue = 0;
int contacertos = 0;
int cont = 0;
const int freq = 5;  
int ledLista[5];
int botoes[5];
int indexLedList = 0;
int indexBotoes = 0;
int prox = indexBotoes + 1;
bool n = false;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(buttonVerde, INPUT_PULLUP);
  pinMode(buttonVermelho, INPUT_PULLUP);
  pinMode(buttonAmarelo, INPUT_PULLUP);
  pinMode(ledVermelha, OUTPUT);
  pinMode(ledAmarela, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  int x = digitalRead(button);
  if (x == LOW) {
    Serial.println("Apertou");
    
  
  maino();
}
 ldrValue = analogRead(0);
  if(cont<5 && ldrValue<150){ 
  tone(buzzerPin, 1000);            
  delay(25);
  noTone(buzzerPin);  
  delay(ldrValue / freq);
 }
  

  }


void randomBlink() {
  int ledPins[] = {ledVermelha, ledAmarela, ledVerde};
  int randomIndex = random(0, 3);  
  int ledPin = ledPins[randomIndex];
  ledLista[indexLedList] = ledPin;
  Serial.println("pisquei");
  indexLedList++;
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}



void jogador(){
  int rverd = digitalRead(buttonVerde);
  int rverm = digitalRead(buttonVermelho);
  int rama= digitalRead(buttonAmarelo);
  ldrValue = analogRead(0);  
  if(cont<5 && ldrValue<150){
  tone(buzzerPin, 1000);            
  delay(25);
  noTone(buzzerPin);  
  delay(ldrValue / freq);
  }
  if (rverd == LOW){
    delay(200);
    botoes[indexBotoes] = ledVerde;
    if (botoes[indexBotoes] == ledLista[indexBotoes]){
      indexBotoes++;
      Serial.println("adicionado");
      cont ++;
    }else{
      indexBotoes = 0;
      indexLedList = 0;
      cont = 0;
      maino();

    }
    
  }
  else if (rverm == LOW){
    delay(200);
    botoes[indexBotoes] = ledVermelha;
    if (botoes[indexBotoes] == ledLista[indexBotoes]){
      indexBotoes++;
      Serial.println("adicionado");
      cont ++;
    }else{
      indexBotoes = 0;
      indexLedList = 0;
      cont = 0;
      maino();

    }
  
    
  
  }
  else if (rama == LOW){
    delay(200);
    botoes[indexBotoes] = ledAmarela;
    if (botoes[indexBotoes] == ledLista[indexBotoes]){
      indexBotoes++;
      Serial.println("adicionado");
      cont ++;
    }else{
      indexBotoes = 0;
      indexLedList = 0;
      cont = 0;
      maino();

    }
  }
}

void maino(){
  for (int i = 0; i < 5; i++) {
      randomBlink();
  }
  
  while(indexBotoes<5){
    jogador();
  }
}