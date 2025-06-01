#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

void shell(){
  char buf[128];
  buf[0] = '\0'; // Initialize buffer to empty

  printString("Welcome to EorzeOS!\r\n");
  while (true) {
    if (buf[0] != '\0') { // if the buffer is not empty
      printString("User> ");
      
      if (strcmp(buf, "yo") == 0) printString("gurt");
      else if (strcmp(buf, "gurt" == 0)) printString("yo"); 
      else printString(buf);
      
      printString("\r\n");
    }

    printString("User> ");
    readString(buf);
    printString("\r\n");
  }
}

void parseCommand(char *buf, char *cmd, char arg[2][64]) {
  //TODO: Implementasi fungsi untuk mem-parsing perintah
}

// Tambahkan fungsi bila perlu