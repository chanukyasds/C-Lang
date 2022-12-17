#include <stdio.h>
#include <string.h>

struct subject
{
    char subject_name[10];
    int  marks;
};

struct student
{
    int student_id;
    char student_name[10];
    struct subject info[2]; 
};

int main()
{
    int i,j;
    struct student st[2];
    printf("Enter Records of 2 students");
    for (i = 0; i < 2; i++)
    {
        printf("\nEnter Rollno:");
        scanf("%d", &st[i].student_id);
        printf("\nEnter Name:");
        scanf("%s", &st[i].student_name);
        for (j=0;j<2;j++)
        {
            printf("enter subject name:");
            scanf("%s",&st[i].info[j].subject_name);
            printf("enter subject marks:");
            scanf("%d",&st[i].info[j].marks);
        }
        
    }
    printf("\nStudent Information List:");
    for (i = 0; i < 2; i++)
    {
        printf("\nRollno:%d, Name:%s", st[i].student_id, st[i].student_name);
        printf("\nmarks:\n");
        for (j=0;j<2;j++)
        {
            printf("subject:%s, marks:%d",st[i].info[j].subject_name,st[i].info[j].marks);
            printf("\n");
        }
    }
    return 0;
}