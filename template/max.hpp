#ifndef MAX_HPP
#define MAX_HPP

template <typename T>
inline T const& max(T const& a, T const& b)
{
		return a < b ? b :a;
}
#endif
// vim:set shiftwidth=4 : 
