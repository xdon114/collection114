#include <type_traits>
#include <iostream>
#include "mtool.h"
template<class From, class To> using CastTo = REQEXPR(
    REQ_E(static_cast<To>(std::declval<From>()))
);
template<class From, class To> CONCEPT(CastToV, CastTo, From, To);
#include "mclean.h"
struct T1{};
struct T2{};
int main() {
    std::cout << CastToV<int, double> << std::endl; // should be 1
    std::cout << CastToV<T1, T2> << std::endl; // should be 0
    return 0;
}