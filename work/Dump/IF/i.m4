#ifdef __math__
#include <stdlib.h>
#include <math.h>

if_integer_type if_abs_function(if_integer_type p) {
    return abs(p);
}

if_real_type if_abs_function(if_real_type p) {
    return abs(p);
}

if_integer_type if_fix_function(if_real_type p) {
    return (int)(p);
}

if_real_type if_power_function(if_real_type p, if_real_type q) {
    return pow(p,q);
}

if_integer_type if_Shift_Left_function(if_integer_type p, if_integer_type q) {
    return p << q;
}

if_integer_type if_Shift_Right_function(if_integer_type p, if_integer_type q) {
    return p >> q;
}

if_integer_type if_ceil_function(if_real_type p) {
    return (int)ceil(p);
}

if_integer_type if_floor_function(if_real_type p) {
    return (int)floor(p);
}

if_real_type if_float_function(if_integer_type p) {
    return (if_real_type)p;
}

if_integer_type if_round_function(if_real_type p) {
    return (int)round(p);
}

if_real_type if_sin_function(if_real_type p) {
    return sin(p);
}

if_real_type if_cos_function(if_real_type p) {
    return cos(p);
}

if_real_type if_sqrt_function(if_real_type p) {
    return sqrt(p);
}

if_integer_type if_trunc_function(if_real_type p) {
    return (int)trunc(p);
}
#endif







































divert(-1)
# inlined from /usr/share/doc/m4/examples/quote.m4
# quote(args) - convert args to single-quoted string
define(`quote', `ifelse(`$#', `0', `', ``$*'')')
# dquote(args) - convert args to quoted list of quoted strings
define(`dquote', ``$@'')
# dquote_elt(args) - convert args to list of double-quoted strings
define(`dquote_elt', `ifelse(`$#', `0', `', `$#', `1', ```$1''',
                             ```$1'',$0(shift($@))')')

# inlined from /usr/share/doc/m4/examples/foreach2.m4
# foreach(x, (item_1, item_2, ..., item_n), stmt)
#   parenthesized list, improved version
define(`foreach', `pushdef(`$1')_$0(`$1',
  (dquote(dquote_elt$2)), `$3')popdef(`$1')')
define(`_arg1', `$1')
define(`_foreach', `ifelse(`$2', `(`')', `',
  `define(`$1', _arg1$2)$3`'$0(`$1', (dquote(shift$2)), `$3')')')

define(`m4_first',`$1')

define(`m4_enum_num_case', `
        case if_`'m4_first$1_constant: return m4_first(shift$1);')
define(`m4_enum_val_case', `
        case m4_first(shift$1): return if_`'m4_first$1_constant;')
define(`m4_enum_val',
`divert(1)
if_integer_type if_num_function(if_$1_type p) {
    switch (p) {foreach(`_m4c',(shift($@)), `m4_enum_num_case(_m4c)')
    }
    return 0;
}

if_$1_type if_val_$1_function(if_integer_type p) {
    switch (p) {foreach(`_m4c',(shift($@)), `m4_enum_val_case(_m4c)')
    }
    return if_`'m4_first$2`'_constant;
}

divert(-1)
')

divert(1)
#ifdef __enum_functions__
divert(-1)
include(dataview.if)
divert(1)
#endif
