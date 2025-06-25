#ifndef REQEXPR__REQEXPR_HPP
#define REQEXPR__REQEXPR_HPP
#include<type_traits>
namespace reqexpr
{
    using std::true_type;
    using std::false_type;
    using std::is_same;

    template<typename...> using void_t = void;

    // satisfy_req
    template<typename _Req, template<typename...> typename, typename...>
        struct _satisfy_req : false_type {};
    template<template<typename...> typename Fn, typename... Args>
        struct _satisfy_req<void_t<Fn<Args...>>, Fn, Args...> : true_type {};
    template<template<typename...> typename Fn, typename... Args>
        using satisfy_req = _satisfy_req<void_t<>, Fn, Args...>;

    // req_same
    template<class T, class U> struct req_same {
        static_assert(is_same<T, U>::value, "reqexpr::req_same failed.");
    };
} // namespace reqexpr


#endif