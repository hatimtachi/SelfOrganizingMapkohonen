//
//  neuralNetworkProcess.c
//  Som
//
//  Created by hatim tachi on 15/11/2017.
//  Copyright © 2017 hatim tachi. All rights reserved.
//

#include "neuralNetworkProcess.h"


void initNetWorkWithData(MapNeurone *neurone,int lengthNetWork,int widthNetWork,double *vecMoyenne,int width){
    srand((unsigned int)time(NULL));

    for(int i = 0 ; i < lengthNetWork; i++){
        for(int j = 0; j < widthNetWork; j++){
            neurone->map[i][j].vecteur = getVecteurBorne(vecMoyenne,width,0.02,0.05);
            neurone->map[i][j].etiquete = 0;
        }
    }
}

/*************************************************************************/

void BestMatchingUnit(MapNeurone *neurone,int lengthNetWork,int widthNetWork,arrayIrisData *dataArrayStruct
                      ,int postionInDataArray,stack **stackBmu,int width){
    
    Clear(stackBmu);
    
    double baseDistance = distanceEculidenne(dataArrayStruct[postionInDataArray].vecDouble, neurone->map[0][0].vecteur,width);
    double tmpDistance  = .0;
    
    for(int i = 0; i < lengthNetWork;i++){
        for(int j = 0; j < widthNetWork;j++){
            
            tmpDistance = distanceEculidenne(dataArrayStruct[postionInDataArray].vecDouble, neurone->map[i][j].vecteur,width);
            
            if(tmpDistance == baseDistance){
                
                push(stackBmu,baseDistance,i,j);
                
            }else if (tmpDistance < baseDistance){
                baseDistance = tmpDistance;
                Clear(stackBmu);
                push(stackBmu,baseDistance,i,j);
            }
        }
    }
    if(Length(*stackBmu) > 1){
        int rand_       = rand()%Length(*stackBmu);
        stack stackTmp    = getStackFormPosition(*stackBmu, rand_);
        Clear(stackBmu);
        push(stackBmu,stackTmp.value,stackTmp.posiX,stackTmp.posiY);
    }
}


/*************************************************************************/

void neighborhood (MapNeurone *neurone,int lengthNetWork,int widthNetWork,double *vectorData
                   ,int rayon,double alpha,stack *bmuStack,int width){
    
    
    int x0,y0,x1,y1;
    x0 = bmuStack->posiX-rayon; if(x0 < 0) x0 = 0;
    y0 = bmuStack->posiY-rayon; if(y0 < 0) y0 = 0;
    x1 = bmuStack->posiX+rayon; if(x1 >= lengthNetWork) x1 = lengthNetWork - 1;
    y1 = bmuStack->posiY+rayon; if(y1 >= widthNetWork) y1 = widthNetWork - 1;
    
    for(int i=x0; i<= x1; i++){
        for(int j=y0; j <= y1; j++){
            for(int p=0; p<width; p++){
                neurone->map[i][j].vecteur[p] += alpha * (vectorData[p] - neurone->map[i][j].vecteur[p]);
            }
        }
    }
    
}

/*************************************************************************/

int getRayon (int sizeOfMapNeurone,int pourcentage){
    int rayon           = 0;
    int maxOfRayon      = (sizeOfMapNeurone*pourcentage)/100;
    int minVoision      = 8;
    int additionRayon   = (rayon * minVoision);
    
    while (additionRayon < maxOfRayon){
        additionRayon += (rayon * minVoision);
        
        if (additionRayon<maxOfRayon) rayon ++;
    }
    rayon = (rayon == 0) ? 1 : rayon;
    return rayon;
}

/*************************************************************************/

double getAlpha (int itration, int itTotal,double alpha_init){
    return alpha_init * (double)(1.0-(double)itration/(double)itTotal);
}


/*************************************************************************/


void learning(MapNeurone *neurone,int lengthNeurone,int widthNeurone,arrayIrisData *arrayIrisBrut,int length,int width,int maxTirage){
    
    stack *stackBmu         = NULL;
    
    int *tabShu             = malloc(sizeof(int) * length);
    int rayon               = getRayon(maxTirage,50);
    int nb_iteration_tot    = (500 * length) * .50;
    int phase               = nb_iteration_tot * .25;
    
    double alpha            = 0.0;
    double alpha_init       = .7;
    
    
    initShuffle(tabShu,length);
    
    for(int k = 0; k < nb_iteration_tot; k++){
        
        shuffle(tabShu, length);
        
        if( k <= phase){
            if (rayon > 1) {
                if(k == (phase * 1/3)) rayon--;
                if(k == (phase * 2/3)) rayon--;
            }
            alpha = getAlpha(k,phase,alpha_init);
        } else{
            alpha = getAlpha(k,nb_iteration_tot,alpha_init)*0.1;
            rayon = 1;
        }
            for(int i =0 ; i < length;i++){
                
                BestMatchingUnit(neurone,lengthNeurone,widthNeurone,arrayIrisBrut,tabShu[i],&stackBmu,width);
                neurone->map[stackBmu->posiX][stackBmu->posiY].etiquete = arrayIrisBrut[tabShu[i]].name;
                neighborhood(neurone, lengthNeurone, widthNeurone, arrayIrisBrut[tabShu[i]].vecDouble, rayon, alpha, stackBmu, width);
                Clear(&stackBmu);
            }    
        if(k % 5 == 0){
            system("clear");                        
            showNetWork(neurone, lengthNeurone, widthNeurone);
        }
    }
    system("clear");                
}
 
/*************************************************************************/

void showNetWork(MapNeurone* neurone, int lengthN,int widthN){
   
    for(int i=0;i<lengthN; i++){
        for(int j=0; j<widthN; j++){
            
            if(neurone->map[i][j].etiquete != 0){
                printf("%s ",dataSwitchName(neurone->map[i][j].etiquete));
            }else{
                printf(". ");
            }
        }
      
        printf("\n");
    }
}

/*************************************************************************/

char* dataSwitchName(char* name){
    if (strcmp("Iris-virginica",name) == 0) {
        return "*";
    }else if(strcmp("Iris-versicolor",name) == 0){
        return "#";
    }else if(strcmp("Iris-setosa",name) == 0){
        return "@";
    }
    return NULL;
}
