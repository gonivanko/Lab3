#include <iostream>
#include <cmath>
using namespace std;
using std::cout;

struct Point
{
	float x, y, z;
};

struct Vector
{
	float x, y, z;

	Vector() { this->x = 0; this->y = 0; this->z = 0; }

	void outputVector();
	void calculateVector(Point A, Point B);
	void vectorProduct(Vector a, Vector b);
	friend float scalarProduct(Vector a, Vector b);
	
};

class Tetrahedron
{
	Point point[4];
	float volume;

public:

	Tetrahedron();
	void setX(float newX, int n);
	void setY(float newY, int n);
	void setZ(float newZ, int n);
	void setPoint(int n);
	float getX(int n);
	float getY(int n);
	float getZ(int n);
	void calculateVolume();
	float getVolume();
	friend void fillObjects(Tetrahedron* t, int n);
	friend int maxVolume(Tetrahedron* t, int n);

};
