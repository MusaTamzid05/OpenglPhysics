#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
    public:

        Vector3():
            x(0),
            y(0),
            z(0) {}


        Vector3(const float x, const float y, const float z):
            x(x),
            y(y),
            z(z) {}

        void invert();
        void normalize();

        void operator+=(const Vector3& v);
        Vector3 operator+(const Vector3& v);

        void operator-=(const Vector3& v);
        Vector3 operator-(const Vector3& v);

        void operator*=(const float value);
        Vector3 operator*(const float value) const;
        Vector3 operator/(const float value) const;
        float operator*(const Vector3& vector) const;



        void operator%=(const Vector3& vector);
        Vector3 operator%(const Vector3& vector) const;

        void addScaledVector(const Vector3& vector, float scale);
        Vector3 componentProduct(const Vector3& vector) const;
        void componentProductUpdate(const Vector3& vector);

        void clear();
        void clearAccumulator();

        float scalarProduct(const Vector3& vector) const;


        float magnitude() const;
        float squareMagnitude() const;


        Vector3 vectorProduct(const Vector3& vector) const;

        float x;
        float y;
        float z;

    private:
        float pad;



};
#endif
