int redPin = 9;   // Пин для красного цвета
int greenPin = 10; // Пин для зеленого цвета
int bluePin = 11;  // Пин для синего цвета

void setup() {
  // Устанавливаем пины как выходы
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  //На всякий случай устанавливаем 0 на выводах
  analogWrite(redPin, 0);  
  analogWrite(greenPin, 0);  
  analogWrite(bluePin, 0);  
}

void loop() {
  //Переход от красного к зеленому
  for (int i = 255; i >=0; i--) {
    analogWrite(redPin, i);        
    analogWrite(greenPin, 255 - i); 
    delay(15);
  }
  //Переход от зеленого к синему
  for (int i = 255; i >=0; i--) {   
    analogWrite(greenPin, i); 
    analogWrite(bluePin, 255-i);        
    delay(15);
  }
  //Переход от синего к красному
  for (int i = 255; i >=0; i--) {
    analogWrite(redPin, 255-i);        
    analogWrite(bluePin, i);    
    delay(15); 
  }

}