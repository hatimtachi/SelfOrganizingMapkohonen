//
//  main.c
//  Som
//
//  Created by hatim tachi on 01/11/2017.
//  Copyright © 2017 hatim tachi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "readFile.h"
#include "dataProcess.h"
#include "neuralNetworkProcess.h"
#define FILENAME "irisData.txt"

int main(void) {
    srand((unsigned int)time(NULL));
    MapNeurone  mapNeurone;
    
    int length          = getLengthFile(FILENAME);
    int width           = getWidthFile (FILENAME);
    int maxTirage       = neuroneNumber(length);
    int lengthNeurone   = getLengthNeurone(length);
    int widthNeurone    = 10;

    arrayIrisData *arrayIrisBrut    = malloc(length         * sizeof(arrayIrisData));
    double *meanVector              = malloc(length         * sizeof(double));
    mapNeurone.map                  = malloc(lengthNeurone  * sizeof(Neurone*));
    
    if (mapNeurone.map != NULL) {
        // malloc du la map de neurone
        for(int i = 0;i <lengthNeurone; i++){
            mapNeurone.map[i] = (Neurone *) malloc(widthNeurone * (sizeof(Neurone)));
        }
        // malloc du vecteur de la map du neurones
        for (int i = 0 ;i < lengthNeurone ; i++) {
            for (int j = 0; j < widthNeurone; j++) {
                mapNeurone.map[i][j].vecteur = malloc(width * sizeof(double));
            }
        }
    }
    
    
    getDataFromFile(FILENAME,arrayIrisBrut);
    
    setNormeInDataStruct(arrayIrisBrut,length,width);
    
    setDataWithNorme(arrayIrisBrut,length,width);
    
    setMeanVector(arrayIrisBrut,length, width, meanVector);
    
   // showMeanVector(width, meanVector);
    
    initNetWorkWithData(&mapNeurone, lengthNeurone, widthNeurone, meanVector, width);
    
    learning(&mapNeurone, lengthNeurone, widthNeurone, arrayIrisBrut, length, width, maxTirage);
  
    showNetWork(&mapNeurone, lengthNeurone, widthNeurone);
    
    free(mapNeurone.map);
    free(meanVector);
    free(arrayIrisBrut);
    return 0;
}
