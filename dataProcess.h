//
//  dataProcess.h
//  Som
//
//  Created by hatim tachi on 03/11/2017.
//  Copyright © 2017 hatim tachi. All rights reserved.
//

#ifndef dataProcess_h
#define dataProcess_h

#include <stdio.h>
#include "math.h"
#include <time.h>
#include <stdlib.h>
#include "structure.h"

// initalisation du tableau de suffle
void    initShuffle             (int *tab,int length);
// faire le suffle sur le tableau Shuffle
void    shuffle                 (int *tabIndice,int length);
// calculer la norme de la structure Data
void    setNormeInDataStruct    (arrayIrisData *dataArrayStruct,int length,int width);
// nomralizer les vecteurs de la structure on divison les valeurs par le norme
void    setDataWithNorme        (arrayIrisData *dataArrayStruct,int length,int width);
// cree le vecteur moyenne avec la Structure Data normalizer
void    setMeanVector           (arrayIrisData *dataArrayStruct,int length,int width,double *vector);
// afficher le vecteur moyenne
void    showMeanVector          (int length,double *vecteur);
// (5* (sqrt (length) ) / 10) * 10
int     neuroneNumber           (int length);
// distance euclidienne
double  distance_euclidienne    (double*vec1,double*vec2,int length);
// random de Double
double  randomDouble            (double min,double max);
// taille de la grille des Neurone
int     getLengthNeurone        (int lengthData);
// return le vecteur moyenne borne
double  *getVecteurBorne        (double *vecteurMoyenne,int width,double borneMin,double borneMax);
// distance eculidenne
double  distanceEculidenne      (double *vec,double *vec2,int length);
#endif /* dataProcess_h */
