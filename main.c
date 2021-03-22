//
//  main.c
//  colle1
//
//  Created by francois de pompignan on 18/03/2021.
//

#include <stdio.h>
#include <string.h>

typedef struct s_case
{
    int valeur;
    int nbre_candidats;
    int candidats[9];
} t_case;

void displaySudoku(char *LIGNE[9])
{
    int i = 0;
    int j = 0;
    
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
            printf("%c ",LIGNE[j][i]);
        }
        printf("| ");
        for(i=3;i<6;i++)
        {
            printf("%c ",LIGNE[j][i]);
        }
        printf("| ");
        for(i=6;i<9;i++)
        {
            printf("%c ",LIGNE[j][i]);
        }
        printf("\n");
    }
    for(i=0;i<22;i++)
    {
        printf("-");
    }
    printf("\n");

    for(j=3;j<6;j++)
    {
        for(i=0;i<3;i++)
        {
            printf("%c ",LIGNE[j][i]);
        }
        printf("| ");
        for(i=3;i<6;i++)
        {
            printf("%c ",LIGNE[j][i]);
        }
        printf("| ");
        for(i=6;i<9;i++)
        {
            printf("%c ",LIGNE[j][i]);
        }
        printf("\n");
    }
    for(i=0;i<22;i++)
    {
        printf("-");
    }
    printf("\n");
    for(j=6;j<9;j++)
    {
        for(i=0;i<3;i++)
        {
            printf("%c ",LIGNE[j][i]);
        }
        printf("| ");
        for(i=3;i<6;i++)
        {
            printf("%c ",LIGNE[j][i]);
        }
        printf("| ");
        for(i=6;i<9;i++)
        {
            printf("%c ",LIGNE[j][i]);
        }
        printf("\n");
    }
}
void displaysudoku(t_case grille[9][9])
{
    int i = 0;
    int j = 0;
    
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
            printf("%d ",grille[j][i].valeur);
        }
        printf("| ");
        for(i=3;i<6;i++)
        {
            printf("%d ",grille[j][i].valeur);
        }
        printf("| ");
        for(i=6;i<9;i++)
        {
            printf("%d ",grille[j][i].valeur);
        }
        printf("\n");
    }
    for(i=0;i<22;i++)
    {
        printf("-");
    }
    printf("\n");

    for(j=3;j<6;j++)
    {
        for(i=0;i<3;i++)
        {
            printf("%d ",grille[j][i].valeur);
        }
        printf("| ");
        for(i=3;i<6;i++)
        {
            printf("%d ",grille[j][i].valeur);
        }
        printf("| ");
        for(i=6;i<9;i++)
        {
            printf("%d ",grille[j][i].valeur);
        }
        printf("\n");
    }
    for(i=0;i<22;i++)
    {
        printf("-");
    }
    printf("\n");
    for(j=6;j<9;j++)
    {
        for(i=0;i<3;i++)
        {
            printf("%d ",grille[j][i].valeur);
        }
        printf("| ");
        for(i=3;i<6;i++)
        {
            printf("%d ",grille[j][i].valeur);
        }
        printf("| ");
        for(i=6;i<9;i++)
        {
            printf("%d ",grille[j][i].valeur);
        }
        printf("\n");
    }
    printf("\n--------------------------------------\n");
}




void initialisation_grille(t_case grille[9][9])
{
    int i = 0;
    int j = 0;
    int k = 0;
    
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(grille[i][j].valeur==0)
            {
                grille[i][j].nbre_candidats=9;
                for(k=0;k<9;k++)
                {
                    grille[i][j].candidats[k]=k+1;
                }
            }
            else
            {
                grille[i][j].nbre_candidats=0;
                for(k=0;k<9;k++)
                {
                    grille[i][j].candidats[k]=0;
                }
            }
                
        }
    }
}

void R_horizontale(t_case grille[9][9])
{
    int i=0;
    int j=0;
    int k=0;
    int n=0;
    int m=0;

    
    
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(grille[i][j].valeur==0)
            {
                for(k=0;k<9;k++)
                {
                    if(grille[i][k].valeur!=0)
                    {
                        for(n=0;n<9;n++)
                        {
                            if (grille[i][j].candidats[n] == grille[i][k].valeur)
                            {
                                grille[i][j].nbre_candidats--;
                                for(m=n;m<9;m++)
                                {
                                    grille[i][j].candidats[m]=grille[i][j].candidats[m+1];
                                }
                                grille[i][j].candidats[8]=0;
                                
                            }
                        }
                    }
                }
            }
        }
    }
}
void R_verticale(t_case grille[9][9])
{
    int i=0;
    int j=0;
    int k=0;
    int n=0;
    int m=0;
  
    
    
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(grille[i][j].valeur==0)
            {
                for(k=0;k<9;k++)
                {
                    if(grille[k][j].valeur!=0)
                    {
                        for(n=0;n<9;n++)
                        {
                            if (grille[i][j].candidats[n] == grille[k][j].valeur)
                            {
                                grille[i][j].nbre_candidats--;
                                for(m=n;m<9;m++)
                                {
                                    grille[i][j].candidats[m]=grille[i][j].candidats[m+1];
                                }
                                grille[i][j].candidats[8]=0;
                            }
                        }
                    }
                }
            }
        }
    }
}

void R_carre(t_case grille[9][9])
{
    int i =0;
    int j = 0;
    int m =0;
    int n =0;
    int p =0;
    int k = 0;
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(grille[i][j].valeur==0)
            {
                for(m=0;m<3;m++)
                {
                    for(p=0;p<3;p++)
                    {
                        if(grille[m][p].valeur != 0)
                        {
                            for(n=0;n<9;n++)
                            {
                                if (grille[i][j].candidats[n] == grille[m][p].valeur)
                                {
                                    grille[i][j].nbre_candidats--;
                                    for(k=n;k<9;k++)
                                    {
                                        grille[i][j].candidats[k]=grille[i][j].candidats[k+1];
                                    }
                                    grille[i][j].candidats[8]=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    for(i=3;i<6;i++)
    {
        for(j=0;j<3;j++)
        {
            if(grille[i][j].valeur==0)
            {
                for(m=3;m<6;m++)
                {
                    for(p=0;p<3;p++)
                    {
                        if(grille[m][p].valeur != 0)
                        {
                            for(n=0;n<9;n++)
                            {
                                if (grille[i][j].candidats[n] == grille[m][p].valeur)
                                {
                                    grille[i][j].nbre_candidats--;
                                    for(k=n;k<9;k++)
                                    {
                                        grille[i][j].candidats[k]=grille[i][j].candidats[k+1];
                                    }
                                    grille[i][j].candidats[8]=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=6;i<9;i++)
    {
        for(j=0;j<3;j++)
        {
            if(grille[i][j].valeur==0)
            {
                for(m=6;m<9;m++)
                {
                    for(p=0;p<3;p++)
                    {
                        if(grille[m][p].valeur != 0)
                        {
                            for(n=0;n<9;n++)
                            {
                                if (grille[i][j].candidats[n] == grille[m][p].valeur)
                                {
                                    grille[i][j].nbre_candidats--;
                                    for(k=n;k<9;k++)
                                    {
                                        grille[i][j].candidats[k]=grille[i][j].candidats[k+1];
                                    }
                                    grille[i][j].candidats[8]=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=3;j<6;j++)
        {
            if(grille[i][j].valeur==0)
            {
                for(m=0;m<3;m++)
                {
                    for(p=3;p<6;p++)
                    {
                        if(grille[m][p].valeur != 0)
                        {
                            for(n=0;n<9;n++)
                            {
                                if (grille[i][j].candidats[n] == grille[m][p].valeur)
                                {
                                    grille[i][j].nbre_candidats--;
                                    for(k=n;k<9;k++)
                                    {
                                        grille[i][j].candidats[k]=grille[i][j].candidats[k+1];
                                    }
                                    grille[i][j].candidats[8]=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=3;i<6;i++)
    {
        for(j=3;j<6;j++)
        {
            if(grille[i][j].valeur==0)
            {
                for(m=3;m<6;m++)
                {
                    for(p=3;p<6;p++)
                    {
                        if(grille[m][p].valeur != 0)
                        {
                            for(n=0;n<9;n++)
                            {
                                if (grille[i][j].candidats[n] == grille[m][p].valeur)
                                {
                                    grille[i][j].nbre_candidats--;
                                    for(k=n;k<9;k++)
                                    {
                                        grille[i][j].candidats[k]=grille[i][j].candidats[k+1];
                                    }
                                    grille[i][j].candidats[8]=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=6;i<9;i++)
    {
        for(j=3;j<6;j++)
        {
            if(grille[i][j].valeur==0)
            {
                for(m=6;m<9;m++)
                {
                    for(p=3;p<6;p++)
                    {
                        if(grille[m][p].valeur != 0)
                        {
                            for(n=0;n<9;n++)
                            {
                                if (grille[i][j].candidats[n] == grille[m][p].valeur)
                                {
                                    grille[i][j].nbre_candidats--;
                                    for(k=n;k<9;k++)
                                    {
                                        grille[i][j].candidats[k]=grille[i][j].candidats[k+1];
                                    }
                                    grille[i][j].candidats[8]=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=6;j<9;j++)
        {
            if(grille[i][j].valeur==0)
            {
                for(m=0;m<3;m++)
                {
                    for(p=6;p<9;p++)
                    {
                        if(grille[m][p].valeur != 0)
                        {
                            for(n=0;n<9;n++)
                            {
                                if (grille[i][j].candidats[n] == grille[m][p].valeur)
                                {
                                    grille[i][j].nbre_candidats--;
                                    for(k=n;k<9;k++)
                                    {
                                        grille[i][j].candidats[k]=grille[i][j].candidats[k+1];
                                    }
                                    grille[i][j].candidats[8]=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=3;i<6;i++)
    {
        for(j=6;j<9;j++)
        {
            if(grille[i][j].valeur==0)
            {
                for(m=3;m<6;m++)
                {
                    for(p=6;p<9;p++)
                    {
                        if(grille[m][p].valeur != 0)
                        {
                            for(n=0;n<9;n++)
                            {
                                if (grille[i][j].candidats[n] == grille[m][p].valeur)
                                {
                                    grille[i][j].nbre_candidats--;
                                    for(k=n;k<9;k++)
                                    {
                                        grille[i][j].candidats[k]=grille[i][j].candidats[k+1];
                                    }
                                    grille[i][j].candidats[8]=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=6;i<9;i++)
    {
        for(j=6;j<9;j++)
        {
            if(grille[i][j].valeur==0)
            {
                for(m=6;m<9;m++)
                {
                    for(p=6;p<9;p++)
                    {
                        if(grille[m][p].valeur != 0)
                        {
                            for(n=0;n<9;n++)
                            {
                                if (grille[i][j].candidats[n] == grille[m][p].valeur)
                                {
                                    grille[i][j].nbre_candidats--;
                                    for(k=n;k<9;k++)
                                    {
                                        grille[i][j].candidats[k]=grille[i][j].candidats[k+1];
                                    }
                                    grille[i][j].candidats[8]=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


void affichage_Nouvelle_valeur(t_case grille[9][9])
{
    int i=0;
    int j=0;
    
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(grille[i][j].nbre_candidats == 1)
            {
                grille[i][j].valeur = grille[i][j].candidats[0];
                grille[i][j].nbre_candidats=0;
            }
        }
    }
    displaysudoku(grille);
}

int compteur_case_occupee(t_case grille[9][9])
{
    int count = 0;
    int i =0;
    int j = 0;
    
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(grille[i][j].nbre_candidats==0)
                count++;
        }
    }
    return count;
}



int main(int argc, const char * argv[]) {
    
    char ligne0[]="9...7....";
    char ligne1[]="2...9..53";
    char ligne2[]=".6..124..";
    char ligne3[]="84...1.9.";
    char ligne4[]="5.....8..";
    char ligne5[]=".31..4...";
    char ligne6[]="..37..68.";
    char ligne7[]=".9..5.741";
    char ligne8[]="47.......";
    int i = 0;
    int j=0;
    int count = 0;
    
    char *LIGNE[9]={ligne0,ligne1,ligne2,ligne3,ligne4,ligne5,ligne6,ligne7,ligne8};
    
    displaySudoku(LIGNE);
    printf("\n");
   

    
    t_case grille[9][9];

    for (i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            grille[i][j].valeur=((int)(LIGNE[i][j])-48);
            if(grille[i][j].valeur==-2)
                grille[i][j].valeur=0;
        }
    }
    initialisation_grille(grille);
    
    while (count!=81)
    {
        R_horizontale(grille);
        R_verticale(grille);
        R_carre(grille);
        affichage_Nouvelle_valeur(grille);
        count = compteur_case_occupee(grille);
    }
    
   

  
    
    
    /*printf("nombre candidats grille[2,0]= %d\n",grille[2][0].nbre_candidats);
    for(i=0;i<9;i++)
    {
        printf("candidat[%d]:%d\n",i,grille[2][0].candidats[i]);
    }*/
  
    /*for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("nombre de candidats de grille[%d][%d] = %d\n",i,j,grille[i][j].nbre_candidats);
        }
    }*/
    
    
    return 0;
}
