#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MAX = 100;

struct student
{
    char *name;
    int ID;
    int total;
    int rank;

} s1;

int main()
{

    struct student *ptr;

    int noOfStudents;

    int temp;

    printf("Entre number of records you want to store:");

    scanf("%d", &noOfStudents);

    char sname[MAX];

    float totals[noOfStudents];

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

        printf("Enter Total:");

        scanf("%d", &(ptr + i)->total);

        totals[i] = (ptr + i)->total;
    }

    // sorting the totals loop
    for (int i = 0; i < noOfStudents; i++)
    {
        for (int j = 0; j < noOfStudents - i - 1; j++)
        {
            if (totals[j] < totals[j + 1])
            {
                temp = totals[j + 1]; 
                totals[j + 1] = totals[j];
                totals[j] = temp;
            }
        }
    }   

    // remove duplicate totals from array 
    int num = noOfStudents;
    for(int i=0;i<num;i++){
      for(int j = i+1; j < num; j++){
         if(totals [i] == totals[j]){
            for(int k = j; k <num; k++){
               totals[k] = totals[k+1];
            }
            j--;
            num--;
         }
      }
   }

    // setting rank based on its total if same total exists same rank will be given
    for (int i=0; i< noOfStudents ; i++)
    {
           for (int j=0; j< noOfStudents ; j++) 
           {
                if ((totals[i]==(ptr+j)->total) && ( (ptr+j)->rank == 0))
                {
                    (ptr+j)->rank = i+1; // rank starts from 1 
                }
           }
    }


    // printing score board
    printf("\nStudent Board\n");
    printf("\nID\tName\tTotal\tRank");
    for (int i = 0; i < noOfStudents; i++)
    {
        
        printf("\n%d\t%s\t%d\t%d", (ptr + i)->ID, (ptr + i)->name, (ptr + i)->total, (ptr + i)->rank);

        printf("\n");
    }

    free(ptr);
}