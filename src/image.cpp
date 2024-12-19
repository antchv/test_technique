#include <vector>
#include <cstdint>
#include <stdexcept>
#include <memory>
#include <cstddef>

#include <cmath>
#include <iostream>



/*
Difficultés :
    - Comprendre comment gérer les différents type d'images --> template
    - Utilisation de unique_ptr pour une utilisation auto de la mémoire, pas besoin d'avoir un destructeur dans notre classe
    - Calcul correct de l'indice dans le tableau 1D pour simuler une matrice 2D
    - Interprétation de la consigne " mécanisme d'accès par ligne "  --> choisi de retourner un ptr vers la ligne concerné au lieu de faire une copie de la ligne entière
*/
template <typename Image_Type>
class VaoImage {
private:
    std::unique_ptr<Image_Type[]> data;  // Utilisation de unique_ptr pour la sécurité
    size_t width;
    size_t height;

public:
    VaoImage(size_t w, size_t h) 
        : width(w)      // Initialisation directe
        , height(h)     // Initialisation directe
        , data(std::make_unique<Image_Type[]>(w * h))  // Initialisation directe
    {}
    
    // Accès aux pixels
    const Image_Type& at_pixel(size_t x, size_t y) {
        // vérification des bornes que le pixel est bien dans l'image
        if (x >= width || y >= height) {
            throw std::out_of_range("Index hors limites");
        }

        return data[y * width + x];
    }

    // Nouvelle méthode pour l'écriture
    Image_Type& set_pixel(size_t x, size_t y) {
        if (x >= width || y >= height) {
            throw std::out_of_range("Index hors limites");
        }
        return data[y * width + x];
    }

    // Accès à une ligne
    Image_Type* getRow(size_t y) {
        return &data[y * width];
    }

    // Getters
    size_t getWidth() {
        return width;
    }

    size_t getHeight() {
        return height;
    }
};




int main() {

    // Création d'une image 100x100 avec des valeurs uint16_t
    VaoImage<uint16_t> img(100, 100);

    // Utilisation de set_pixel pour l'écriture
    for(size_t y = 0; y < img.getHeight(); ++y) {
        for(size_t x = 0; x < img.getWidth(); ++x) {
            img.set_pixel(x, y) = (x + y) % 256;
        }
    }

    // Calcul de la moyenne
    double sum = 0.0;
    size_t totalPixels = img.getWidth() * img.getHeight();
    
    for(size_t y = 0; y < img.getHeight(); ++y) {
        for(size_t x = 0; x < img.getWidth(); ++x) {
            sum += img.at_pixel(x, y);
        }
    }
    
    double mean = sum / totalPixels;

    // Calcul de l'écart-type
    double sumSquareDiff = 0.0;
    for(size_t y = 0; y < img.getHeight(); ++y) {
        for(size_t x = 0; x < img.getWidth(); ++x) {
            double diff = img.at_pixel(x, y) - mean;
            sumSquareDiff += diff * diff;
        }
    }
    
    double standardDeviation = std::sqrt(sumSquareDiff / totalPixels);

    // Affichage des résultats
    std::cout << "Moyenne: " << mean << std::endl;
    std::cout << "Écart-type: " << standardDeviation << std::endl;


    return 0;
}