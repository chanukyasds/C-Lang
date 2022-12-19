#include<stdlib.h>

char *dstr_read(char *msg)

{

    char *str;


    char buf[100]; /*buffer*/

    printf("%s", msg);

    scanf("%s", buf); /*read string in buffer*/

    str = (char*) malloc(strlen(buf) + 1);

    if (str == NULL) {

       printf("Error: out of memory …\n");

       exit(1);

    }
       strcpy(str, buf);

       return str;
}

int main ()

{

   char *fname, *lname;

   printf("Enter your name:\n");

   fname = dstr_read("First name : ");

   lname = dstr_read("Last name : ");

   printf("Hi, %s %s\n", fname, lname);

   free(fname);

   free (lname);

   return 0;

}