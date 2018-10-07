#include "List.h"
#include "Vector.h"
#include <iostream>

using namespace std;
using namespace pr;


template< template<typename> class Container, typename T>
void show_const (const Container<T> & vec) {
	std::cout << "const:" << std::endl;
	for(const auto & val : vec) {
		std::cout << val << " ";
	}
	std::cout << "\nfin show_const" << std::endl;
}


template< template<typename> class Container, typename T>
void show (Container<T> & vec) {
	std::cout << "avant:" << std::endl;
	for(auto & val : vec) {
		std::cout << val << " ";
		++val;
	}
	std::cout << "\napres:" << std::endl;
	show_const(vec);
	std::cout << "\nfin show" << std::endl;
}


template< template<typename> class Container, typename T>
int test (Container<T> & vec) {
	for(int i=0; i < 15 ; i++)
		vec.push_back(i);
	std::cout << vec << "\nsize : " << vec.size() <<std::endl;
	show_const(vec);
	show(vec);	
	cout << "fin test\n" << endl;
	return 0;
}

int main_t () {
	Vector<int> vec;
	test(vec);
	std::cout << vec[4] << std::endl;
	vec[4]++;
	std::cout << vec[4] << std::endl;
	List<int> list;
	test(list);
	return 0;
}
