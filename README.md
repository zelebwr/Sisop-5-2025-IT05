# Sisop-5-2025-IT05

## Kelompok IT05

Nama | NRP
--- | ---
Tasya Aulia Darmawan | 5027241009
Jonathan Zelig | 5027241047
Maritza Adelia S | 5027241111

## Laporan resmi

## Soal [Template]
### Overview
### Code block
```c
Template
```
### Explanation
bahdbshdbdfh

### Input/&Output
![halo/template.png](assets/soal_1/template.png)

## Soal 3
### Overview
The code will change the username to <username> when the user types 'user <username>'.
If no specific username is provided, only "user", the code will reset the username to the default user.

### Code block
#### shell.c
```c
static char current_username[64] = "user"; // Default username

else if(strcmp(cmd, "user") == 0) { 
  if (arg[0][0] == '\0') { // If no argument provided
    strcpy(current_username, "user"); // Reset to default
  }
  else { // If argument provided
    strcpy(current_username, arg[0]); // Update username
  }
  printString("Username changed to ");
  printString(current_username);
  printString("\r\n");
}
```
### Explanation
It compares the parsed cmd (first input of sentence) with "user". If it's true, and if the user types user (no argument), reset current_username to "user".
If the user types user <new_username>, copy <new_username> into current_username. It then prints a confirmation message.

### Input/&Output
![halo/template.png](assets/soal_1/template.png)

## Soal 6
### Overview
When the user types 'yogurt', the system will respond with a random part of the word or phrase each time. For instance, the first time the user types 'yogurt', it will return 'yo', the second time it will return 'ts unami gng </3', and the third time it will respond with 'sygau'. This process continues in a random selection of these responses.

### Code block
#### shell.c
```c
else if (strcmp(cmd, "yogurt") == 0) {
  unsigned int randomValue = getBiosTick();
  int remainder = mod(randomValue, 3);
  printString("\r");
  if (remainder == 0) {
    printString("\ryo\r\n");
  } else if (remainder == 1) {
    printString("\rts unami gng </3\r\n");
  } else {
    printString("\rsygau\r\n");
  }
}
```
### Explanation
It calls getBiosTick() to get a "random" system timer value, uses mod() to compute randomValue % 3, yielding 0, 1, or 2.
Prints a different response based on the remainder:
0 → "yo"
1 → "ts unami gng </3"
2 → "sygau"

### Input/&Output
![halo/template.png](assets/soal_1/template.png)
