//
//  neuralNetworkProcess.h
//  Som
//
//  Created by hatim tachi on 15/11/2017.
//  Copyright © 2017 hatim tachi. All rights reserved.
//

#ifndef neuralNetworkProcess_h
#define neuralNetworkProcess_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"
#include "dataProcess.h"
#include "stack.h"


// init Vecteur Neurone
void    initNetWorkWithData (MapNeurone *neurone,int lengthNetWork,int widthNetWork,double *vecMoyenne,int width);
// fonction d'affichage
void    showNetWork         (MapNeurone* neurone, int lengthN,int widthN);
char*   dataSwitchName      (char* name);
// fonction qui me bmu dans une liste chaine (pile)
void    BestMatchingUnit    (MapNeurone *neurone,int lengthNetWork,int widthNetWork,arrayIrisData *dataArrayStruct
                                                ,int postionInDataArray,stack **stackBmu,int width);
// apprentisage dans le voisinage
void    neighborhood        (MapNeurone *neurone,int lengthNetWork,int widthNetWork,double *vectorData
                                                ,int rayon,double alpha,stack *bmuStack,int width);
// pour avoir le rayon du voisinage
int     getRayon            (int sizeOfMapNeurone,int pourcentage);
// pour avoir l'alpha
double  getAlpha            (int itration, int itTotal,double alpha_init);
// regroupe les fonction d'apprentisage
void    learning            (MapNeurone *neurone,int lengthNeurone,int widthNeurone,arrayIrisData *arrayIrisBrut
                                                ,int length,int width,int maxTirage);
#endif /* neuralNetworkProcess_h */
