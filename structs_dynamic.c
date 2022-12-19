#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MAX = 100;

struct student
{
    char *name;
    int ID;

} s1;

int main()
{

    struct student *ptr;

    int noOfStudents;

    printf("Entre number of records you want to store:");

    scanf("%d", &noOfStudents);

    char sname[MAX];

    ptr = (struct student *)malloc(noOfStudents * sizeof(struct student));

    for (int i = 0; i < noOfStudents; i++)
    {

        printf("\nEnter name of student:");

        scanf("%s", sname);

        int length = strlen(sname);

        (ptr + i)->name = (char *)malloc(strlen(sname) + 1);

        strcpy((ptr + i)->name, sname);

        printf("Enter ID:");

        scanf("%d", &(ptr + i)->ID);
    }

    printf("\nStudent Board\n");
    for (int i = 0; i < noOfStudents; i++)
    {
        printf("\n%d\t%s", (ptr + i)->ID, (ptr + i)->name);

        printf("\n");
    }

    free(ptr);
}