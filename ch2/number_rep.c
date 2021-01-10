#include "str.h"
#include "number_rep.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

str hex_to_bin(str hex_s) {
  int hex_len = hex_s.len;
  int bin_len = 4 * hex_len;
  char* bin_str = (char*)malloc((bin_len + 1));
  char c;
  for (size_t i = 0; i < hex_len; i++) {

    c = hex_s.pstr[i];

    switch(c) {
      case '0':
        strncat(bin_str, "0000", 4);
        break;
      case '1':
        strncat(bin_str, "0001", 4);
        break;
      case '2':
        strncat(bin_str, "0010", 4);
        break;
      case '3':
        strncat(bin_str, "0011", 4);
        break;
      case '4':
        strncat(bin_str, "0100", 4);
        break;
      case '5':
        strncat(bin_str, "0101", 4);
        break;
      case '6':
        strncat(bin_str, "0110", 4);
        break;
      case '7':
        strncat(bin_str, "0111", 4);
        break;
      case '8':
        strcat(bin_str, "1000");
        break;
      case '9':
        strncat(bin_str, "1001", 4);
        break;
      case 'A':
      case 'a':
        strncat(bin_str, "1010", 4);
        break;
      case 'B':
      case 'b':
        strncat(bin_str, "1011", 4);
        break;
      case 'C':
      case 'c':
        strncat(bin_str, "1100", 4);
        break;
      case 'D':
      case 'd':
        strncat(bin_str, "1101", 4);
        break;
      case 'E':
      case 'e':
        strncat(bin_str, "1110", 4);
        break;
      case 'F':
      case 'f':
        strncat(bin_str, "1111", 4);
        break;
    }
  }

  str s = init_str(bin_str, bin_len);
  return s;
}

str bin_to_hex(str bin_s) {
  int bin_len = bin_s.len;
  int hex_len = bin_len/4;

  int x = 0;
  if ((bin_len%4) != 0) {
    hex_len += 1;
    x = 4 - (bin_len%4);
  }

  char *hex_p = (char*)malloc(hex_len + 1);
  char *bin_p = (char*)malloc(bin_len + x + 1);

  for (size_t i = 0; i < x; i++) {
    bin_p[i] = '0'; //padding with 0s
  }

  int bin_len_x = bin_len + x;
  for (size_t i = x; i <= bin_len_x; i++) {
    bin_p[i] = bin_s.pstr[i - x];
  }

  //("%s\n", bin_p);
  char *t = (char*)malloc(4 + 1);
  t[4] = '\0';

  for (size_t i = 0; i < bin_len_x; i += 4) {
    strncpy(t, bin_p + i, 4);

    if (strncmp(t, "0000", 4) == 0) {
      strncat(hex_p, "0", 1);
    } else if(strncmp(t, "0001", 4) == 0) {
      strncat(hex_p, "1", 1);
    } else if (strncmp(t, "0010", 4) == 0) {
      strncat(hex_p, "2", 1);
    } else if (strncmp(t, "0011", 4) == 0) {
      strncat(hex_p, "3", 1);
    } else if (strncmp(t, "0100", 4) == 0) {
      strncat(hex_p, "4", 1);
    } else if (strncmp(t, "0101", 4) == 0) {
      strncat(hex_p, "5", 1);
    } else if (strncmp(t, "0110", 4) == 0) {
      strncat(hex_p, "6", 1);
    } else if (strncmp(t, "0111", 4) == 0) {
      strncat(hex_p, "7", 1);
    } else if (strncmp(t, "1000", 4) == 0) {
      strncat(hex_p, "8", 1);
    } else if (strncmp(t, "1001", 4) == 0) {
      strncat(hex_p, "9", 1);
    } else if (strncmp(t, "1010", 4) == 0) {
      strncat(hex_p, "A", 1);
    } else if (strncmp(t, "1011", 4) == 0) {
      strncat(hex_p, "B", 1);
    } else if (strncmp(t, "1100", 4) == 0) {
      strncat(hex_p, "C", 1);
    } else if (strncmp(t, "1101", 4) == 0) {
      strncat(hex_p, "D", 1);
    } else if (strncmp(t, "1110", 4) == 0) {
      strncat(hex_p, "E", 4);
    } else if (strncmp(t, "1111", 4) == 0) {
      strncat(hex_p, "F", 1);
    }
  }

  str s = init_str(hex_p, hex_len);
  free(hex_p);
  free(t);
  free(bin_p);
  return s;
}
long long bin_to_dec(str bin_s) {
  int l = bin_s.len;
  long long d = 0;
  for (; l >= 1; l--) {
    d += (bin_s.pstr[bin_s.len - l] - 48) * pow(2, l - 1);
  }
  return d;
}
long long hex_to_dec(str hex_s) {
  str s = hex_to_bin(hex_s);
  return bin_to_dec(s);
}

str dec_to_bin(long long x) {
  long long q;
  int r;
  char st[1024];
  st[0] = '\0';
  int i = 0;
  q = 4000; //arbitrary
  while (x != 0) {
    st[i++] = x%2 + '0';
    x = x/2;
  }
  st[i] = '\0';
  char *p = (char*)malloc(i + 1);
  for (size_t j = 0; j < i; j++) {
    p[j] = st[i - j - 1];
  }
  p[i] = '\0';
  str bin_s = init_str(p, i);
  free(p);
  return bin_s;
}

str dec_to_hex(long long x) {
  str bin_s = dec_to_bin(x);
  return bin_to_hex(bin_s);
}
