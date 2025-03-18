int redPin = 9;   // Пин для красного цвета
int greenPin = 10; // Пин для зеленого цвета
int bluePin = 11;  // Пин для синего цвета

// Массив RGB значений для 7 цветов радуги (русский порядок)
int rainbowColors[7][3] = {
  {255, 0, 0},     // Красный
  {255, 69, 0},   // Оранжевый
  {255, 255, 0},   // Желтый
  {0, 255, 0},     // Зеленый
  {0, 255, 255},   // Голубой
  {0, 0, 255},     // Синий
  {255, 0, 255}  // Фиолетовый
};

void setup() {
  // Устанавливаем пины как выходы
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // На всякий случай устанавливаем 0 на выводах
  analogWrite(redPin, 0);  
  analogWrite(greenPin, 0);  
  analogWrite(bluePin, 0);  
}

void loop() {
  // Переход по всем цветам радуги
  for (int i = 0; i < 7; i++) {
    analogWrite(redPin, rainbowColors[i][0]);
    analogWrite(greenPin, rainbowColors[i][1]);
    analogWrite(bluePin, rainbowColors[i][2]);
    delay(1000); // Задержка 1 секунда на каждом цвете
  }
}
