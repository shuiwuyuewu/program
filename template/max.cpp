#include <iostream>
#include <string>
#include "max.hpp"

int main(void)
{
		int i = 42;
		std::cout << "max(7,i) : " << max(7,i) << std::endl;

		double f1 = 3.4;
		double f2 = -6.7;
		std::cout << "max(f1,f2) : " << max(f1,f2) << std::endl;

		std::string s1 = "mathematics";
		std::string s2 = "math";
		//error std::cout << "max(s1,s2) : " << max(s1,s2) << std::endl;
		std::cout << "max(s1,s2) : " << ::max(s1,s2) << std::endl;
		//error max(4,4.7);
		std::cout << "max<double>(4,4.7) : " << max<double>(4,4.7) << std::endl;
}
