/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: carlos
 *
 * Created on November 5, 2019, 8:20 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
 * 
 */
class Fraction{
private:
    int numerator;
    int denominator;
public:
    Fraction (int n, int d) : numerator(n), denominator(d){}
    friend ostream& operator<< (ostream& os, const Fraction& f){
        os << f.numerator << " / " << f.denominator << endl;
        return os;
    }
    Fraction operator* (const Fraction& f) const{
        int n = numerator * f.numerator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }
    Fraction operator+ (const Fraction& f) const{
        int n = numerator * f.denominator +  f.numerator * denominator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }
     Fraction operator- (const Fraction& f) const{
        int n = numerator * f.denominator -  f.numerator * denominator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }
     Fraction operator+ (int x) const{
         int n = numerator + x * denominator;
         int d = denominator;
         return Fraction(n, d);
     }
     Fraction operator/ (const Fraction& f) const{
         int n = numerator * f.denominator;
         int d = denominator * f.numerator;
         return Fraction(n, d);
     }
     bool operator< (const Fraction& f) const{
        Fraction tmp = Fraction(numerator, denominator) - f;
        if (tmp.numerator < 0){
            return true;
        }
        return false;
     }
     friend Fraction operator+ (int x, const Fraction& f){
         return f + x;
     }
};
int main(int argc, char** argv) {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    //Fraction f1(1, 6);
    //Fraction f2(1, 2);
    Fraction f3 = f1 * f2;
    cout << f3;
    f3 = f1 + f2;
    cout << f3;
    f3 = f1 - f2;
    cout << f3;
    f3 = f1 + 2;
    cout << f3;
    f3 = 2 + f1;
    cout << f3;
    f3 = f1 / f2;
    cout << f3;
    if (f1 < f2){
        cout << "F1 is smaller than F2" << endl;
    }
    //How to get the mathematical correct answer? following the associative property? think damn think..
    Fraction f4 = f1 + f2 * f3 + 5 - f2 / f1;
    cout << f4;
    return 0;
}

