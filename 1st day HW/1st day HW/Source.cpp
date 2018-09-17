#include <iostream>
using namespace std;

double sqroot(int b) {

	double res;
	int r;

	for (res = b; res > 0; res--) {
		
		r = res;

		if (b % r == 0)
			break;
	}

	return res;
};

template <class t>
class vec3 {
public:
	t x, y, z;

public:
	vec3();
	vec3(t, t, t);
	vec3(const vec3 &v2);

	t min_value();

	vec3 operator+(const vec3& b);
	vec3 operator-(const vec3& b);
	vec3 operator+=(const vec3& b);
	vec3 operator-=(const vec3& b);
	vec3 operator=(const vec3& b);
	int operator==(const vec3& b);
	vec3 operator/=(int b);

	vec3 normalize();
	vec3 zero();
	int is_zero();
	t distance_to(const vec3& b);

};

template <class t>
vec3<t>::vec3() {
	x = 0;
	y = 0;
	z = 0;
}

template <class t>
vec3<t>::vec3(t a, t b, t c) {
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
vec3<t> vec3<t>::operator+(const vec3& b) {
	vec3 vecr;

	vecr.x = this->x + b.x;
	vecr.y = this->y + b.y;
	vecr.z = this->z + b.z;

	return vecr;
}

template <class t>
vec3<t> vec3<t>::operator-(const vec3& b) {
	vec3 vecr;

	vecr.x = this->x - b.x;
	vecr.y = this->y - b.y;
	vecr.z = this->z - b.z;
		
	return vecr;
}

template <class t>
vec3<t> vec3<t>::operator+=(const vec3& b) {
	
	this->x += b.x;
	this->y += b.y;
	this->z += b.z;

	vec3 vecr(this->x, this->y, this->z);

	return vecr;
}

template <class t>
vec3<t> vec3<t>::operator-=(const vec3& b) {

	this->x -= b.x;
	this->y -= b.y;
	this->z -= b.z;

	vec3 vecr(this->x, this->y, this->z);

	return vecr;
}

template <class t>
vec3<t> vec3<t>::operator=(const vec3& b) {

	this->x = b.x;
	this->y = b.y;
	this->z = b.z;

	vec3 vecr(this->x, this->y, this->z);

	return vecr;
}

template <class t>
int vec3<t>::operator==(const vec3& b) {

	if (this->x == b.x && this->y == b.y && this->z == b.z)
		return 1;

	else return 0;
}

template <class t>
vec3<t> vec3<t>::operator/=(int b) {

	vec3 vecr;

	vecr.x = this->x / b;
	vecr.y = this->y / b;
	vecr.z = this->z / b;
	
	return vecr;
}

template <class t>
t vec3<t>::min_value() {

	vec3 b(this->x, this->y, this->z);

	t min = b.x;

	if (min < b.y)
		min = b.y;
	else if (min < b.z);
		min = b.z;

	return min;
}

template <class t>
vec3<t> vec3<t>::normalize() {
	vec3 vecr(this->x, this->y, this->z);
	int	min = vecr.min_value();

	while (min > 0) {

		if ((vecr.x % min) == 0 && (vecr.y % min) == 0 && (vecr.z % min) == 0) {

			vecr.x /= min;
			vecr.y /= min;
			vecr.z /= min;
		}
		min--;
	}

	return vecr;
}

template <class t>
vec3<t> vec3<t>::zero() {
	
	vec3 vec0;
	return vec0;
}

template <class t>
int vec3<t>::is_zero() {
	int res = 0;
	vec3 vecr(this->x, this->y, this->z);
	vec3 zero;

	if (vecr == zero)
		res = 1;

	return res;
}

template <class t>
t vec3<t>::distance_to(const vec3& b) {

	vec3 a(this->x, this->y, this->z);

	t distance;

	distance = sqroot((b.x - a.x) + (b.y - a.y) + (b.z - a.z));

	return distance;
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


	vec3 <int> vecd(24234, 234, 4456);

	vec3 <int> vecn = vecd.normalize();
	
	cout << "Vecd.x = " << vecd.x << endl << endl;
	cout << "Vecd.y = " << vecd.y << endl << endl;
	cout << "Vecd.z = " << vecd.z << endl << endl;

	cout << "Vecd.x normalized = " << vecn.x << endl << endl;
	cout << "Vecd.y normalized = " << vecn.y << endl << endl;
	cout << "Vecd.z normalized = " << vecn.z << endl << endl;

	vec3 <int> vec0 = vec0.zero();

	cout << "Vec0.x = " << vec0.x << endl << endl;
	cout << "Vec0.y = " << vec0.y << endl << endl;
	cout << "Vec0.z = " << vec0.z << endl << endl;

	cout << "Is Vec0 == 0?: " << vec0.is_zero() << endl << endl;
	cout << "Is Vecd == 0?: " << vecd.is_zero() << endl << endl;  

	vec3 <int >vecf(2, 2, 2);

	cout << "Distance from Veca to Vecf =  " << veca.distance_to(vecf) << endl << endl;

	return 0;
}