#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN
// Taille d'une image 
    int colorImageSize = w * h * 3; // Taille d'une image couleur en octets 
    int bwImageSize = w * h;       // Taille d'une image noir et blanc en octets 

    // Nombre total d'images pour chaque section :
    int colorFrames = durationMovie * fps; // Nombre d'images pour la section couleur
    int bwFrames = durationCredits * fps; // Nombre d'images pour la section noir et blanc

    // Taille totale de la vidéo en octets :
    float totalSize = (colorFrames * colorImageSize) + (bwFrames * bwImageSize);

    // Conversion en fonction de l'unité demandée :
    if (strcmp(unit, "bt") == 0) {
        totalSize *= 8; // Conversion en bt
    } else if (strcmp(unit, "ko") == 0) {
        totalSize /= 1024; // Conversion en ko
    } else if (strcmp(unit, "mo") == 0) {
        totalSize /= (1024 * 1024); // Conversion en mo
    } else if (strcmp(unit, "go") == 0) {
        totalSize /= (1024 * 1024 * 1024); // Conversion en go
    }

    return totalSize; //la taille totale
}
   // YOUR CODE HERE - END
