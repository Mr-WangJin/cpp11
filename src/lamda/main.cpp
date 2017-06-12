#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>


void testFunction(std::function<int(int)> func2) {
	std::cout << std::endl << __func__ << std::endl;

	std::cout << "func2: " << func2(6) << '\n';
}


double my_divide(double x, double y) { return x / y; }

struct MyPair {
	double a, b;
	double multiply() { return a*b; }
};

void testBind() {
	std::cout << std::endl << __func__ << std::endl;
	using namespace std::placeholders;    

	auto fn_five = std::bind(my_divide, 10, 2);               // returns 10/2
	std::cout << fn_five() << '\n';                          // 5

	auto fn_half = std::bind(my_divide, _1, 2);               // returns x/2
	std::cout << fn_half(10) << '\n';                        // 5

	auto fn_invert = std::bind(my_divide, _2, _1);            // returns y/x
	std::cout << fn_invert(10, 2) << '\n';                    // 0.2

	MyPair ten_two{ 10,2 };

	// binding members:
	auto bound_member_fn = std::bind(&MyPair::multiply, _1); // returns x.multiply()
	std::cout << bound_member_fn(ten_two) << '\n';           // 20

	auto bound_member_data = std::bind(&MyPair::a, ten_two); // returns ten_two.a
	std::cout << bound_member_data() << '\n';                // 10
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