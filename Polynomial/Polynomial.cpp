//
// Created by Admin on 12.07.2018.
//
#include "Polynomial.h"

Polynom:: Polynom(std::string &polynomial): si(hasmonomials(polynomial)), components(new Component [si])
{
    extractingmonomials(polynomial);
    negativesignmulcof( );
    sortpolyexp( );
    resize(adductionandresize());
}

int Polynom::size() const
{
    return si;
}

Component* Polynom::getComponents()const {
    return components;
}

Polynom::Polynom(const Polynom & polynom){
    si = polynom.size();
    components = new Component [polynom.size()];
    for(int i = 0; i < polynom.size(); i++)
        components[i] = polynom.getComponents()[i];
}

Polynom::~Polynom(){
    delete [] components;
}

Polynom& Polynom::operator=(Polynom& polynom) {
    if (this == &polynom) {
        return *this;
    }
    si = polynom.size();
    delete [] components;
    components = new Component [polynom.size()];
    for(int i = 0; i < polynom.size(); i++)
        components[i] = polynom.getComponents()[i];
    return *this;

}

Component& Polynom::operator[](size_t i){
    if (i >= 0 && i < si)
        return components[i];
    else
        return components[0];
}

const Component& Polynom::operator[](size_t i) const
{
    if (i >= 0 && i < si)
        return components[i];
    else
        return components[0];
}



std::string Polynom::toString(){
    std::string res;

    for(int i = 0; i < si; i++) {


        if (components[i].exponent != 0 && components[i].exponent != 1)
            res += (i == 0 || components[i].coefficient < 0 ? "" : "+")
                   + std::to_string(components[i].coefficient) + '*'
                   + "x^" + std::to_string(components[i].exponent);
        if(components[i].exponent == 1)
            res += (i == 0 || components[i].coefficient < 0 ? "" : "+")
                   + std::to_string(components[i].coefficient) + '*'
                   + "x";
        if(components[i].exponent == 0)
            res += (i == 0 || components[i].coefficient < 0 ? "" : "+")
                   + std::to_string(components[i].coefficient);

    }

    return res;

}


int Polynom::hasmonomials(std::string &polynomial){
    int k = 1;
    int i = 0;
    if(polynomial[i] == '-')
        i++;
    while(polynomial[i] != '\0') {
        if (polynomial[i] == '+' || polynomial[i] == '-')
            k++;
        i++;
    }
    return k;
}


void Polynom::negativesignmulcof( )
{
    for (int i = 0; i < si; i++) {
        if(components[i].negative_sign)
            components[i].coefficient = components[i].coefficient * (-1);
    }
}

//Сортировка полинома по экспоненте
void Polynom::sortpolyexp()
{
    Component temp;
    for (int i = 0; i < si - 1; i++) {
        for (int j = 0; j < si - i - 1; j++) {
            if (components[j].exponent < components[j + 1].exponent) {
                temp = components[j];
                components[j] = components[j + 1];
                components[j + 1] = temp;
            }
        }
    }
}


int Polynom::adductionandresize(){

    int ptrpoly = 0;
    int count = 0;
    for (int i = 0; i < si; i++){
        for (int j = i + 1; j < si; j++) {
            ptrpoly = i;
            if (components[i].exponent == components[j].exponent ) {
                components[i].coefficient += components[j].coefficient;
                ptrpoly = j;
            }
            if(components[i].coefficient == 0)
                count++;
            count += ptrpoly - i;
            i = ptrpoly;
        }
    }
    std::cout << "count: " << count << std::endl << std::endl;

    return si - count;
}


void Polynom::resize(int new_size) {
    Component *str_new = new Component[new_size];
    int j = 0;
    int count = components[0].exponent;
    std::cout << std::endl << std::endl;

    for(int i = 0; i < si; i++) {
        if (components[i].exponent <= count)
            count = components[i].exponent;
        if (components[i].exponent == count) {
            std::cout << count << " " << components[i].coefficient
                      << " " << components[i].exponent   << std::endl;
            count--;
            str_new[j++] = components[i];
        }
    }

    std::cout << std::endl << std::endl;

    si = new_size;
    delete[]components;
    components =  str_new;
}

void Polynom::parscof(std::string &polynomial, std::string &polystrtmp,
                      int &i, int &t, int &k, int id){

    if(polynomial[i + id] != 'x')
        while (polynomial[i + t] != '*' && polynomial[i + t] != '+'
               && polynomial[i + t] != '-' && polynomial[i + t] != '\0') {
            polystrtmp += polynomial[i + t];
            t++;
        }
    else{
        polystrtmp = '1';
        t--;
    }

    components[k].coefficient =  atoll(polystrtmp.c_str());
    polystrtmp.clear();
}



void Polynom::parssign(std::string &polynomial, std::string &polystrtmp,
                       int &i, int &t, int &k){

    //Знак у коэффициента
    if(polynomial[i] == '-')
        components[k].negative_sign = 1;
    else
        components[k].negative_sign = 0;

}
void Polynom::parsexp(std::string &polynomial, std::string &polystrtmp,
                      int &i, int &t, int &k, int id){

    //Парсим экспоненту
    if (polynomial[i + t + 1] == 'x')
        if (polynomial[i + t + 2] == '+' || polynomial[i + t + 2] == '-' || polynomial[i + t + 2] == '\0')
            components[k].exponent = 1;
        else {
            int j = 3;
            while (polynomial[i + t + j] != '+' && polynomial[i + t + j] != '-'
                   && polynomial[i + t + j] != '\0') {
                polystrtmp += polynomial[i + t + j];
                j++;
            }
            components[k].exponent = atoll(polystrtmp.c_str());
            polystrtmp.clear();
        }

    if(polynomial[i + id] != 'x') {
        if (polynomial[i + t] == '+' || polynomial[i + t] == '-' || polynomial[i + t] == '\0')
            components[k].exponent = 0;
    }

}


void Polynom::parsall(std::string &polynomial, std::string &polystrtmp,
                      int &i, int &t, int &k, int id){

    parscof(polynomial,polystrtmp, i, t, k,id);
    parssign(polynomial,polystrtmp, i, t, k);
    parsexp(polynomial,polystrtmp, i, t, k,id);
    k++;
}

int Polynom::extractingmonomials(std::string &polynomial) {

    int k = 0;
    int i = 0;
    int t = 0;
    int id = 0;

    std::string polystrtmp;

    if(polynomial[i] != '-')
        parsall(polynomial,polystrtmp, i, t, k, id);

    while(polynomial[i] != '\0') {
        if (polynomial[i] == '+' || polynomial[i] == '-') {
            t = 1;
            id =1;
            parsall(polynomial,polystrtmp, i, t, k, id);
        }
        i++;
    }

}

void Polynom::derivative(){
    int f =0;
    for (int i = 0; i < si; i++)
        if (components[i].exponent != 0) {
            components[i].coefficient = components[i].coefficient *
                                        components[i].exponent;
            components[i].exponent = components[i].exponent - 1;
        } else {
            components[i].coefficient = 0;
            f = 1;
        }
    if(f)
        resize(si -1);
    
}

//Прверка на лишение символы
int checksymbols(std::string &polynomial){
    int i = 0;
    while(polynomial[i] != '\0'){

        if(polynomial[i] != '1'&&
           polynomial[i] != '2'&&
           polynomial[i] != '3'&&
           polynomial[i] != '4'&&
           polynomial[i] != '5'&&
           polynomial[i] != '6'&&
           polynomial[i] != '7'&&
           polynomial[i] != '8'&&
           polynomial[i] != '9'&&
           polynomial[i] != '0'&&
           polynomial[i] != '+'&&
           polynomial[i] != '-'&&
           polynomial[i] != '*'&&
           polynomial[i] != '^'&&
           polynomial[i] != 'x')
            return 1;
        i++;
    }
    return 0;
}

std::string derivative(std::string &polynomial){


    if(!checksymbols(polynomial)){
        Polynom poly(polynomial);
        std::cout << poly.toString() << std::endl;
        poly.derivative();
        std::cout << poly.toString() << std::endl;
        return poly.toString();
    }
    else
        return "";

}
