#include<stdio.h>;
#include<math.h>;
#include<stdlib.h>;


int main(int argc, char *argv[])
{
    float a, b, s;
    //Числа, с которыми работает Калькулятор
    //a - первое число, b - второе, s - результат(используется только для возведения в степень)
    int fac, ask, sym, a1, b1, a2, b2, a3, b3, ask2;
    // fac - переменная для факториала, ask - переменная продолжения работы, sym - для выбора операции
    ask = 1; // ask = 1, программа работает
    char in[100], out[100];
    while (ask != 0) //Присвоение переменной ask значение 0 прекратит работу программы
    //Работа с калькулятором в файле
    //1. Выбор векторного(2), либо обычного калькулятора(1)
    //2. Ввод чисел, либо векторов(если числа, то через пробел 1-е 2-е, если вектора, то аналогично но с координатами)
    //3. Выбор операции
    //При работе с числами в файле input будет 4 числа, ппри работе с векторами 6
    { 
        printf("Введите название файла для входных данных(***.txt):\n");
        scanf("%s", &in);
        printf("Введите название файла для выходных данных(***.txt):\n");
        scanf("%s", &out);
        FILE *input, *output;
        input = fopen(in, "r");
        output = fopen(out, "w");
        fprintf(output, "Выберите действие:\n(1)Обычный калькулятор\n(2)Векторные операции\n");
        fscanf(input, "%d", &ask2);//Выбор калькурятора(векторный или простой)
        if (ask2 == 2)// ask2 = 2, выполняются векторные операции
        {
            fprintf(output, "Введите значения первого вектора(a1,b1)\n");
            fscanf(input, "%d", &a1);//х координата первого вектора
            fscanf(input, "%d", &b1);//у координата первого вектора
            fprintf(output, "Введите значения второго вектора(a2,b2)\n");
            fscanf(input, "%d", &a2);//х координата второго вектора
            fscanf(input, "%d", &b2);//у координата второго вектора
            fprintf(output, "Выберите операцию:\n1.Сложение\n2.Вычитание\n3.Скалярное произведение\n");
            fscanf(input, " %d", &sym);//Выбор операции
        
            switch (sym) 
                {
                    case 1: //Сложение векторов
                    {
                        a3 = a1 + a2;
                        b3 = b1 + b2;
                        fprintf(output, "Результат:(%d, %d)+(%d, %d) ", a1, b1, a2, b2);
                        fprintf(output, "=(%d, %d)\n", a3, b3);
                    }
                    break;
                    case 2: //Вычитание векторов
                    {
                        a3 = a1 - a2;
                        b3 = b1 - b2;
                        fprintf(output, "Результат:(%d, %d)-(%d, %d) ", a1, b1, a2, b2);
                        fprintf(output, "=(%d, %d)\n", a3, b3);
                    }
                    break;
                    case 3://Скалярное призведение векторов
                    {
                        a3 = a1 * b1 + a2 * b2;
                        fprintf(output, "Результат:(%d, %d)*(%d, %d) ", a1, b1, a2, b2);
                        fprintf(output, "=(%d)\n", a3);
                    }
                    break;
                    default: fprintf(output, "Упс... Что-то пошло не так :(");//Ошибка при несответствии ни одному из условий
                }
        }
        else if (ask2 == 1)//Обычный калькулятор
            {
                fprintf(output, "\nВведите первое число:\n");
                fscanf(input, "%f", &a);
                fprintf(output, "Введите второе число:\n");
                fscanf(input, "%f", &b);
                fprintf(output, "Выберите операцию:\n1. Сложение\n2. Вычитание\n3. Умножение\n");
                fprintf(output, "4. Деление\n5. Возведение 1-го числа в степень 2-го\n6. Возведение 2-го числа в степень 1-го\n7. Факториал первого числа\n8. Факториал второго числа\n");
                fprintf(output, "Для выбора операции введите в конcоль её номер:\n");
                fscanf(input, " %d", &sym);//Выбор операции
                switch (sym) 
                {
                    case 1:
                    fprintf(output, "Результат: %f+%f=%f", a, b, a+b); //Операия сложения
                    break;
                    case 2:
                    fprintf(output, "Результат: %f-%f=%f", a, b, a-b); //Операция вычитания
                    break;
                    case 3:
                    fprintf(output, "Результат: %f*%f=%f", a, b, a*b); //Операция умножения
                    break;
                    case 4:
                    fprintf(output, "Результат: %f/%f=%f", a, b, a/b); //Операция деления
                    break;
                    case 5:
                    s = powf (a, b);
                    fprintf(output, "Результат: %f^%f=%f", a, b, s); //Возведение 1-го числа в степень 2-го
                    break;
                    case 6:
                    s = powf (b, a);
                    fprintf(output, "Результат: %f^%f=%f", b, a, s); //Предыдущее наоборот
                    break;
                    case 7:
                    {
                       fac = 1;
                       if (a > 0)
                      {
                       for (int i=1; i <= a; i++)
                       fac = fac * i;
                       fprintf(output, "Результат: %f!=%d", a, fac); //Факториал 1-го числа
                      }
                       else 
                       fprintf(output, "Упс... Что-то пошло не так :("); //Если введенный символ не является числом у которого можно найти факториал
                    }
                    break;
                     case 8:
                       {
                       fac = 1;
                       if (b > 0)
                       {
                       for (int i=1; i <= b; i++)
                           fac = fac * i;
                       fprintf(output, "Результат: %f!=%d", b, fac); //Факториал 2-го числа
                       }
                       else 
                       fprintf(output, "Упс... Что-то пошло не так :("); 
                    }
                    break;
                    default: fprintf(output, "Упс... Что-то пошло не так :(");//Ошибка при несответствии ни одному из условий
                }
            }
        fprintf(output, "\nГорбанев Кирилл 4группа 1курс ФизФак. Спасибо за использование программы");
        fclose(input);
        fclose(output);
        printf("Продолжить работу?:\n1-да 0-нет\n");
        scanf("%d", &ask);
        
        
    }         
  

return 0;
}