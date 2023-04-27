#include "Tetrahedron.h"

void Vector::outputVector()
{
	cout << "vector: (" << this->x << ", " << this->y << ", " << this->z << ")" << endl;
}

void Vector::calculateVector(Point A, Point B)
{
	this->x = B.x - A.x;
	this->y = B.y - A.y;
	this->z = B.z - A.z;
}

void Vector::vectorProduct(Vector a, Vector b)
{
	this->x = a.y * b.z - a.z * b.y;
	this->y = a.z * b.x - a.x * b.z;
	this->z = a.x * b.y - a.y * b.x;
}

float scalarProduct(Vector a, Vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

Tetrahedron::Tetrahedron()
{
	point[0] = { 0, 0, 0 };
	point[1] = { 0, 0, 0 };
	point[2] = { 0, 0, 0 };
	point[3] = { 0, 0, 0 };
	volume = 0;
}

void Tetrahedron::setX(float newX, int n)
{
	point[n].x = newX;
}

void Tetrahedron::setY(float newY, int n)
{
	point[n].y = newY;
}

void Tetrahedron::setZ(float newZ, int n)
{
	point[n].z = newZ;
}

void Tetrahedron::setPoint(int n)
{
	float x_temp, y_temp, z_temp;
	cout << "Enter point " << n + 1 << " coordinates (in format 1 2 3): " << endl;
	cin >> x_temp; cin >> y_temp; cin >> z_temp;
	point[n].x = x_temp; point[n].y = y_temp; point[n].z = z_temp;
}

float Tetrahedron::getX(int n)
{
	return point[n].x;
}

float Tetrahedron::getY(int n)
{
	return point[n].y;
}

float Tetrahedron::getZ(int n)
{
	return point[n].z;
}

void Tetrahedron::calculateVolume()
{
	Vector vector[3];
	for (int i = 0; i < 3; i++)
	{
		vector[i].calculateVector(point[0], point[i + 1]);
	}

	Vector vector_product;
	vector_product.vectorProduct(vector[0], vector[1]);
	this->volume = fabs(scalarProduct(vector_product, vector[2])) / 6;
	cout << "Object's volume is " << volume << endl;
}

float Tetrahedron::getVolume() 
{ 
	return volume; 
}

void fillObjects(Tetrahedron* t, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Object " << i + 1 << ":" << endl;
		for (int j = 0; j < 4; j++) t[i].setPoint(j);
		t[i].calculateVolume();
		cout << "==============================================" << endl;
	}
}

int maxVolume(Tetrahedron* t, int n)
{
	float volume, max_volume = 0;
	int max_index = 0;
	for (int i = 0; i < n; i++)
	{
		volume = t[i].getVolume();

		if (i == 0 || volume > max_volume)
		{
			max_volume = volume;
			max_index = i;
		}
	}

	cout << "Max volume " << max_volume << " has the Object " << max_index + 1 << endl;
	return max_index;
}
