#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN
  // Taille de base en octets
   float sizeInBytes = w * h * 3; 

   // Convertir en bits
    if (strcmp(unit, "bt") == 0) {
        return sizeInBytes * 8; 
        
   // Convertir en kilobytes  
    } else if (strcmp(unit, "ko") == 0) {
        return sizeInBytes / 1024; 

   // Convertir en megabytes
    } else if (strcmp(unit, "mo") == 0) {
        return sizeInBytes / (1024 * 1024); 

   // Convertir en gigabytes
    } else if (strcmp(unit, "go") == 0) {
        return sizeInBytes / (1024 * 1024 * 1024); 

   // Unite inconnue
    } else {
        return 0; 
    }
}

   // YOUR CODE HERE - END
