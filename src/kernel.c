#include "shell.h"
#include "kernel.h"

int main() {
  clearScreen();
  shell();
}

void printString(char *str)
{
  int i = 0; 
  unsigned int AX; 
  char character_to_print; 

  while (str[i] != '\0') {
    character_to_print = str[i];
    AX = 0x0E << 8 | (unsigned char)character_to_print;
    // 0x0E for teletype output, 
    // "<< 8" to shift it to the high byte, 
    // "| (unsigned char)character_to_print" to set the low byte
    interrupt(0x10, AX, 0, 0, 0); // Call BIOS interrupt 0x10 to print character
    i++;
  }
}

void readString(char *buf)
{
  //TODO: Implementasi fungsi untuk membaca string
}

void clearScreen()
{
  //TODO: Implementasi fungsi untuk membersihkan layar
}