//
//  main.c
//  jour05
//
//  Created by francois de pompignan on 16/02/2021.
//

#include <unistd.h>
#include <stdlib.h>
#include<stdio.h>



int ft_putchar(char c)
{
    write (1,&c,1);
    return 0;
}
//-----------------------------------------------------
void ft_putstr(char *str)
{
    int i =0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
    ft_putchar('\n');
}
//----------------------------------------------------
void ft_putnbr(int nb)
{
    int x =0 , y=0 , z=0, a=0, b=0, xr=0, yr=0,zr=0,ar=0,br =0;
    
    for (x=0;x<10;x++)
    {
        for (y=0;y<10;y++)
        {
            for (z=0;z<10;z++)
            {
                for (a=0;a<10;a++)
                {
                    for (b=0;b<10;b++)
                    {
                        if (nb == (10000*x + 1000*y + 100*z + 10*a + b))
                        {
                            xr = x;
                            yr = y;
                            zr = z;
                            ar = a;
                            br = b;
                        }
                    }
                }
            }
        }
    }
    ft_putchar(xr+48);
    ft_putchar(yr+48);
    ft_putchar(zr+48);
    ft_putchar(ar+48);
    ft_putchar(br+48);
    ft_putchar('\n');
}
//------------------------------------------
int ft_atoi(char *str)
{
    int x =str[0] , y=str[1] , z=str[2], a=str[3], b=str[4];
    int result =0;
    
    
    result = 10000*(x-48) + 1000*(y-48) + 100*(z-48) +10*(a-48) + (b-48);
    
    return  result;
}
//--------------------------------------------
char *ft_strcpy(char *dest,char *src)
{
    int i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return  dest;;
}
//-----------------------------------------------
int ft_strlen(char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}
//--------------------------------------------

char *ft_strstr(char *str, char *to_find)
{
    
    int longueurKey = ft_strlen(to_find);
    int longueurString = ft_strlen(str);
    char newstr[longueurString];
    int i = 0;
    int j =0;
    int count = 0;
    int debut = -1;
    int k = 0;
    for (i=0; i<=longueurString;i++)
    {
        for (j=0;j<=longueurKey;j++)
        {
            if (str[i+j] == to_find[j])
            {
                count++;
            }
        }
        if (count == longueurKey)
        {
            debut = i + longueurKey;
            count = 0;
            printf("%d\n",debut);
        }else
            count = 0;
    }
    
    
    if (debut != -1)
    {
        for (k=0;k<longueurString;k++)
        {
            newstr[k] = str[debut + k];
        }
        return newstr;
        
    } else
    return NULL;
}
//--------------------------------------------------
int ft_strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' && (*s1 == *s2)) {s1++; s2++;}
    return (s1==s2) ? 0 : (*(unsigned char *)s1 - *(unsigned char *)s2);
}
//---------------------------------------------------
int ft_strncmp(char *s1,char *s2,unsigned int n)
{
    int count =1;
    {
        while (*s1 != '\0' && (*s1 == *s2) && count < n) {s1++; s2++;count++;}
        return (s1==s2) ? 0 : (*(unsigned char *)s1 - *(unsigned char *)s2);
    }
}
//-----------------------------------------------------
char *ft_strupcase(char *str)
{
    int count =0;
    while (*str != '\0')
    {
        *str = *str - 32;
        str++;
        count++;
    }
    
    
    return (str - count) ;
}
//---------------------------------------------------
char *ft_strlowcase(char *str)
{
    int count =0;
    while (*str != '\0')
    {
        if (*str <= 90 && *str>=65 )
        *str = *str + 32;
        str++;
        count++;
    }
    
    
    return (str - count) ;
}
//----------------------------------------------------
char *ft_strcapitalized(char *str)
{
    int count =0;
    str[0]=str[0] - 32;
    
    while ( *str != '\0')
    {
        if (*str  == ' ')
        {
            if (*(str+1) <= 122 && *(str+1)>=97 )
            {
                *(str+1)=*(str+1) - 32;
            }
        }
        str++;
        count++;
    }
    return (str-count);
}
//-------------------------------------------------------
int ft_str_is_alpha(char *str)
{
    int result =2;
    int ret = 1;
    if (str == NULL)
        return ret;
    while ( *str != '\0')
    {
        if ((*str <=122 && *str>=97) || (*str<=90 && *str>=65) )
            result =1;
        else
            result = 0;
        if (result == 0)
            ret =0;
        str++;
    }
    return ret;
}
//---------------------------------------------------
int ft_str_is_numeric(char *str)
{
    int result =2;
    int ret = 1;
    if (str == NULL)
        return ret;
    while ( *str != '\0')
    {
        if ((*str <=57 && *str>=48)  )
            result =1;
        else
            result = 0;
        if (result == 0)
            ret =0;
        str++;
    }
    return ret;
}
//-------------------------------------------------
int ft_str_is_lowercase(char *str)
{
    int result =2;
    int ret = 1;
    if (str == NULL)
        return ret;
    while ( *str != '\0')
    {
        if ((*str <=122 && *str>=97)  )
            result =1;
        else
            result = 0;
        if (result == 0)
            ret =0;
        str++;
    }
    return ret;
}
//----------------------------------------
int ft_str_is_uppercase(char *str)
{
    int result =2;
    int ret = 1;
    if (str == NULL)
        return ret;
    while ( *str != '\0')
    {
        if ((*str <=90 && *str>=65)  )
            result =1;
        else
            result = 0;
        if (result == 0)
            ret =0;
        str++;
    }
    return ret;
}
//-----------------------------------------
char *ft_strcat(char *dest,char *src)
{
    int fin =0;
    while (*dest !='\0')
    {
        fin++;
        dest++;
    }
    printf("%d\n",fin);
    
    while (*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    dest[fin +1] ='\0';
    printf("%d\n",fin);
    
    return dest;
}
//--------------------------------------------
char *ft_strncat(char *dest,char *src, int nb)
{
    int count =0;
    while (*dest !='\0' && count<nb)
    {
        count++;
        dest++;
    }
    printf("%d\n",count);
    
    while (*src != '\0' && count<nb)
    {
        *dest = *src;
        src++;
        dest++;
        count++;
    }
    dest[count +1] ='\0';
    printf("%d\n",count);
    
    return dest;
}




int main(int argc, const char * argv[]) {
    
    
    
    
    
    
   
    
    
    return 0;
}
