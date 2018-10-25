//Робот с функцией следования по белой полосе "изоленте".

// *********************** Установка выводов моторов ************************
int MotorLeftSpeed = A0; // Левый (А) мотор СКОРОСТЬ — ENA
int MotorLeftForward = 4; // Левый (А) мотор ВПЕРЕД — IN1
int MotorLeftBack = 2; // Левый (А) мотор НАЗАД — IN2
int MotorRightForward = 8; // Правый (В) мотор ВПЕРЕД — IN3
int MotorRightBack = 7; // Правый (В) мотор НАЗАД — IN4
int MotorRightSpeed = A1; // Правый (В) мотор СКОРОСТЬ — ENB
int duration;

// ********************* Установка выводов датчиков линии *******************
const int LineSensorLeft = 12; // вход левого датчика линии
const int LineSensorMiddle = 3; //  вход центрального датчика линии
const int LineSensorRight = 10; // вход правого датчика линии
int SL; // статус левого сенсора
int SM; // статус центрального сенсора
int SR; // статус правого сенсора

// *********************************** SETUP ********************************
void setup ()
{
//*************** Задаем контакты моторов
pinMode (MotorRightBack, OUTPUT); // Правый (В) мотор НАЗАД
pinMode (MotorRightForward, OUTPUT); // Правый (В) мотор ВПЕРЕД
pinMode (MotorLeftBack, OUTPUT); // Левый (А) мотор НАЗАД
pinMode (MotorLeftForward, OUTPUT); // Левый (А) мотор ВПЕРЕД
delay(duration);
//*************** Задаем контакты датчиков полосы
pinMode (LineSensorLeft, INPUT); // определением pin левого датчика линии
pinMode (LineSensorMiddle, INPUT);// определением pin центрального датчика линии
pinMode (LineSensorRight, INPUT); // определением pin правого датчика линии
}
// ****************** Основные команды движения ******************
void forward (int a, int sa) // ВПЕРЕД
{
digitalWrite (MotorRightBack, LOW);
digitalWrite (MotorRightForward, HIGH);
analogWrite (MotorRightSpeed, sa);
digitalWrite (MotorLeftBack, LOW);
digitalWrite (MotorLeftForward, HIGH);
analogWrite (MotorLeftSpeed, sa);
delay (a);
}
void right (int b, int sb) // ПОВОРОТ ВПРАВО (одна сторона)
{
digitalWrite (MotorRightBack, LOW);
digitalWrite (MotorRightForward, LOW);
digitalWrite (MotorLeftBack, LOW);
digitalWrite (MotorLeftForward, HIGH);
analogWrite (MotorLeftSpeed, sb);
delay (b);
}
void left (int k, int sk) // ПОВОРОТ ВЛЕВО (одна сторона)
{
digitalWrite (MotorRightBack, LOW);
digitalWrite (MotorRightForward, HIGH);
analogWrite (MotorRightSpeed, sk);
digitalWrite (MotorLeftBack, LOW);
digitalWrite (MotorLeftForward, LOW);
delay (k);
}
void turnR (int d, int sd) // БЫСТРЫЙ ПОВОРОТ ВПРАВО (обе стороны)
{
digitalWrite (MotorRightBack, HIGH);
digitalWrite (MotorRightForward, LOW);
analogWrite (MotorRightSpeed, sd);
digitalWrite (MotorLeftBack, LOW);
digitalWrite (MotorLeftForward, HIGH);
analogWrite (MotorLeftSpeed, sd);
delay (d);
}
void turnL (int e, int se) // БЫСТРЫЙ ПОВОРОТ ВЛЕВО (обе стороны)
{
digitalWrite (MotorRightBack, LOW);
digitalWrite (MotorRightForward, HIGH);
analogWrite (MotorRightSpeed, se);
digitalWrite (MotorLeftBack, HIGH);
digitalWrite (MotorLeftForward, LOW);
analogWrite (MotorLeftSpeed, se);
delay (e);
}
void back (int g, int sg) // НАЗАД
{   
digitalWrite (MotorRightBack, HIGH);
digitalWrite (MotorRightForward, LOW);
analogWrite (MotorRightSpeed, sg);
digitalWrite (MotorLeftBack, HIGH);
digitalWrite (MotorLeftForward, LOW);
analogWrite (MotorLeftSpeed, sg);
delay (g);
}
void stopp (int f) // СТОП
{
digitalWrite (MotorRightBack, LOW);
digitalWrite (MotorRightForward, LOW);
digitalWrite (MotorLeftBack, LOW);
digitalWrite (MotorLeftForward, LOW);
delay (f);
}
// *********************************** LOOP *********************************
// ********************** Режим следования по ЛИНИИ *************************
void loop ()
{
SL = digitalRead (LineSensorLeft); // считываем сигнал с левого датчика полосы
SM = digitalRead (LineSensorMiddle); // считываем сигнал с центрального датчика полосы
SR = digitalRead (LineSensorRight); // считываем сигнал с правого датичка полосы

// ************************* Следование по белой линии ***********************
// РОБОТ на полосе — едем прямо
if (SL == 0 & SM == 1 & SR == 0 ) // ЧЕРНЫЙ — БЕЛЫЙ — ЧЕРНЫЙ — едем ПРЯМО
{
forward (10, 140);// ПРЯМО (время, скорость)
}
// РОБОТ начинает смещаться с полосы — подруливаем
else if (SL == 1 & SM == 1 & SR == 0) // БЕЛЫЙ — БЕЛЫЙ — ЧЕРНЫЙ — поворот ВЛЕВО
{
left (10, 180);// поворот ВЛЕВО (время, скорость)
}
else if (SL == 0 & SM == 1 & SR == 1) // ЧЕРНЫЙ — БЕЛЫЙ — БЕЛЫЙ — поворот ВПРАВО
{
right (10, 180);// поворот ВПРАВО (время, скорость)
}
// РОБОТ начинает съезжать с полосы — доворачиваем
else if (SL == 0 & SM == 0 & SR == 1) // ЧЕРНЫЙ — ЧЕРНЫЙ — БЕЛЫЙ — поворот ВПРАВО БЫСТРО
{
turnR (50, 150);// РАЗВОРОТ ВПРАВО (время, скорость)
}
else if (SL == 1 & SM == 0 & SR == 0) // БЕЛЫЙ — ЧЕРНЫЙ — ЧЕРНЫЙ — поворот ВЛЕВО БЫСТРО
{
turnL (30, 150);// РАЗВОРОТ ВЛЕВО (время, скорость)
}
// РОБОТ съехал с полосы — кружим, ищем полосу
else if (SL == 0 & SM == 0 & SR == 0) // ЧЕРНЫЙ — ЧЕРНЫЙ — ЧЕРНЫЙ — поворот затяжной ВЛЕВО
{
left (10, 130); // поворот ВЛЕВО (время, скорость)
}
else if (SL == 1 & SM == 1 & SR == 1) // БЕЛЫЙ — БЕЛЫЙ — БЕЛЫЙ — поворот затяжной ВПРАВО
{
forward (10, 140);// ПРЯМО (время, скорость)
}
}
