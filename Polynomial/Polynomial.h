//
// Created by Admin on 12.07.2018.
//
#ifndef POLYNOMIAL_POLYNOMIAL_H

#include <iostream>
#include <string>

#include <cstddef>
#include <cmath>

typedef struct {
    int negative_sign;
    //unsigned int coefficient;
    //unsigned int exponent;
    int coefficient;
    int exponent;
} Component;


class Polynom {
public:

    explicit Polynom(std::string &polynomial);
    int size() const;
    Component* getComponents()const;
    Polynom(const Polynom & polynom);
    ~Polynom();
    Polynom& operator=(Polynom& polynom);
    Component& operator[](size_t i);
    const Component& operator[](size_t i) const;
    std::string toString();
    void derivative();

private:

    int si;
    Component *components;

    int hasmonomials(std::string &polynomial);
    int extractingmonomials(std::string &polynomial);

    void negativesignmulcof( );

    void parscof(std::string &polynomial, std::string &polystrtmp,
                 int &i, int &t, int &k, int id);
    void parssign(std::string &polynomial, std::string &polystrtmp,
                  int &i, int &t, int &k);
    void parsexp(std::string &polynomial, std::string &polystrtmp,
                 int &i, int &t, int &k, int id);
    void parsall(std::string &polynomial, std::string &polystrtmp,
                          int &i, int &t, int &k, int id);

    //Сортировка полинома по экспоненте
    void sortpolyexp();
    int adductionandresize();
    void resize(int new_size);
};

//Прверка на лишение символы
int checksymbols(std::string &polynomial);
//Производная
std::string derivative(std::string &polynomial);

#define POLYNOMIAL_POLYNOMIAL_H
#endif //POLYNOMIAL_POLYNOMIAL_H
