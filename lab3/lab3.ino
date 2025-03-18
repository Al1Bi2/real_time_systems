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

  // Задаём ширину каждого сектора потенциометра
  int maxled = 1023 / 3;

  // Выбор пина в зависимости от значения потенциометра
  int ledpin = potValue / maxled;

  // Управление светодиодами в зависимости от значения потенциометра
  if (ledpin == 0) {  // Значение около 0
    digitalWrite(ledPin1, HIGH);  // Включаем красный
    digitalWrite(ledPin2, LOW);   // Выключаем зеленый
    digitalWrite(ledPin3, LOW);   // Выключаем синий
  } else if (ledpin == 1) {  // Значение около ½
    digitalWrite(ledPin2, HIGH);  // Включаем зеленый
    digitalWrite(ledPin1, LOW);   // Выключаем красный
    digitalWrite(ledPin3, LOW);   // Выключаем синий
  } else {  // Значение около 1
    digitalWrite(ledPin3, HIGH);  // Включаем синий
    digitalWrite(ledPin1, LOW);   // Выключаем красный
    digitalWrite(ledPin2, LOW);   // Выключаем зеленый
  }

  delay(50);  // Пауза для стабилизации
}
