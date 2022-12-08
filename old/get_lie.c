#include "get_next_line.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j_str;
	char	*str_joined;

	if (!s1 || !s2)
		return (0);
	j_str = malloc((strlen(s1) + strlen(s2)) + 1);
	if (!j_str)
		return (0);
	str_joined = j_str;
	while (*s1)
	{
		*j_str = *s1;
		s1++;
		j_str++;
	}
	while (*s2)
	{
		*j_str = *s2;
		s2++;
		j_str++;
	}
	*j_str = '\0';
	return (str_joined);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = strlen(src);
	if (dstsize != 0)
	{
		dstsize = dstsize - 1;
		while (dstsize && *src)
		{
			*dst = *src;
			dst++;
			src++;
			dstsize--;
		}
		*dst = '\0';
	}
	return (srclen);
}

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

char    *get_next_line(int fd)
{
    static  char    *box;
    char    *new_box;
    char    *tmp;

    if(!box)
    {
        box = malloc(BUFFER_SIZE);
        if(!box)
            return (NULL);
    }
    while (0 < read(fd, box, BUFFER_SIZE))
    {
        if(1)//find_line_or_end(box))
        {
            tmp = box;
            box = move_to_another_lie(box);
            return(get_lie(tmp));
        }
        else
        {
            new_box = malloc(BUFFER_SIZE);
            if (!new_box)
                return (NULL);
            read(fd, new_box, BUFFER_SIZE);
            //box_join(box, new_box);
            free(new_box);
        }
    }
    return (NULL);
}

/*int main()
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
}*/

/*int main()
{   
    int i = 1;
    int iplus = 0;
    char buffer[700];
    size_t iiplus;
    int buffersize = 5;
    int fd = open("file1", O_RDONLY);
    
    while (i > 0)
    {
        iiplus = buffer + iplus;
        i = read(fd, iiplus, buffersize);
        iplus = iplus + i;
         if (i <= 0)
            break; 
        printf("int is = %d \n str is = \n%s\n iplus is = %d", i, buffer, iplus);    
    }
    printf("if end\n");
    
    printf("close");
    return(0);
}*/ //THIS WORK!!!!!!!! v 1

/*int main() NOTWORK
{
    char    *tmp_buf;
    char    *buffer;
    int     buffersize = 5;
    int     read_count = 0;
    size_t  bufinserted = 0;
    size_t  len;
    size_t  index_to_insert;
    int     fd = open("file1", O_RDONLY);

    if(!buffer)
    {
        buffer = malloc(buffersize + 1);
        if(!buffer)
            return(0);
        buffer[buffersize] = '\0';
        read(fd, buffer, 5);
    }
    //printf("%s",buffer);
    while(read_count >= 0)
    {
        tmp_buf = malloc(bufinserted + buffersize + 1);
        tmp_buf[bufinserted + buffersize] = '\0';
        memcpy(tmp_buf, buffer, bufinserted);
        
        //free(buffer);
        buffer = tmp_buf;
        index_to_insert = buffer + bufinserted;
        read_count = read(fd, ((char *)index_to_insert), buffersize);
        bufinserted = bufinserted + read_count;
        if(read_count <= 0)
            break;
        printf("int is = %d \n str is = \n%s\n iplus is = %d\n", read_count, buffer, bufinserted);
    
    }    
}*/
int main()
{
    int fd = open("file1", O_RDONLY);
    static  char    *memmory;
    int buffersize = 5;
    size_t  to_insert;
    char    *tmp;
    int     can_read;

    if(!memmory)
    {
        memmory = malloc(buffersize + 1);
        if(!memmory)
            return(0);
        memmory[buffersize] = '\0';
    }
    can_read = read(fd, memmory, buffersize);
    if(can_read > 0)
        printf("Start now!!! with  = %s\n",memmory);
    while(can_read > 0)
    {
        write(1, memmory,10);
        break;

    }
    printf("I can not read!!!");
    return(0);

}   