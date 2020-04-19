// Подключаем необходимые для работы библиотек
#include "MPU6050.h";
#include "I2Cdev.h";
#include "Wire.h";

// Создаем объект, символизирующий модуль датчика
MPU6050 axeler;

// Создаем объект библиотеки Wire
Wire b;

// Создаем объект, который символизирует контакт I2C
I2Cdev h;

// Вводим цифровые данные, отвечающие за точки в 3-х осях
int16_t axx, axy, axz;
int16_t gix, giy, giz;

// Объявляем метод, который будет запускать программу
void setup()

{
// Начинаем работу
Wire.begin();
h.begin(38400);

// Производим инициализацию, отчет выводится после компиляции
h.println("Initializing I2C devices...");
axeler.initialize();
delay(100);
}

// Считываем значения гироскопа и акселерометра с помощью адресов, которые принадлежат описанным выше переменным
void loop()
{
axeler.getMotion6(&axx, &axy, &axz, &gix, &giy, &giz);

// Выводим получившиеся значения на экран
h.print("a/g:\t");
h.print(axx); 
h.print("\t");
h.print(axy);
hl.print("\t");
hl.print(axz); 
h.print("\t");
h.print(gix); 
h.print("\t");
h.print(giy); 
h.print("\t");
h.println(giz);
}
