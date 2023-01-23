/**
\file mycomplex.cpp
\brief Заголовочный файл класса Complex
*/

#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/**
\brief Конструктор класса
\param aRe Действительная составляющая
\param aIm Мнимая составляющая
*/
Complex::Complex (double aRe, double aIm)
{
    Re = aRe;
    Im = aIm;
}

/**
\brief Конструктор класса через указатель
\param aRval.Re Действительная составляющая
\param aRval.Im Мнимая составляющая
*/
Complex::Complex (const Complex &aRval)
{
    Re = aRval.Re;
    Im = aRval.Im;
}

/**
\brief Деструктор
*/
Complex::~Complex()
{
    Re = 0.0;
    Im = 0.0;
}

/**
\brief Метод присваивания значения
\param aRe Действительная составляющая
\param aIm Мнимая составляющая
*/
void Complex::Set (double aRe, double aIm)
{
    Re = aRe;
    Im = aIm;
}

/**
\brief Метод присваивания значения
\param aRe Действительная составляющая
\param aIm Мнимая составляющая
\return Модуль
*/
Complex::operator double()
{
    return abs();
}

/**
\brief Метод абсолютное значение
\return Модуль
*/
double Complex::abs()
{
    return sqrt(Re * Re + Im * Im);
}

/**
\brief Оператор +
\param &aRval Комплексное число
\return Сумма
*/
Complex Complex::operator + (const Complex &aRval)
{
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im ;
    return Result;
}

/**
\brief Оператор -
\param &aRval Комплексное число
\return Разность
*/
Complex Complex::operator - (const Complex &aRval)
{
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/**
\brief Оператор +
\param &aRval Комплексное число
\return Сумма
*/
Complex Complex::operator + (const double &aRval)
{
    Complex Result;
    Result.Re = Re + aRval;
    Result.Im = Im;
    return Result;
}

/**
\brief Оператор -
\param &aRval Комплексное число
\return Разность
*/
Complex Complex:: operator - (const  double &aRval)
{
    Complex Result(*this);
    Result.Re = Re - aRval;
    return Result;
}

/**
\brief Оператор *
\param &aRval Комплексное число
\return Произведение
*/
Complex Complex::operator * (const Complex &aRval)
{
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/**
\brief Оператор *
\param &aRval Комплексное число константа
\return Произведение
*/
Complex Complex::operator * (const double &aRval)
{
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}

/**
\brief Оператор /
\param &aRval Комплексное число
\return Частное
*/
Complex Complex::operator / (const double &aRval)
{
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

/**
\brief Оператор +=
\param &aRval Комплексное число
\return Сумма
*/
Complex &Complex::operator += (const Complex &aRval)
{
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

/**
\brief Оператор -=
\param &aRval Комплексное число
\return Разность
*/
Complex &Complex::operator -= (const Complex &aRval)
{
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

/**
\brief Оператор *=
\param &aRval Комплексное число
\return Произведение
*/
Complex &Complex::operator *= (const Complex &aRval)
{
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

/**
\brief Оператор +=
\param &aRval Комплексное число
\return Сумма
*/
Complex &Complex::operator += (const double &aRval)
{
    Re += aRval;
    return *this;
}

/**
\brief Оператор -=
\param &aRval Комплексное число
\return Разность
*/
Complex &Complex::operator -= (const double &aRval)
{
    Re -= aRval;
    return *this;
}

/**
\brief Оператор *=
\param &aRval Комплексное число
\return Произведение
*/
Complex &Complex::operator *= (const double &aRval)
{
    Re *= aRval;
    Im *= aRval;
    return *this;
}

/**
\brief Оператор /=
\param &aRval Комплексное число
\return Частное
*/
Complex &Complex::operator /= (const double &aRval)
{
    Re /= aRval;
    Im /= aRval;
    return *this;
}

/**
\brief Оператор =
\param &aRval Комплексное число
\return Присваивание
*/
Complex &Complex::operator = (const Complex &aRval)
{
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/**
\brief Оператор =
\param &aRval Комплексное число
\return Присваивание
*/
Complex &Complex::operator = (const double &aRval)
{
    Re = aRval;
    Im = 0.0;
    return *this;
}

/**
\brief Оператор >>
\param &aRval Комплексное число
\return сдвиг вправо
*/
istream &operator >> (istream& stream, Complex &aRval)
{
    char tmp[256];
    stream >> aRval.Re >> aRval.Im >> tmp;
    return stream;
}

/**
\brief Оператор <<
\param &aRval Комплексное число
\return сдвиг влево
*/
ostream &operator << (ostream& stream, Complex &aRval)
{
    stream << aRval.Re;
    if(!(aRval.Im < 0))
    {
        stream << '+';
        stream << aRval.Im << 'i';
    }
    return stream;
}

/**
\brief Оператор +
\param &aRval Комплексное число
\return Сумма
*/
Complex operator + (const double& aLval, const Complex &aRval)
{
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im =  aRval.Im;
    return Result;
}

/**
\brief Оператор -
\param &aRval Комплексное число
\return Разность
*/
Complex operator - (const double &aLval, const Complex &aRval)
{
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im =- aRval.Im;
    return Result;
}

/**
\brief Оператор *
\param &aRval Комплексное число
\return Произведение
*/
Complex operator * (const double &aLval, const Complex &aRval)
{
    Complex Result;
    Result.Re = aLval * aRval.Re;
    Result.Im = aLval * aRval.Im;
    return Result;
}
