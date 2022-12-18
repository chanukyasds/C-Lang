#include <stdio.h>
#include <string.h>
int MAX =100;
int main()
{
    char *str;
    char *str2;
    str=(char*)malloc(MAX*sizeof(char));
    printf("Enter value:");
    scanf("%s",str);
    str2=str;
    int len;
    len = strlen(str2);
    printf("%d",len);
    return 0;
}
