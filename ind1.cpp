#include <iostream>
using namespace std;
int main()
{
    int n = 93; int ten=10,flagOne=0,flagThree=0,max = 0,mul = 1,two = 2; 
    _asm {
        mov eax, n;
    l1:
        mov edx, 0;
        div ten;
        cmp edx, 1;
        je l2;
        cmp edx, 3;
        je l3;
    l2:
        add flagOne, 1;
        cmp eax, 0;
        jne l1;
        jmp l4;
    l3:
        add flagThree, 1;
        cmp eax, 0;
        jne l1;
    l4:
        cmp flagOne, 0;
        je l7;
        cmp flagThree, 0;
        jne l7;

        mov eax, n;
        mov ebx, 0;
    l5:
        mov edx, 0;
        div ten;
        cmp ebx, edx;
        jge l6;
        mov ebx, edx;
    l6:
        cmp eax, 0;
        jne l5;
        add max, ebx;
        jmp l10;
    l7:
        mov ecx, n;
    l8:
        mov eax, ecx;
        mov edx, 0;
        div ten;

        mov ecx, eax;
        mov eax, edx;
        mov ebx, eax;
        mov edx, 0;
        div two;
        cmp edx, 0;
        je l9;
        mov eax, mul;
        imul eax, ebx;
        mov mul, eax;
    l9:
        cmp ecx, 0;
        jne l8;
    l10:

    }
    cout << flagOne << flagThree<<" "<<max<< " "<< mul;
}

