#include "shell.h"
#include "kernel.h"
#include "std_lib.h"

static char current_username[64] = "user"; // Default username

// 0 = none
// 1 = Maelstrom
// 2 = Twin Adder
// 3 = Immortal Flames
static int current_grand_company = 0; 

static void printUsername() {
  printString(current_username);
  if (current_grand_company == 0) {
    // do nothing if no grand company is set 
  } else if (current_grand_company == 1) {
    printString("@Storm");
  } else if (current_grand_company == 2) {
    printString("@Serpent");
  } else if (current_grand_company == 3) {
    printString("@Flame");
  }
  printString("> ");
}

void shell(){
  char buf[128];
  char cmd[64];
  char arg[2][64];
  buf[0] = '\0'; // initialize buffer to empty

  printString("Welcome to EorzeOS!\r\n");
  while (true) {
    // printString("User> ");
    printUsername(); // print the username and grand company
    readString(buf); // read input from the user
    printString("\r\n");

    parseCommand(buf, cmd, arg); // parse the inputs

    if(buf[0] != '\0') { // if buffer is not empty

       // if the command is "grandcompany"
       if(strcmp(cmd, "grandcompany") == 0) { 
        if (arg[0][0] == '\0') { // if there are no continued name after cmd
          printString("Please specify a grand company name. Please use 'maelstrom', 'twinadder', or 'immortalflames'.\r");
        }
        else if (strcmp(arg[0], "maelstrom") == 0) { // if the argument is "Maelstrom"
          // setTextColor(0x04); // set text color to red
          current_grand_company = 1; // set grand company to Maelstrom
          clearScreen(); // clear the screen
        }
        else if (strcmp(arg[0], "twinadder") == 0) { // if the argument is "Twin Adder"
          // setTextColor(0x06); // set text color to green
          current_grand_company = 2; // set grand company to Twin Adder
          clearScreen(); // clear the screen
        }
        else if (strcmp(arg[0], "immortalflames") == 0) { // if the argument is "Immortal Flames"
          // setTextColor(0x01); // set text color to yellow
          current_grand_company = 3; // set grand company to Immortal Flames
          clearScreen(); // clear the screen
        } else {
          printString("Unknown grand company name. Please use 'maelstrom', 'twinadder', or 'immortalflames'.\r\n");
        }
      }

      // if the command is "clear"
      else if (strcmp(cmd, "clear") == 0) { 
        current_grand_company = 0; // reset grand company
        clearScreen(); // clear the screen
      }

      // if the command is "user"
      else if(strcmp(cmd, "user") == 0) { 
        if (arg[0][0] == '\0') { // if the user didn't input a new username
          strcpy(current_username, "user"); 
        }
        else { // if the user did input a username
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
