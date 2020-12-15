
#include <stdio.h> 
#include <string.h>

char const NL = '\n';
char const NUL = '\0';  //  not to be confused with NULL

size_t const size = 6;
typedef struct rolls rolls;
struct rolls {
  int roll;
  char name[80];
};

int main(void) {
  rolls roll[size];

  for (size_t i = 0; i < size; i++) {
    printf("\nEnter your Roll number: ");
    fflush(stdout);
    scanf("%d", &roll[i].roll);
    //  remove any newlines left in the buffer after scanf
    int dc;
    while ((dc = getchar()) != '\n');

    printf("Enter your name: ");
    fflush(stdout);
    fgets(roll[i].name, sizeof(roll[i].name), stdin);

    //  remove unwanted newlines
    char * cp = roll[i].name;
    while ((cp = strchr(cp, NL)) != NULL) { *cp++ = NUL; }
  }
  putchar('\n');

  for (size_t i = 0; i < size; i++) {
    printf("%0zu: %3d %s\n", i, roll[i].roll, roll[i].name);
  }

  return 0;
}
