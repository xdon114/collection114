#ifndef REQEXPR__MTOOL_H
#define REQEXPR__MTOOL_H
#include "reqexpr.hpp"

#define REQEXPR(...) ::reqexpr::void_t<__VA_ARGS__>

// in REQexpr, reqiure type to be valid. returns type.
#define REQ_T(type) type

// in REQexpr, reqiure expr to be valid. returns decltype(expr).
// expr is unevaled.
#define REQ_E(expr) decltype(expr)

// in REQexpr, reqiure decltype(expr) to be valid to /*  */req.
// expr is unevaled.
#define REQ_R(expr, req) req<REQ_E(expr)>
/*
template<...> using XXX = REQEXPR(..., ..., ......);
*/

#define SATISFY_REQ_T(req, ...) ::reqexpr::satisfy_req<req, __VA_ARGS__>
#define SATISFY_REQ(req, ...) SATISFY_REQ_T(req, __VA_ARGS__)::value
#define CONCEPT(name, req, ...) constexpr bool name = SATISFY_REQ(req, __VA_ARGS__) // ;

#endif