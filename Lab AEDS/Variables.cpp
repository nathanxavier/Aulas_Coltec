#include <iostream>

using namespace std;
int main()
{
    cout << "Tamanho Bool: " << sizeof(bool) << endl;
    cout << "Tamanho Char: " << sizeof(char) << endl;

    cout << "\nInteiros: " << endl;
    cout << "Tamanho Unsigned Short Int: " << sizeof(unsigned short) << endl;
    cout << "Tamanho Short Int: " << sizeof(short) << endl;
    cout << "Tamanho Unsigned Long Int: " << sizeof(unsigned long) << endl;
    cout << "Tamanho Long: " << sizeof(long) << endl;
    cout << "Tamanho Int: " << sizeof(int) << endl;
    cout << "Tamanho Unsigned Long Long: " << sizeof(unsigned long long) << endl;
    cout << "Tamanho Long Long: " << sizeof(long long) << endl;
    cout << "Tamanho Unsigned Int: " << sizeof(unsigned int) << endl;

    cout << "\nPontos Flutuantes: " << endl;
    cout << "Tamanho Float: " << sizeof(float) << endl;
    cout << "Tamanho Double: " << sizeof(double) << endl;

    int a = 0;
    cout << a << "\t" << a++ << "\t" << a << "\t" << ++a << "\t" << a << endl;
}