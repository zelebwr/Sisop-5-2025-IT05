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
  int buffer_index = 0;
  char current_character;
  unsigned int bios_key_input_ax; // stores the result from interrupt 0x16
  unsigned int bios_teletype_ax; // prepares AX for interrupt 0x10
  int max_buffer_size = 127; // maximum size of the buffer for null terminator at buf[127]

  while (true) {
    bios_key_input_ax = interrupt(0x16, (0x00 << 8), 0, 0, 0); // call BIOS interrupt 0x16 to read a key
    current_character = (char)(bios_key_input_ax & 0xFF); // get the character from AX

    
  }

}

void clearScreen()
{
  //TODO: Implementasi fungsi untuk membersihkan layar
}