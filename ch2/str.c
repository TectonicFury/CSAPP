#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "str.h"

str init_str(char* s, int len) {
  str st;
  char* p = (char*)malloc((len + 1) * sizeof(char));
  for (size_t i = 0; i < len; i++) {
    p[i] = s[i];
  }
  p[len] = '\0';
  st.pstr = p;
  st.len = len;
  return st;
}

str init_str_with(str s) {
  str st = init_str(s.pstr, s.len);
  return st;
}

str init_str_with_const(const char* s) {
  unsigned int l = strlen(s);
  char *p = (char*)malloc((l + 1));
  for (size_t i = 0; i < l; i++) {
    p[i] = s[i];
  }
  p[l] = '\0';
  str st = init_str(p, l);
  free(p);
  return st;
}

void clean_str(str s) {
  free(s.pstr);
}

void print_str(str s) {
  printf("%s\n", s.pstr);
}

str read_str() {
  int n = 1024;
  char *p = (char*)malloc(n);
  char *t;
  int len = 0;
  int c;
  for (; (c = getchar()) != '\n' && c != EOF ; len++) {
    if (len < n - 1) {
      p[len] = c;
    } else {

      t = (char*)malloc(2 * n);
      for (size_t i = 0; i < n; i++) {
        t[i] = p[i];
      }
      free(p);
      p = t;
      n = 2 * n;
    }
  }

  str s = init_str(p, len);
  free(p);
  return s;
}
