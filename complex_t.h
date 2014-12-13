#ifndef COMPLEX_T_H_INCLUDED
#define COMPLEX_T_H_INCLUDED

class complex_t{
    double real, img;

    public:
        complex_t (){
            real=0;
            img=0;
        }
        complex_t(double x,double y){
            real=x;
            img=y;
        }
        complex_t readComplex(){
            double x, y;
            std::cin>>x>>y;
            real=x;
            img=y;
            return *this;
        }
        void setComplex(double x,double y){
            real=x;
            img=y;
        }
        void showComplex(){
            if (img>=0)
                std::cout <<real<<"+"<<img<<"i  ";
            else std::cout <<real<<img<<"i  ";
        }

        complex_t operator+ (complex_t c);
        complex_t operator- (complex_t c);
        complex_t operator* (complex_t c);
        complex_t operator/ (complex_t c);

        void add(complex_t c);
       ~complex_t(){}

};
void complex_t::add(complex_t c){
    real=real+ c.real;
    img= img + c.img;
}

complex_t complex_t::operator+ (complex_t c){
    complex_t r;
    r.real=real+ c.real;
    r.img= img + c.img;
    return r;
}
complex_t complex_t::operator- (complex_t c){
    complex_t r;
    r.real=real- c.real;
    r.img= img - c.img;
    return r;
}
complex_t complex_t::operator* (complex_t c){
    complex_t r;
    r.real=(real*c.real)- (img*c.img);
    r.img= (img *c.real) + (real * c.img);
    return r;
}
complex_t complex_t::operator/ (complex_t c){
    double rr;
    complex_t r;
    rr= (c.real*c.real)+(c.img*c.img);
    r.real=(real*c.real+img*c.img)/rr;
    r.img=(img*c.real-real*c.img)/rr;
    return r;
    }

#endif // COMPLEX_T_H_INCLUDED
