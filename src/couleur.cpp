#include <vector>
#include <cstdint>
#include <stdexcept>
#include <memory>
#include <cstddef>

#include <cmath>
#include <iostream>



/*
Difficultés :
    - Comprendre le pattern de la matrice de Bayer
    - Ne pas oublier la conversion uint8 --> uint16
    - Bien comprendre ce que font les API fournies
*/

// std::vector<uint16_t> extractBlueLayer() {
//     // Obtention de la taille du buffer en octets
//     uint32_t bufferSize;
//     if(GetImagingBufferSize(&bufferSize) != 0) {
//         throw std::runtime_error("Failed to get buffer size");
//     }

//     // Création d'un buffer temporaire pour stocker l'image brute
//     std::vector<uint8_t> rawBuffer(bufferSize);
//     if(GetImagingData(rawBuffer.data(), bufferSize) != 0) {
//         throw std::runtime_error("Failed to get image data");
//     }

//     // Conversion du buffer uint8_t* en uint16_t*
//     const uint16_t* imageData = reinterpret_cast<const uint16_t*>(rawBuffer.data());
    
//     // Définition des dimensions
//     // constexpr car on connait les valeurs à la compilation, sera calculé au compile time
//     constexpr size_t fullWidth = 3096;
//     constexpr size_t fullHeight = 2080;
//     constexpr size_t blueWidth = fullWidth / 2; // car un pixel sur 2 est B
//     constexpr size_t blueHeight = fullHeight / 2; // car un pixel sur 2 est B
    
//     // Création du vecteur de destination pour les pixels bleus
//     std::vector<uint16_t> blueLayer(blueWidth * blueHeight);
    
//     // Extraction des pixels bleus
//     for(size_t y = 0; y < blueHeight; y++) {
//         for(size_t x = 0; x < blueWidth; x++) {
//             size_t srcIdx = (2*y + 1) * fullWidth + (2*x + 1);
//             size_t finalIdx = y * blueWidth + x;
//             blueLayer[finalIdx] = imageData[srcIdx];
//         }
//     }
    
//     return blueLayer;
// };

int main() {}
