#include <iostream>

template <typename T>
inline T const& max(T const& a, T const& b)
{
		std::cout << "max<T>" << std::endl;
		return a < b ? b :a;
}
#ifdef BEFORE
inline int const& max(int const& a, int const& b)
{
		std::cout << "max(int const& a, int const& b)" << std::endl;
		return a < b ? b :a;
}
#endif

template <typename T>
inline void max(T const & a, T const& b, T const& c)
{
		max(max(a,b),c);
}

#ifndef BEFORE
inline int const& max(int const& a, int const& b)
{
		std::cout << "max(int const& a, int const& b)" << std::endl;
		return a < b ? b :a;
}
#endif

int main(void)
{
		int  a=1,b=2,c=3;
		max(1,2,3);
}
