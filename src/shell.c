#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

static char current_username[64] = "user"; // Default username

void shell(){
  char buf[128];
  char cmd[64];
  char arg[2][64];
  buf[0] = '\0'; // Initialize buffer to empty

  printString("Welcome to EorzeOS!\r\n");
  while (true) {
    printString(current_username); 
    printString("> "); 
    readString(buf); 

    parseCommand(buf, cmd, arg); // parse the inputs

    if(buf[0] != '\0') { // if buffer is not empty
      
      // if the command is "user"
      if(strcmp(cmd, "user") == 0) { 
        
        // if the user didn't input a new username
        if (arg[0][0] == '\0') { 
          strcpy(current_username, "user"); 
        }

        // if the user did input a username
        else { 
          strcpy(current_username, arg[0]);
        }

        // by default to be printed after the above operations
        printString("Username changed to ");
        printString(current_username);
        printString("\r\n");
      }

      // if the command is yo
      else if (strcmp(cmd, "yo") == 0) {
        printString("gurt\r\n");
      }

      // if the command is "gurt"
      else if (strcmp(cmd, "gurt") == 0) {
        printString("yo\r\n");
      }

      // if the command is not registered 
      else {
        printString(buf); 
        printString("\r\n"); 
      }

    }

    else { // if the buffer is empty
      printString("\r\n");
    }

  }
}

void parseCommand(char *buf, char *cmd, char arg[2][64]) {
  int i = 0, 
      j = 0;

  cmd[0] = '\0'; // Initialize command to empty
  arg[0][0] = '\0'; // Initialize first argument to empty
  arg[1][0] = '\0'; // Initialize second argument to empty

  // copying the command 
  while (buf[i] != '\0' && buf[i] != ' ' && j < 63) {
    cmd[j] = buf[i]; // copy the first command
    i++; 
    j++;
  }
  cmd[i] = '\0'; // null terminate the command string

  while (buf[i] == ' ') i++; // skip spaces

  // copying the first arguments
  j = 0;
  while (buf[i] != '\0' && buf[i] != ' ' && j < 63) {
    arg[0][j] = buf[i]; // copy the first argument
    i++; 
    j++;
  }
  arg[0][j] = '\0'; // null terminate the first argument string
 
  while (buf[i] == ' ') i++; // skip spaces

  // copying the second arguments
  j = 0;
  while (buf[i] != '\0' && buf[i] != ' ' && j < 63) {
    arg[1][j] = buf[i]; // copy the second argument
    i++; 
    j++;
  }
  arg[1][j] = '\0'; // null terminate the second argument string

  while (buf[i] == ' ') i++; // skip spaces
}
