#include <iostream>

#include "complex_t.h"
#include "vector.h"
#include "matrix.h"

int main()
{
//Complex
    std::cout << "Hello world!\n";
    std::cout<<"Complex Sample Test:\n";
    complex_t c1(2,3),c2(3,2),c3;

    std::cout<<"\nComplex Addition C1+C2\n";
    c3=c1+c2;
    c3.showComplex();

    std::cout<<"\nComplex Subtraction C1-C2\n";
    c3=c1-c2;
    c3.showComplex();

    std::cout<<"\nComplex Multiplication C1*C2\n";
    c3=c1*c2;
    c3.showComplex();

    std::cout<<"\nComplex Division C1/C2\n";
    c3=c1/c2;
    c3.showComplex();

//Vectors
    std::cout<<"\n\nVector Sample Test:\n";
    complex_t s;
    vector v1(2),v2,v3;
    std::cout<<"Set V1 :\n";
    v1.setVector();

    std::cout<<"Set V2 :\n";
    v2.setVector();

    std::cout<<"Vectors Addition V1+V2= \n";
    v3=v1+v2;
    v3.showVector();

    std::cout<<"Vectors Subtraction V1-V2= \n";
    v3=v1-v2;
    v3.showVector();

    std::cout<<"Vectors Multiplication V1*V2= \n";
    s=v1*v2;
    s.showComplex();

    std::cout<<"Vectors Division V1/V2= \n";
    v3=v1/v2;
    v3.showComplex();



//Matrix
    std::cout<<"\n\nMatrix Sample Test:\n";
    matrix m1(2,2),m2(2,2),m3;
    std::cout<<"Set m1 :\n";
    m1.setMatrix();
    std::cout<<"Set m2 :\n";
    m2.setMatrix();

    std::cout<<"Addition m1+m2 is :\n";
    m3=m1+m2;
    m3.showMatrix();

    std::cout<<"Subtraction m1-m2 is :\n";
    m3=m1-m2;
    m3.showMatrix();

    std::cout<<"Multiplication m1*m2 is :\n";
    m3=m1*m2;
    m3.showMatrix();

    std::cout<<"Division m1/m2 is :\n";
    m3=m1+m2;
    m3.showMatrix();
    return 0;
}
