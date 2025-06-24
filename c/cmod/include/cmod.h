#ifndef CMOD__CMOD_H
#define CMOD__CMOD_H

#define _MINAME(mod)            _interface_##mod

#define Cm_DECL(mod, decls)         extern struct _MINAME(mod) {decls} mod 
#define Cm_I_VAR(x, type)           type  *const x;
#define Cm_I_ARR(x, type)           type (*const x) [];
#define Cm_I_FUNC(x, ret, args)     ret  (*const x) args;

#define Cm_DEF(mod, ...)            struct _MINAME(mod) mod = {__VA_ARGS__}
#define Cm_D(x)                     .x = &x

#endif
