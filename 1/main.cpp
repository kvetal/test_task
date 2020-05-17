#include "shapes.h"
#include <iostream>


int main(){
	
	Circle c(5);
	std::cout << c.Area() << std::endl;

	Triangle *t = new Triangle(5,7,7);
	std::cout << t->Area() << '\n';
	return 0;
}
