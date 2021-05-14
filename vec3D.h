//
// Created by hob on 14.05.2021.
//

#ifndef VEC3D_VEC3D_H
#define VEC3D_VEC3D_H

#include <iostream>
class vec3D {
    public:
        vec3D() : i(0), j(0), k(0) {};
        explicit vec3D(const double &x) : i(x), j(0), k(0) {};
        explicit vec3D(const double &x, const double &y) : i(x), j(y), k(0) {};
        explicit vec3D(const double &x, const double &y, const double &z) : i(x), j(y), k(z) {};

    public:
        double Magnitude() const;
        void Normalize();
        void Set(const double &x, const double &y, const double &z);
        double X() const;
        double Y() const;
        double Z() const;

        vec3D operator+(const vec3D &iVec)const ;
        vec3D operator-(const vec3D &iVec)const ;
        vec3D operator+=(const vec3D &iVec);
        vec3D operator-=(const vec3D &iVec);

        vec3D operator*(const double &c)const ;
        vec3D operator/(const double &c)const ;
        vec3D operator*=(const double &c);
        vec3D operator/=(const double &c);

        double operator*(const vec3D &iVec)const;    // * = dot product
        vec3D operator^(const vec3D &iVec)const ; // ^ = cross product

        bool operator<(const vec3D &iVec) const;
        bool operator>(const vec3D &iVec) const;
        friend bool operator==(const vec3D &iVec1, const vec3D &iVec2);

        friend std::ostream &operator<<(std::ostream &out, const vec3D &iVec);
        double operator[](const int &b) const;

        friend double AngleBetweenVec3D(const vec3D &iVec1, const vec3D &iVec2);

    private:
        double i, j, k;
    };

#endif //VEC3D_VEC3D_H
