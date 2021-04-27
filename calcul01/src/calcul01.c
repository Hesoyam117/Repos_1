#include<stdio.h> 
#include<math.h>

int main(int argc, char *argv[])
{
    float a, b, s;
    //Числа, с которыми работает Калькулятор
    //a - первое число, b - второе, s - результат(используется только для возведения в степень)
    int fac, ask, sym, a1, b1, a2, b2, ask2;
    // fac - переменная для факториала, ask - переменная продолжения работы, sym - для выбора операции
    ask = 1; // ask = 1, программа работает
    while (ask != 0) //Присвоение переменной ask значение 0 прекратит работу программы
    { 
        printf("Выберите действие:\n(1)Обычный калькулятор\n(2)Векторные операции\n");
        scanf("%d", &ask2);//Выбор калькурятора(векторный или простой)
        if (ask2 == 2)// ask2 = 2, выполняются векторные операции
        {
            printf("Введите значения первого вектора(a1,b1)\n");
            scanf("%d", &a1);//х координата первого вектора
            scanf("%d", &b1);//у координата первого вектора
            printf("Введите значения второго вектора(a2,b2)\n");
            scanf("%d", &a2);//х координата второго вектора
            scanf("%d", &b2);//у координата второго вектора
            printf("Выберите операцию:\n1.Сложение\n2.Вычитание\n3.Скалярное произведение\n");
            scanf(" %d", &sym);//Выбор операции
        
            switch (sym) 
                {
                    case 1: //Сложение векторов
                    {
                        a1 = a1 + a2;
                        b1 = b1 + b2;
                        printf("Результат:(%d, ", a1);
                        printf("%d)\n", b1);
                    }
                    break;
                    case 2: //Вычитание векторов
                    {
                        a1 = a1 - a2;
                        b1 = b1 - b2;
                        printf("Результат:(%d, ", a1);
                        printf("%d)\n", b1);
                    }
                    break;
                    case 3://Скалярное призведение векторов
                    {
                        a1 = a1 * b1 + a2 * b2;
                        printf("Результат:%d\n", a1);
                    }
                    break;
                    default: printf("Упс... Что-то пошло не так :(");//Ошибка при несответствии ни одному из условий
                }
        }
        else if (ask2 == 1)//Обычный калькулятор
            {
                printf("\nВведите первое число:\n");
                scanf("%f", &a);
                printf("Введите второе число:\n");
                scanf("%f", &b);
                printf("Выберите операцию:\n1. Сложение\n2. Вычитание\n3. Умножение\n");
                printf("4. Деление\n5. Возведение 1-го числа в степень 2-го\n6. Возведение 2-го числа в степень 1-го\n7. Факториал первого числа\n8. Факториал второго числа\n");
                printf("Для выбора операции введите в конcоль её номер:\n");
                scanf(" %d", &sym);//Выбор операции
                switch (sym) 
                {
                    case 1:
                    printf("Результат: %f", a+b); //Операия сложения
                    break;
                    case 2:
                    printf("Результат: %f", a-b); //Операция вычитания
                    break;
                    case 3:
                    printf("Результат: %f", a*b); //Операция умножения
                    break;
                    case 4:
                    printf("Результат: %f", a/b); //Операция деления
                    break;
                    case 5:
                    s = powf (a, b);
                    printf("Результат: %f", s); //Возведение 1-го числа в степень 2-го
                    break;
                    case 6:
                    s = powf (b, a);
                    printf("Результат: %f", s); //Предыдущее наоборот
                    break;
                    case 7:
                    {
                       fac = 1;
                       if (a > 0)
                      {
                       for (int i=1; i <= a; i++)
                       fac = fac * i;
                       printf("Результат: %d", fac); //Факториал 1-го числа
                      }
                       else 
                       printf("Упс... Что-то пошло не так :("); //Если введенный символ не является числом у которого можно найти факториал
                    }
                    break;
                     case 8:
                       {
                       fac = 1;
                       if (b > 0)
                       {
                       for (int i=1; i <= b; i++)
                           fac = fac * i;
                       printf("Результат: %d", fac); //Факториал 2-го числа
                       }
                       else 
                       printf("Упс... Что-то пошло не так :("); 
                    }
                    break;
                    default: printf("Упс... Что-то пошло не так :(");//Ошибка при несответствии ни одному из условий
                }
            }
    printf("\nЧтобы продолжить работу введите '1'\nЧтобы прекратить работу введите '0'\n"); 
                //Присвоение значения переменной ask. 0 - завершение работы.
                //Любое другое значение - завершение работы
    scanf("%d", &ask);
    }  
printf("Горбанев Кирилл 4группа 1курс ФизФак. Спасибо за использование программы");
return 0;
}

    

