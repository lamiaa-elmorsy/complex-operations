#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "complex_t.h"
#include "vector.h"
#define MAX_SIZE 50
class matrix:public vector{
    int row , col;
    vector mVec[MAX_SIZE];
    protected:

    public:
        matrix (){
            row=0;
            col=0;
        }
        matrix (int x,int y){
            row=x;
            col=y;
        }

        void setMatrix();
        void showMatrix();
        matrix operator+ (matrix m);
        matrix operator- (matrix m);
        matrix operator* (matrix m);
        matrix operator/ (matrix m);
        ~matrix() { }

};

void matrix::setMatrix(){
    if (row==0){
        std::cout<<"Please Enter the number of Rows: ";
        std::cin>>row;
    }
    if (col==0){
        std::cout<<"Please Enter the number of Rows: ";
        std::cin>>col;
    }
    for (int k=0; k<row; k++){
        std::cout << "Enter Row number"<<k+1<<"data\n";
        mVec[k].setVector(col); // col here will be the length of the vector
    }
}
void matrix::showMatrix(){
    for(int ii=0 ; ii<row;ii++){
        mVec[ii].showVector();
        std::cout<<"\n";
    }
}

matrix matrix::operator+ (matrix m){
    matrix r(row , col);
    for(int j=0 ; j<row ;j++){
        r.mVec[j]=mVec[j]+ m.mVec[j];
    }
    return r;
}
matrix matrix::operator- (matrix m){
    matrix r(row , col);
    for(int j=0 ; j<row ;j++){
        r.mVec[j]=mVec[j]- m.mVec[j];
    }
    return r;
}

matrix matrix::operator* (matrix m){
    if (col !=m.row){
        std::cout<<"ERROR: Number of Row in the first matirx should Equal the Number of Columns in the second matrix\n";
        exit(1);
    }
    matrix r(row , m.col);
    vector x,y,sumVec(m.col);
    complex_t b,a,mul,ssum;

    for(int j=0 ,jj=0,z=0,zz=0 ; j<row ;){
        x=mVec[j]; // x represents each row -vector- in matrix 1
     while(zz< m.col){
        while (z<col || jj<m.row){
            b=x.getMemberOfvector(z);  // b Represent each element in each row in matrix 1

            y=m.mVec[jj]; // y represents each row -vector- in matrix 2

            a=y.getMemberOfvector(zz); // a represent the element of all vector in the same COLUMN

// Int the first loop b= m1[0][0] , a= m2[0][0]
            mul=a * b;
            ssum.add(mul);
            z++; jj++;
// Int the second loop b=m1[0][1] , a= m2[1][0]
// they will be multiply to each other and added to the previous result stored in 'ssum'
           }
// 'ssum' will be put in 'sumVec'
            sumVec.setMemberOfvector(zz,ssum);
           z=0;zz++;jj=0;
           ssum.setComplex(0.0,0.0); // reset ssum
          }
// the row number j in the result matrix = sumVec
          r.mVec[j]=sumVec;
          j++; zz=0;z=0;jj=0;
// j++ to go to the next row in matrix 1
//jj=0 to go to the first row in matrix 2
//z=0 , zz=0 to access the first element ot rows for the next loop
   }
    return r;
}

matrix matrix::operator/ (matrix m){
    matrix r(row , col);
    for(int j=0 ; j<row ;j++){
        r.mVec[j]=mVec[j]/ m.mVec[j];
    }
    return r;
}
#endif // MATRIX_H_INCLUDED
