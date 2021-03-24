# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import random

grille={}


#initialisation de la grille
for i in range(0,10):
    for j in range(0,10):
        grille[(i,j)]=0

print (grille)

#définition du nombre de bateaux
nombreBateaux= int(input("veuille saisir le nombre de bateaux"))

print(nombreBateaux)
        
#positionnementaléatoire des  bateaux
for n in range (0,nombreBateaux):
    a=random.randint(0,10)
    b=random.randint(0,10)
    
    while grille[(a,b)]==1:
        a=random.randint(0,10)
        b=random.randint(0,10)
    
    grille[(a,b)]=1

print(grille)