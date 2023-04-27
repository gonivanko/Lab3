#include "Tetrahedron.h"

// 7. Розробити клас "тетраедр", який заданий координатами своїх вершин в простоpi. 
// Створити масив об'єктів даного класу. 
// Визначити тетраедр з найбільшим об'ємом.

int main()
{
	int n, max_index;
	cout << "Hi! this is the program to calculate tetrahedrons value and find the max one of them." << endl;
	cout << "Enter number of Tetrahedron objects: "; cin >> n;

	Tetrahedron* t = new Tetrahedron[n];

	fillObjects(t, n);
	max_index = maxVolume(t, n);

	delete[] t;

}