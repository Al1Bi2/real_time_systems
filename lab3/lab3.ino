// Пины для подключения светодиодов
const int ledPin1 = 9;  // Светодиод 1 (красный)
const int ledPin2 = 10; // Светодиод 2 (зеленый)
const int ledPin3 = 11; // Светодиод 3 (синий)

// Пин для потенциометра
const int potPin = A0;

void setup() {
  // Инициализация пинов для светодиодов как выходных
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  // Инициализация последовательного порта для вывода данных
  Serial.begin(9600);
}

void loop() {
  // Чтение значения с потенциометра (диапазон от 0 до 1023)
  int potValue = analogRead(potPin);


  // Вывод значения на монитор порта
  Serial.print("Потенциометр: ");
  Serial.println(potValue);

  //Задаём ширину каждого сектора потенциометра(1026 для того чтобы при взятии модуля от 1023 не было 1)
  int maxled = 1026/3;
  // Преобразование значения с потенциометра в диапазон от 0 до 255
  int ledvalue = map(potValue%(maxled),0,maxled,0,255);
  //Выбор пина в зависимости от значения потенциометра
  int ledpin = potValue/(maxled);
  // Управление светодиодами в зависимости от значения потенциометра
  if (ledpin ==0) {  // Значение около 0
    analogWrite(ledPin1, ledvalue);   
    digitalWrite(ledPin2, LOW);  
    digitalWrite(ledPin3, LOW);   
  } else if (ledpin==1) {  // Значение около ½
    analogWrite(ledPin2, ledvalue);   
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin3, LOW);  
  } else {  // Значение около 1
    analogWrite(ledPin3, ledvalue);   
    digitalWrite(ledPin1, LOW);  
    digitalWrite(ledPin2, LOW);   
  }

  delay(50); 
} 
