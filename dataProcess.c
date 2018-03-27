//
//  dataProcess.c
//  Som
//
//  Created by hatim tachi on 03/11/2017.
//  Copyright © 2017 hatim tachi. All rights reserved.
//

#include "dataProcess.h"



void initShuffle(int *tabIndice,int length){
    for(int i=0;i<length;i++){
        tabIndice[i]=i;
    }
}
/*************************************************************************/


void shuffle(int *tabIndice,int length){

    for(int i=0;i<length;i++){
        int _rand=rand()%length;
        int tmp=tabIndice[i];
        tabIndice[i]=tabIndice[_rand];
        tabIndice[_rand]=tmp;
    }
}

/*************************************************************************/


void setNormeInDataStruct(arrayIrisData *dataArrayStruct,int length,int width){
    
    double norm = .0;
    
    for(int i=0;i<length;i++){
      
        for(int j=0;j<width;j++){
            norm += pow(dataArrayStruct[i].vecDouble[j], 2);
        }
       
        norm                        = sqrt(norm);
        dataArrayStruct[i].norme    = norm;
        norm                        = .0;
    
    }
}

/*************************************************************************/


void setDataWithNorme(arrayIrisData *dataArrayStruct,int length,int width){
    
    for (int i = 0; i < length ; i++){
        
        for (int j = 0; j < width ; j++){
        
            dataArrayStruct[i].vecDouble[j] /= dataArrayStruct[i].norme;
        
        }
    
    }
}

/*************************************************************************/

void setMeanVector (arrayIrisData *dataArrayStruct,int length,int width,double *vector){
    
    double sommeColonne=.0;
    
    for(int i = 0;i < width;i++){
    
        for(int j = 0;j < length;j++){
    
            sommeColonne += dataArrayStruct[j].vecDouble[i];
        
        }
        vector[i] = sommeColonne/(length);
        sommeColonne=0;
    
    }
}
/*************************************************************************/



void showMeanVector(int width,double* vecteurMoyenne){
    for(int i=0 ; i < width ; i++){
        printf(" i -->>> %d =  %lf\n",i,vecteurMoyenne[i]);
    }
}
/*************************************************************************/

int neuroneNumber(int length){
    return ( ( 5 * sqrt(length) ) / 10 ) * 10;
}
/*************************************************************************/


double randomDouble(double min,double max){
    return (max - min) * ((((double) rand()) / (double) RAND_MAX)) + min ;
}

/*************************************************************************/


double* getVecteurBorne(double *vecteurMoyenne,int width,double borneMin,double borneMax){
    
    double bornMin = .0,bornMax = .0,_rand = .0;
    double *vecteurBorne = malloc(width * sizeof(double));
    
    for (int i =0; i<width; i++) {
    
        bornMin             = vecteurMoyenne[i] - borneMin;
        bornMax             = vecteurMoyenne[i] + borneMax;
        _rand               = randomDouble(bornMin,bornMax);
        vecteurBorne[i]     = _rand;
    }
    return vecteurBorne;
}

/*************************************************************************/


int getLengthNeurone(int lengthData){
    return 5 * (sqrt(lengthData))/10;
}

/*************************************************************************/


double distanceEculidenne(double *vec,double *vec2,int length){
    
    double res = .0;
    for (int i = 0; i < length; i++) {
        res += pow(vec[i] - vec2[i],2);
    }
    
    return sqrt(res);
}















