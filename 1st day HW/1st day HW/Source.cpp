#include <iostream>
#include <math.h>
using namespace std;


template <class t>
class vec3 {
public:
	t x, y, z;

public:
	vec3();
	vec3(const t& a, const t& b, const t& c);
	vec3(const vec3 &v2);

	vec3 operator+(const vec3& b)const;
	vec3 operator-(const vec3& b)const;
	vec3 operator+=(const vec3& b);
	vec3 operator-=(const vec3& b);
	vec3 operator=(const vec3& b);
	bool operator==(const vec3& b)const;
	vec3 operator/=(int b);

	vec3 normalize();
	void zero();
	bool is_zero()const;
	t distance_to(const vec3& b)const;

};

template <class t>
vec3<t>::vec3() {
	x = 0;
	y = 0;
	z = 0;
}

template <class t>
vec3<t>::vec3(const t& a, const t& b, const t& c) {
	x = a;
	y = b;
	z = c;
}

template <class t>
vec3<t>::vec3(const vec3 &v2) {
	x = v2.x;
	y = v2.y;
	z = v2.z;
}


template <class t>
vec3<t> vec3<t>::operator+(const vec3& b)const {
	vec3 vecr;

	vecr.x = x + b.x;
	vecr.y = y + b.y;
	vecr.z = z + b.z;

	return vecr;
}

template <class t>
vec3<t> vec3<t>::operator-(const vec3& b)const {
	vec3 vecr;

	vecr.x = x - b.x;
	vecr.y = y - b.y;
	vecr.z = z - b.z;
		
	return vecr;
}

template <class t>
vec3<t> vec3<t>::operator+=(const vec3& b) {
	
	x += b.x;
	y += b.y;
	z += b.z;

	return *this;
}

template <class t>
vec3<t> vec3<t>::operator-=(const vec3& b) {

	x -= b.x;
	y -= b.y;
	z -= b.z;

	return *this;
}

template <class t>
vec3<t> vec3<t>::operator=(const vec3& b) {

	x = b.x;
	y = b.y;
	z = b.z;

	return *this;
}

template <class t>
bool vec3<t>::operator==(const vec3& b)const {

	return (x == b.x && y == b.y && z == b.z);
}


template <class t>
vec3<t> vec3<t>::operator/=(int b) {

	x /= b;
	y /= b;
	z /= b;
	
	return *this;
}

template <class t>
vec3<t> vec3<t>::normalize() {

	return (*this /= (sqrt(x * x + y * y + z * z)));
}

template <class t>
void vec3<t>::zero() {
	
	x = 0; y = 0; z = 0;
}

template <class t>
bool vec3<t>::is_zero()const {

	return (x == 0 && y == 0 && z == 0);
}


template <class t>
t vec3<t>::distance_to(const vec3& b)const {

	return sqrt((b.x - x) + (b.y - y) + (b.z - z));
}

int main() {

	vec3 <int> veca(1, 1, 1);
	vec3 <int> vecb(1, 2, 3);
	vec3 <int> vecc;

	vecc = veca + vecb;
	cout << "Vec1.x = " << vecc.x << endl;
	cout << "Vec1.y = " << vecc.y << endl;
	cout << "Vec1.z = " << vecc.z << endl << endl;

	vecc = vecc - vecb;
	cout << "Vec2.x = " << vecc.x << endl;
	cout << "Vec2.y = " << vecc.y << endl;
	cout << "Vec2.z = " << vecc.z << endl << endl;

	vecc += veca;
	cout << "Vec3.x = " << vecc.x << endl;
	cout << "Vec3.y = " << vecc.y << endl;
	cout << "Vec3.z = " << vecc.z << endl << endl;

	vecc -= veca;
	cout << "Vec4.x = " << vecc.x << endl;
	cout << "Vec4.y = " << vecc.y << endl;
	cout << "Vec4.z = " << vecc.z << endl << endl;

	vecc = vecb;
	cout << "Vec5.x = " << vecc.x << endl;
	cout << "Vec5.y = " << vecc.y << endl;
	cout << "Vec5.z = " << vecc.z << endl << endl;

	int comp1 = (vecc == veca);
	int comp2 = (vecc == vecb);

	cout << "Comp1 = " << comp1 << endl << endl;
	cout << "Comp2 = " << comp2 << endl << endl;


	vec3 <float> vecd(242.34, 23.4, 4.456);
	cout << "Vecd.x = " << vecd.x << endl << endl;
	cout << "Vecd.y = " << vecd.y << endl << endl;
	cout << "Vecd.z = " << vecd.z << endl << endl;

	vecd.normalize();
	cout << "Vecd.x Normalize = " << vecd.x << endl << endl;
	cout << "Vecd.y Normalize = " << vecd.y << endl << endl;
	cout << "Vecd.z Normalize = " << vecd.z << endl << endl;

	vec3 <int> vec0 (69, 48, 86);
	vec0.zero();

	cout << "Vec0.x = " << vec0.x << endl << endl;
	cout << "Vec0.y = " << vec0.y << endl << endl;
	cout << "Vec0.z = " << vec0.z << endl << endl;

	cout << "Is Vec0 == 0?: " << vec0.is_zero() << endl << endl;
	cout << "Is Vecd == 0?: " << vecc.is_zero() << endl << endl;  

	vec3 <float>vecf(2.0, 2.0, 2.0);
	vec3 <float>vecg(4.0, 4.0, 4.0);

	cout << "Distance from Veca to Vecf =  " << vecf.distance_to(vecg) << endl << endl;

	return 0;
}