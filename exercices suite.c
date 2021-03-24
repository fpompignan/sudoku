//
//  main.c
//  jour07
//
//  Created by francois de pompignan on 24/02/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LEN 50

int ft_putchar(char c)
{
    write (1,&c,1);
    return 0;
}
//-------------------------------------------------


char *ft_strdup(char *src)
{
    char *copy;
    int i = 0;
    long size = 0;
    size = strlen(src);
    
  
    
    
    
    if (LEN < size)
        return NULL;
    else {
        copy = malloc(sizeof(char)*LEN);
        for (i=0;i<= size;i++)
        {
            copy[i]=src[i];
        }
        copy[i+1] ='\0';
        
        return copy;
        
    }
}
//-------------------------------------------------------
int *ft_range(int min, int max)
{
    
    if (min >= max)
        return NULL;
    else{
        int *range;
        int i =0;
        range = malloc(sizeof(int)*(max+2 - min ));
        for ( i=0;i<=(max-min);i++)
        {
            range[i]=min + i;
        }
        return range;
    }
}
//----------------------------------------------------------
/*char **ft_split_whitespaces(char *str)
{
    
    char array[20][20];
    int i = 0;
    int j =0;
    
    
    while (*str !='\0')
    {
        while (*str != ' ' && *str != '\0')
        {
            array[j][i] = *str;
            str++;
            i++;
        }
        i = 0;
        j++;
        str++;

    }
    return array;
}*/

//----------------------------------------------------------

//------------------------------------------------------------
int count_char(char *str)
{
    int count = 0;
    while (*str !='\0')
    {
        count++;
        str++;
    }
    return  count;
}
//------------------------------------------------------
char *retourneTableau()
{
    char *str = malloc(50 * sizeof(char));
    
    strcpy(str, "coucou");

    return str;
}
//--------------------------------------------------------
int        ft_nb_words(char *str)
{
    int i;
    int sym;
    int count;

    i = 0;
    sym = 0;
    count = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
        {
            i++;
            sym = 1;
        }
        if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
        {
            count += (sym == 1) ? 1 : 0;
            sym = 0;
            i++;
        }
    }
    return (count);
}

int        ft_ln_w(char *str, int i)
{
    int count;

    count = 0;
    while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
    {
        count++;
        i++;
    }
    return (count);
}
//----------------------------------------------
int count_word(char *str)
{
    int count = 0;
    if (str == NULL)
        return  0;
    while (*str !='\0')
    {
        while(*str !=' ' && *str !='\t' && *str !='\n' && *str !='\0')
        {
            str++;
        }
        count++;
        if (*str != '\0')
            str++;
        
    }
    return count;
   
}


char    **ft_split_whitespaces(char *str)
{
    char    **res;
    int        i;
    int        j;
    int        k;

    i = 0;
    j = 0;
    if ((res = malloc(sizeof(char*) * (ft_nb_words(str) + 1))) == NULL)
        return (NULL);
    while (str[i])
    {
        while ((str[i] == '\t' || str[i] == ' ' || str[i] == '\n') && str[i])
            i++;
        if (str[i])
        {
            k = 0;
            if ((res[j] = malloc(sizeof(char) * ft_ln_w(str, i) + 1)) == NULL)
                return (NULL);
            while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
                res[j][k++] = str[i++];
            res[j++][k] = '\0';
           
        }
    }
    res[j] = NULL;
    return (res);
}
//----------------------------------------
char **ft_split_espace(char *str)
{
    char **res;
    int lettres[count_word(str)];
    int count =0;
    int i = 0;
    int j = 0;
    int k = 0;
    int n = 0;
    char *strr = str;
    res =malloc(sizeof(char*)*count_word(str));
    if (res == NULL)
        return NULL;
    
    
    while (*str !='\0')
    {
        while(*str != ' ' && *str !='\0')
        {
            count++;
            str++;
        }
        lettres[k] = count;
        count = 0;
        k++;
        if (*str != '\0')
            str++;
       
    }
    lettres[k]=1;
    str=strr;
    
    while (n <= count_word(str))
    {
        res[n] = malloc(sizeof(char)*lettres[n]);
        if (res[n]== NULL)
            return NULL;
        n++;
    }

    
    while (*str !='\0')
    {
        while(*str != ' ' && *str !='\0')
        {
            res[i][j] = *str;
            j++;
            str++;
        }
        res[i][j]='\0';
        j=0;
        i++;
        if (*str != '\0')
        str++;
    }
    res[i][j]='\0';
        
    return res;
}
//-------------------------------------------
void ft_print_words_tables(char **tab)
{
    int count = 0;
    int i = 0;
    int j = 0;
    
    while (tab[count] != NULL)
        count++;
    
    while (i < count)
    {
        while ( tab[i][j] != '\0')
        {
            ft_putchar(tab[i][j]);
            j++;
        }
        ft_putchar('\n');
        j=0;
        i++;
    }
}
//------------------------------------------
char **ft_split(char *str,char *charset)
{
    char **tab;
    char *lettres;
    int count = 0;
    int i = 0;
    int k = 0;
    int j = 0;
    int mots = 0;
    int mot = 0;
    int n = 0;
    char *charset2 = charset;
    char *str2 = str;
    
    while (*charset != '\0')
    {
        count++;
        charset++;
    }
    charset = charset2;
    printf("%d\n",count);

    lettres = malloc(sizeof(char)*(count+1));
    if (lettres == NULL)
        return NULL;
    
    
    while (*charset != '\0')
    {
        lettres[i] = *charset;
        i++;
        charset++;
    }
    lettres[count]='\0';
    
    
    printf("%c\n",lettres[0]);
    printf("%c\n",lettres[1]);
    printf("%c\n",lettres[2]);
    
   
    while (k != 1)
    {
        for (j=0;j<count;j++)
        {
            if (*str == lettres[j])
                k = 1;
        }
        if (k == 1)
        {
            str++;
            mots++;
            if (*str != '\0')
                k = 0;
        } else
        {
            str++;
            if (*str == '\0')
                k = 1;
        }
    }
    k = 0;
    mot = mots + 1;
    printf("%d\n",mot);
    
    tab = malloc(sizeof(char*) * mot);
    if (tab == NULL)
        return NULL;
        
    str = str2;
    while (k != 1)
    {
        for (j=0;j<count;j++)
        {
            if (*str == lettres[j])
                k = 1;
        }
        if (k == 1)
        {
            str++;
            if (*str != '\0')
                k = 0;
        } else
        {
            
            str++;
            if (*str == '\0')
                k = 1;
        }
    }
        
    
   
    
    
    
    return NULL;
}




int main(int argc, const char * argv[]) {
    
    char *str = "comment tu nait";
    char *charset = "on";
    char **tab;
    
    ft_split(str, charset);
   
    
    
   
    
    

    
    free(tab);
    
    
   
    
    
   
    return 0;
}
