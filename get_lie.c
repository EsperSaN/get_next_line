#include "get_next_line.h"
#include <strings.h>

int  lie_lenght(char *box)
{
    int len;

    len = 0;

    while(*box)
    {
        len++;
        box++;
        if (*box == '\n')
            break;
    }
    return(len);
}

char    *move_to_another_lie(char *box)
{
    char    *new_lie;
    char    *tmp_lie;
    int     i;

    tmp_lie = box;
    i = 0;

    while(*tmp_lie)
    {
        tmp_lie++;
        if (*(tmp_lie - 1) == '\n')
            break;
    }

    new_lie = malloc(strlen(tmp_lie) + 1);
    if(!new_lie)
        return(NULL);

    while(tmp_lie[i])
    {
        new_lie[i] = tmp_lie[i];
        i++;
    }
    tmp_lie[i] = '\0'; 
    free (box);
    return (new_lie);
}

char    *get_lie(char *box)
{
    char    *result;
    int     i;
    
    i = 0;

    result = malloc(lie_lenght(box) + 1);
    if(!result)
        return(NULL);
    while (box[i])
    {
        result[i] = box[i];
        i++;
        if(box[i] == '\n')
            break;
    }
    result[i] = '\0';
    return (result);
}

int main()
{
    char *test = "Hello Imeiei \n from bkk 27399 \n 123141512";
    char *result;
    char *tmp_test;

    tmp_test = strdup(test);

    printf("%s\n",tmp_test);
    result = get_lie(tmp_test);
    printf("%s\n",result);
    free(result);

    tmp_test = move_to_another_lie(tmp_test);   
    
    printf("after \n%s",tmp_test);
    result = get_lie(tmp_test);
    printf("\n%s",result);
    free(result);
    free(tmp_test);
}