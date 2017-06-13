#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>


void testFunction(std::function<int(int)> func2) {
	std::cout << std::endl << __func__ << std::endl;

	std::cout << "func2: " << func2(6) << '\n';
}


void getSum(double x, double y, double &sum) { sum = x + y; }

struct MyPair {
	double a, b;
	double multiply() { return a*b; }
};

void testBind() {
	std::cout << std::endl << __func__ << std::endl;
	using namespace std::placeholders;    

	double n1 = 10.0;
	double n2 = 2.0;
	double n3 = 0.0f;

	auto fn_five = std::bind(getSum, n1, n2, std::ref(n3));					// returns 10+2
	n1 = 12.0;				
	fn_five();
	std::cout << n3 << '\n';                          

	auto fn_half = std::bind(getSum, _1, 2, std::ref(n3));					// returns  _1+2
	fn_half(11);
	std::cout << n3 << '\n';                       

	auto fn_invert = std::bind(getSum, _2, _1, std::ref(n3));				// returns 2+10
	fn_invert(10, 2);
	std::cout << n3 << '\n';                    

	MyPair ten_two{ 10,2 };

	// binding members:
	auto bound_member_fn = std::bind(&MyPair::multiply, _1);				// returns x.multiply()
	std::cout<< bound_member_fn(ten_two) << '\n';							// 20

	auto bound_member_data = std::bind(&MyPair::a, ten_two);				// returns ten_two.a
	std::cout << bound_member_data() << '\n';								// 10
}

int main()
{
	std::vector<int> c{ 1,2,3,4,5,6,7 };
	int x = 5;
	c.erase(std::remove_if(c.begin(), c.end(), [x](int n) -> bool { return n < x; }), c.end());

	std::cout << "c: ";
	for (auto i : c) {
		std::cout << i << ' ';
	}
	std::cout << '\n';

	auto func1 = [](int i) { return i + 4; };
	std::cout << "func1: " << func1(6) << '\n';

	std::function<int(int)> func2 = [](int i) { 
		i = i + 4;
		return i;
	};
	testFunction(func2);


	testBind();

	system("pause");
}