//str.h
#ifndef __STR__H__
#define __STR__H__
typedef struct {
  char* pstr;
  int len;
} str;

void clean_str(str s);
str init_str(char* s, int len);
str init_str_with(str s);
str init_str_with_const(const char* s);
void print_str(str s);
str read_str();
#endif
