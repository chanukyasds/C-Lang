#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    char *name;
    int ID;
    int social;
    int science;
    int total_marks;
    float percent;
    char grade[2];
}s1;

int main() {

   struct student *ptr;

   int noOfStudents;
    printf("Entre number of records you want to store:");
    scanf("%d",&noOfStudents);

    ptr = (struct student *) malloc(noOfStudents * sizeof(struct student));

    ptr->name = (char*)malloc(sizeof(char)*256);

    for (int i=0; i<noOfStudents;i++)
    {
        printf("\nEnter name of student:");
        scanf("%s",  &(ptr + i)->name);
        printf("Enter ID:");
        scanf("%d",&(ptr + i) -> ID);
        printf("Enter the Social Marks:");
        scanf("%d", &ptr->social);
        printf("Enter the Science Marks:");
        scanf("%d", &ptr->science);
        ptr->total_marks = (ptr->social + ptr->science);
        ptr->percent = ((float) ptr->total_marks / 200) * 100;
        if (ptr->percent>=95) strcpy(ptr->grade,"A+"); else if (ptr->percent>90) strcpy(ptr->grade,"A");else if (ptr->percent>85)strcpy(ptr->grade,"B+");else if (ptr->percent>80) strcpy(ptr->grade,"B");
        else if (ptr->percent>75)strcpy(ptr->grade,"C+"); else if (ptr->percent>70)strcpy(ptr->grade,"C"); else if (ptr->percent>65)strcpy(ptr->grade,"D+"); else if (ptr->percent>60)strcpy(ptr->grade,"D");
        else if (ptr->percent>35)strcpy(ptr->grade,"Pass"); else strcpy(ptr->grade,"Fail");
        printf("\nTotal Marks: %d",ptr->total_marks);
        printf("\nGrade: %s",ptr->grade);


    }
    for (int i=0; i<noOfStudents;i++)
    {
        printf("\n%d\t%s\t%s",(ptr+i)->ID, (ptr+i)->name, (ptr+i)->grade);
    }
    free(ptr);

   return 0;
}