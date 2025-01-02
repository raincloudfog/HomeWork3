#include "SimpleVector.h"



int main() {

	SimpleVector<int>* test = new SimpleVector<int>(4);

	test->push_back(5);
	test->push_back(7);
	test->push_back(2);
	test->push_back(3);

	test->capacity();

	test->SortData();

	test->capacity();

	cout << test->size() << endl;




	test->push_back(2);
	test->push_back(2);


	test->capacity();
	cout << test->size() << endl;

	//test->pop_back();
	delete test;



	return 0;
}