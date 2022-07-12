#include "vector3.h"
#include <cmath>

void Vector3::invert() {
    x *= -1;
    y *= -1;
    z *= -1;
}


float Vector3::magnitude() const {
    return sqrt(x * x + y * y + z * z);
}


float Vector3::squareMagnitude() const {
    return x * x + y * y + z * z;
}


void Vector3::normalize() {
    float len = magnitude();

    if(len > 0) 
        (*this)*= ((float)1) / len;
}

void Vector3::operator*=(const float value) {
    x *= value;
    y *= value;
    z *= value;
}


Vector3 Vector3::operator*(const float value) const {
    return Vector3(x * value, y * value, z * value);
}


Vector3 Vector3::operator/(const float value) const {
    return Vector3(x / value, y / value, z / value);
}

void Vector3::operator+=(const Vector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
}

Vector3 Vector3::operator+(const Vector3& v) {
    return Vector3(x + v.x, y + v.y, z + v.z);
}


void Vector3::operator-=(const Vector3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

Vector3 Vector3::operator-(const Vector3& v) {
    return Vector3(x - v.x, y - v.y, z - v.z);
}



void Vector3::addScaledVector(const Vector3& vector, float scale) {
    x += vector.x * scale;
    y += vector.y * scale;
    z += vector.z * scale;
}


Vector3 Vector3::componentProduct(const Vector3& vector) const {
    return Vector3(x * vector.x, y * vector.y, z * vector.z);
}


void Vector3::componentProductUpdate(const Vector3& vector) {
    x *= vector.x;
    y *= vector.y;
    z *= vector.z;
}

void Vector3::clear() {
    x = 0;
    y = 0;
    z = 0;
}


float Vector3::scalarProduct(const Vector3& vector) const {
    return x * vector.x + y * vector.y + z * vector.z;

}


float Vector3::operator*(const Vector3& vector) const {
    return x * vector.x + y * vector.y + z * vector.z;
}



Vector3 Vector3::vectorProduct(const Vector3& vector) const {
    return Vector3(
                y * vector.z - z * vector.y,
                z * vector.x - x * vector.z,
                x * vector.y - y * vector.x
            );
}


void Vector3::operator%=(const Vector3& vector) {
    *this = vectorProduct(vector); 
}



Vector3 Vector3::operator%(const Vector3& vector) const {
    return Vector3(
                y * vector.z - z * vector.y,
                z * vector.x - x * vector.z,
                x * vector.y - y * vector.x
            );
}
