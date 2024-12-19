#include <vector>
#include <array>
#include <iostream>
#include <ostream>

/*
Difficultés :
    - Avoir une seule fonction Trier au lieu de faire du overloading et d'en avoir 3 pour gérer les cas possible
    - choix du pivot, dans une parmière version j'ai choisit le dernier éléments. Mais cela peut etre contre productif si le tableau est deja presque bien trier
        --> utilisation 
    - utilisation de std::swap au lieu d'avoir une méthode "échanger" que j'avais codé à la main
*/
class Trieur {
public:
   // Fonction qui échange deux éléments d'un tableau, template pour gérer les différents type
//    template<typename T>
//    void echanger(T& a, T& b) {
//        T temp = a;     // On stocke temporairement la valeur de a
//        a = b;          // On met b dans a
//        b = temp;       // On met l'ancienne valeur de a dans b
//    }

   // Cette fonction prend le dernier élément comme pivot
   // et met tous les éléments plus petits à gauche
   // et tous les éléments plus grands à droite
//    template<typename T>
//    int partitionner(T* tableau, int debut, int fin) {
//        T pivot = tableau[fin];  // On choisit le dernier élément comme pivot
//        int i = debut - 1;       // Index qui va repérer la position finale du pivot

//        // On parcourt tous les éléments sauf le pivot
//        for(int j = debut; j < fin; j++) {
//            // Si l'élément actuel est plus petit que le pivot
//            if(tableau[j] < pivot) {
//                i++;    // On avance l'index des éléments plus petits
//                echanger(tableau[i], tableau[j]);  // On met l'élément plus petit à gauche
//            }
//        }
//        // On place le pivot à sa position finale (entre les petits et grands éléments)
//        echanger(tableau[i + 1], tableau[fin]);
//        return i + 1;  // On retourne la position du pivot
//    }

    template <typename T>
    int choisirPivotMedian(T* tableau, int debut, int fin) {
        int milieu = (debut + fin) / 2;

        // Trouver la médiane entre tableau[debut], tableau[milieu], tableau[fin]
        if (tableau[debut] > tableau[milieu]) std::swap(tableau[debut], tableau[milieu]);
        if (tableau[debut] > tableau[fin]) std::swap(tableau[debut], tableau[fin]);
        if (tableau[milieu] > tableau[fin]) std::swap(tableau[milieu], tableau[fin]);

        // Maintenant, tableau[milieu] est la médiane
        std::swap(tableau[milieu], tableau[fin]); // Déplace la médiane à la fin
        return fin; // Retourne l'index du pivot (qui est maintenant à la fin)
    }


    template <typename T>
    int partitionner(T* tableau, int debut, int fin) {
        int pivotIndex = choisirPivotMedian(tableau, debut, fin);
        T pivot = tableau[pivotIndex]; // Le pivot est maintenant la médiane
        int i = debut - 1;

        for (int j = debut; j < fin; ++j) {
            if (tableau[j] < pivot) {
                ++i;
                std::swap(tableau[i], tableau[j]);
            }
        }
        std::swap(tableau[i + 1], tableau[fin]);
        return i + 1; // Position finale du pivot
    }

   // Fonction récursive principale du QuickSort
   template<typename T>
   void quickSort(T* tableau, int debut, int fin) {
       // On continue tant qu'il y a au moins 2 éléments à trier
       if(debut < fin) {
           // On trouve la position du pivot
           int pivot = partitionner(tableau, debut, fin);

           // On trie récursivement les deux parties :
           // - avant le pivot
           quickSort(tableau, debut, pivot - 1);
           // - après le pivot
           quickSort(tableau, pivot + 1, fin);
       }
   }


//    // Fonction pour trier un std::vector
//    template<typename T>
//    void trier(std::vector<T>& vec) {
//        if(!vec.empty()) {
//            quickSortRecursif(vec.data(), 0, vec.size() - 1);
//        }
//    }

//    // Fonction pour trier un tableau C classique
//    template<typename T>
//    void trier(T* tableau, int taille) {
//        if(taille > 0) {
//            quickSortRecursif(tableau, 0, taille - 1);
//        }
//    }

//    // Fonction pour trier un std::array
//    template<typename T, size_t N>
//    void trier(std::array<T, N>& arr) {
//        if(N > 0) {
//            quickSortRecursif(arr.data(), 0, N - 1);
//        }
//    }


    template<typename Container>
    void trier(Container& container) {
        auto taille = std::size(container);
        
        if(taille > 0) {
            auto ptr = std::data(container);
            quickSort(ptr, 0, taille - 1);
        }
    }
};





// Programme de test
int main() {
    Trieur trieur;

    // Test avec std::vector
    std::vector<double> vec = {64.5, 34.2, 25.1};
    std::cout << "Vector avant tri : ";
    for (const auto& v : vec) std::cout << v << " ";
    std::cout << std::endl;

    trieur.trier(vec);

    std::cout << "Vector après tri : ";
    for (const auto& v : vec) std::cout << v << " ";
    std::cout << std::endl;

    // Test avec tableau C
    int tab[] = {64, 34, 25};
    size_t tabSize = std::size(tab); // Taille du tableau
    std::cout << "Tableau C avant tri : ";
    for (size_t i = 0; i < tabSize; ++i) std::cout << tab[i] << " ";
    std::cout << std::endl;

    trieur.trier(tab);

    std::cout << "Tableau C après tri : ";
    for (size_t i = 0; i < tabSize; ++i) std::cout << tab[i] << " ";
    std::cout << std::endl;

    // Test avec std::array
    std::array<float, 3> arr = {64.5f, 34.2f, 25.1f};
    std::cout << "Array avant tri : ";
    for (const auto& a : arr) std::cout << a << " ";
    std::cout << std::endl;

    trieur.trier(arr);

    std::cout << "Array après tri : ";
    for (const auto& a : arr) std::cout << a << " ";
    std::cout << std::endl;


//    // Test avec vector
//    std::vector<double> vec = {64.5, 34.2, 25.1, 12.3, 22.4, 11.1, 90.0};
//    std::cout << "Vector avant tri: ";
//    for(const auto& val : vec) std::cout << val << " ";
//    std::cout << std::endl;
   
//    trieur.trier(vec);
   
//    std::cout << "Vector après tri: ";
//    for(const auto& val : vec) std::cout << val << " ";
//    std::cout << std::endl;

//    // Test avec tableau C
//    int tab[] = {64, 34, 25, 12, 22, 11, 90};
//    trieur.trier(tab, 7);

//    // Test avec std::array
//    std::array<float, 5> arr = {64.5f, 34.2f, 25.1f, 12.3f, 22.4f};
//    trieur.trier(arr);

   return 0;
}