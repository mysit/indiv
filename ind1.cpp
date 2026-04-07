// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    int n = 193;
    int ten = 10, two = 2, four = 4;
    int sum = 0, max = 0, min = 9, count = 0, result = 0;

    _asm {
        // Считаем сумму цифр, max и min
        mov eax, n;
        mov ebx, ten;

    l1:
        mov edx, 0;
        div ebx;

        add sum, edx;      // сумма цифр

        // ищем max
        cmp edx, max;
        jle l2;
        mov max, edx;

    l2:
        // ищем min
        cmp edx, min;
        jge l3;
        mov min, edx;

    l3:
        cmp eax, 0;
        jne l1;

        // проверяем чётность суммы
        mov eax, sum;
        mov edx, 0;
        div two;
        cmp edx, 0;
        jne l5;

        // чётная сумма: max - min
        mov eax, max;
        sub eax, min;
        mov result, eax;
        jmp l7;

    l5:
        // нечётная сумма: считаем цифры, кратные 4
        mov eax, n;
        mov ecx, 0;        // ecx - счётчик

    l6:
        mov edx, 0;
        div ebx;

        // проверяем, делится ли цифра (edx) на 4
        push eax;
        mov eax, edx;
        mov edx, 0;
        div four;
        cmp edx, 0;
        jne l8;
        add ecx, 1;

    l8:
        pop eax;
        cmp eax, 0;
        jne l6;

        mov count, ecx;    // сохраняем счётчик в count
        mov result, ecx;   // result = ecx (напрямую из регистра)

    l7:
    }

    cout << result;
}
