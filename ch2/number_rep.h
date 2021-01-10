//number_rep.h
#ifndef __NUMBER__REP__H__
#define __NUMBER__REP__H__
#include "str.h"

str hex_to_bin(str hex_s);
str bin_to_hex(str bin_s);
long long hex_to_dec(str hex_s);
long long bin_to_dec(str bin_s);
str dec_to_bin(long long x);
str dec_to_hex(long long x);
#endif
