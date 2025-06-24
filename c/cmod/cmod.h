#ifndef CMOD__CMOD_H
#define CMOD__CMOD_H

#define _MINAME(mod)            _interface_##mod

#define Cm_I_BEGIN(mod)         extern struct _MINAME(mod) { //;
#define Cm_I_VAR(x, type)           type* const x //;
#define Cm_I_ARR(x, type)           type* const x //;
#define Cm_I_FUNC(x, ret, args)     ret (*const x) args //;
#define Cm_I_END(mod)               int _last_init; \
                                } mod //;

#define Cm_D_BEGIN(mod)         struct _MINAME(mod) mod = {
#define Cm_D_VAR(x)                 .x = &x,
#define Cm_D_ARR(x)                 .x = x,
#define Cm_D_FUNC(x)                .x = &x,
#define Cm_D_END(mod)               ._last_init = 0 \
                                } //;

#endif
