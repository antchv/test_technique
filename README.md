# Projet C++ pour entretien technique

## partie 1
Difficultés :  
    - Comprendre le pattern de la matrice de Bayer  
    - Ne pas oublier la conversion uint8 --> uint16  
    - Bien comprendre ce que font les API fournies  


## partie 2
Difficultés :  
    - Comprendre les "attentes classiques du telle classe" --> gestion de la mémoire, noms explicites, gestion des execptions  
    - Comprendre comment gérer les différents type d'images --> template  
    - Utilisation de unique_ptr pour une utilisation auto de la mémoire, pas besoin d'avoir un destructeur dans notre classe  
    - choix d'un ptr car taille connu à l'avance et a priori ne va pas changer dans la durée de vie de l'objet, taille = 3096*2080  
    - Calcul correct de l'indice dans le tableau 1D pour simuler une matrice 2D  
    - Interprétation de la consigne " mécanisme d'accès par ligne "  --> choisi de retourner un ptr vers la ligne concerné au lieu de faire une copie de la ligne entière  


## partie 3
Difficultés :  
    - Avoir une seule fonction Trier au lieu de faire du overloading et d'en avoir 3 pour gérer les cas possible  
    - choix du pivot, dans une parmière version j'ai choisit le dernier éléments. Mais cela peut etre contre productif si le tableau est deja presque bien trier
        --> utilisation  
    - utilisation de std::swap au lieu d'avoir une méthode "échanger" que j'avais codé à la main  


## Lancer les codes
mkdir build  
cd build  
cmake ..  
make  

les exécutables seront dans le dossier build : TestTechnique_couleur, TestTechnique_image, TestTechnique_sort