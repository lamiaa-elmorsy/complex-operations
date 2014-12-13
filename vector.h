#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <exception>
#include <stdlib.h>
#include "complex_t.h"
#define MAX_LENGTH 50

class vector:public complex_t{

    int length;
    complex_t vComp[MAX_LENGTH];
    public:
        vector (){
            length=0;
        }
        vector(int l){
            length=l;
            if (length==0){
                std::cout<<"Please Enter The Vector's Length: ";
                std::cin>>length;
            }
        }

        void setVector();
        void setVector(int l);
        void showVector();
        void setMemberOfvector (int index , complex_t x);
        complex_t getMemberOfvector (int index);
        vector operator+ (vector v);
        vector operator- (vector v);
        complex_t operator* (vector v);
        vector operator/ (vector v);

        ~vector(){
            //abort();
        }
};

void vector::setMemberOfvector(int index , complex_t x){
    vComp[index] =x;
}

complex_t vector::getMemberOfvector (int index){
    return vComp[index];
}
void vector::setVector(){
    if (length==0){
        std::cout<<"Please Enter The Vector's Length: ";
        std::cin>>length;
    }
    for (int i=0; i<length; i++){
        std::cout << "Enter Complex Number_"<< i+1<<" (real img): ";
        vComp[i]= complex_t::readComplex() ;
    }
    std::cout<<"\n";
}
void vector::setVector(int l){
    length=l;
    if (length==0){
        std::cout<<"Please Enter The Vector's Length: ";
        std::cin>>length;
    }
    for (int i=0; i<length; i++){
        std::cout << "Enter Complex Number_"<< i+1<<" (real img): ";
        vComp[i]= complex_t::readComplex() ;
    }
    std::cout<<"\n";
}
void vector::showVector(){
    for (int i=0; i<length; i++){
        vComp[i].showComplex();
    }
    std::cout<<"\n";
}


vector vector::operator+ (vector v){
    if (v.length != length){
        std::cout<<"ERROR: Vectors should have the same length";
        exit(1);
    }
    vector r(length);
    for(int i=0 ; i<length ;i++){
        r.vComp[i]=vComp[i]+ v.vComp[i];
    }
    return r;
}
vector vector::operator- (vector v){
    if (v.length != length){
        std::cout<<"ERROR: Vectors should have the same length";
        exit(1);
    }
    vector r(v.length);
    for(int i=0 ; i<length ;i++){
        r.vComp[i]=vComp[i]- v.vComp[i];
    }
    return r;
}
complex_t vector::operator* (vector v){
    if (v.length != length){
        std::cout<<"ERROR: Vectors should have the same length";
        exit(1);
    }
    complex_t result,r;
    for (int i=0;i<length;i++){
        r=vComp[i] * v.vComp[i];
        result.add(r);
    }
    return result;
}
vector vector::operator/ (vector v){
    if (v.length != length){
        std::cout<<"ERROR: Vectors should have the same length";
        exit(1);
    }
    vector r (v.length);
    for (int i=0;i<length;i++){
        r.vComp[i]=vComp[i] / v.vComp[i];
    }
    return r;
}

#endif // VECTOR_H_INCLUDED
