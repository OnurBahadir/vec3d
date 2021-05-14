#include "vec3D.h"
#include <cmath>
#include <memory>

double vec3D::Magnitude() const {
    return sqrt(pow(i,2)+pow(j,2)+pow(k,2));
}

void vec3D::Normalize() {
    if( this->Magnitude()>0.0) {
        std::unique_ptr<vec3D> temp{std::make_unique<vec3D>(*this)};
        i/=(temp->Magnitude());
        j/=(temp->Magnitude());
        k/=(temp->Magnitude());
    }
}

void vec3D::Set(const double &x, const double &y, const double &z) {
    i=x;
    j=y;
    k=z;
}

double vec3D::X() const {
    return i;
}

double vec3D::Y() const {
    return j;
}

double vec3D::Z() const {
    return k;
}

vec3D vec3D::operator+(const vec3D &iVec) const{
    return vec3D(i+iVec.i,j+iVec.j,k+iVec.k);
}

vec3D vec3D::operator-(const vec3D &iVec) const {
    return vec3D(i-iVec.i,j-iVec.j,k-iVec.k);
}

vec3D vec3D::operator+=(const vec3D &iVec) {
    i+=iVec.i;
    j+=iVec.j;
    k+=iVec.k;
    return *this;
}

vec3D vec3D::operator-=(const vec3D &iVec) {
    i-=iVec.i;
    j-=iVec.j;
    k-=iVec.k;
    return *this;
}
vec3D vec3D::operator*(const double &c) const {
    return vec3D(i*c,j*c,k*c);
}
vec3D vec3D::operator/(const double &c) const {
    if(c!=0) {
        return vec3D(i * (1 / c), j * (1 / c), k * (1 / c));
    }
    else{
        return vec3D();
    }
}


vec3D vec3D::operator*=(const double &c) {
    i*=c;
    j*=c;
    k*=c;
    return *this;
}

vec3D vec3D::operator/=(const double &c) {
    if(c!=0.0) {
        i *= (1/c);
        j *= (1/c);
        k *= (1/c);
        return *this;
    }
    return vec3D(0,0,0);
}

double vec3D::operator*(const vec3D &iVec) const{
    return i*iVec.i+j*iVec.j+k*iVec.k;
}

vec3D vec3D::operator^(const vec3D &iVec) const {
    return vec3D( j*iVec.k-iVec.j*k,k*iVec.i-iVec.k*i,i*iVec.j-iVec.i*j);
}

std::ostream &operator<<(std::ostream &out, const vec3D &iVec) {
    out <<iVec.i<<"i "<<iVec.j<<"j "<<iVec.k<<"k ";
    return out;
}

bool vec3D::operator<(const vec3D &iVec) const {
    return (this->Magnitude() < iVec.Magnitude());
}

bool vec3D::operator>(const vec3D &iVec) const {
    return (this->Magnitude() > iVec.Magnitude());
}

bool operator==(const vec3D &iVec1, const vec3D &iVec2) {
    return ( iVec1.i==iVec2.i && iVec1.j==iVec2.j && iVec1.k==iVec2.k );
}

double vec3D::operator[](const int &b) const {
    switch (b) {
        case 0:
            return i;
            break;
        case 1:
            return j;
            break;
        case 2:
            return k;
            break;
        default:
            return 0;
            break;
    }
}

double AngleBetweenVec3D(const vec3D &iVec1,const vec3D &iVec2){
    return acos((iVec1.i*iVec2.i+iVec1.j*iVec2.j+iVec1.k*iVec2.k)/(iVec1.Magnitude()*iVec2.Magnitude()))*(180.0/M_PI);
}



