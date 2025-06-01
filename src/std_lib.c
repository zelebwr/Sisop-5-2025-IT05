#include "std_lib.h"

int div(int a, int b)
{
  //TODO: Implementasi pembagian
  //NOTE: HARUS BISA ANGKA NEGATIF
}

int mod(int a, int b)
{
  //TODO: Implementasi modulus
}

int strcmp(char *str1, char *str2) {
  int i = 0; // initialize index

  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i]) {
      return (unsigned int)str1[i] - (unsigned int)str2[i]; // return difference if characters differ
    }
    i++;
  }
  return (unsigned int)str1[i] - (unsigned int)str2[i]; // return difference at the end of the strings, which is 0, meaning they are equal
}

void strcpy(char *dst, char *src)
{
  //TODO: Implementasi penyalinan string
}

void clear(byte *buf, unsigned int size)
{
  //TODO: Implementasi pembersihan buffer
}

void atoi(char *str, int *num)
{
  //TODO: Implementasi konversi string ke integer
  //NOTE: HARUS BISA ANGKA NEGATIF
}

void itoa(int num, char *str)
{
  //TODO: Implementasi konversi integer ke string
  //NOTE: HARUS BISA ANGKA NEGATIF
}