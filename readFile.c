//
//  readFile.c
//  Som
//
//  Created by hatim tachi on 01/11/2017.
//  Copyright © 2017 hatim tachi. All rights reserved.
//

#include "readFile.h"



int getLengthFile(char* fileName){
    
    FILE* file  = fopen(fileName,"r");
    
    int nbLine  = 0;
    char *line  = NULL;
    size_t size = getBuffer(fileName) * sizeof(char);
    
    while (getline (&line,&size,file)!= -1) {nbLine++;}

    fclose(file);
    return nbLine;
}

/*************************************************************************/


int getWidthFile(char* fileName){
    
    FILE *file  = fopen(fileName,"r");
    int cara    = fgetc(file);
    int nbCol   = 0;
    
    while (cara != '\0') {
        if (cara == ',') {
            ++nbCol;
        }else if(cara == '\n'){
            break;
        }
        cara    = fgetc(file);
    }
    fclose(file);
    return nbCol;
}

/*************************************************************************/

int getBuffer(char* fileName){
    FILE* file = fopen(fileName,"r");
    int buf = 0;
    while (!feof(file)) {
        if (getc(file) != '\n') {
            buf++;
        }else{
            break;
        }
    }
    fclose(file);
    return buf*3;
}

/*************************************************************************/

void getDataFromFile (char* fileName,arrayIrisData *arrayParam){
    FILE* file = fopen(fileName,"r");
    
    char line[getBuffer(fileName)];
    char *token;
    char *name = NULL;
    const char specialC[2]  = ",";
    
    int positionVecteurData = 0;
    int positionArray       = 0;
    
    while (fgets(line ,getBuffer(fileName) * sizeof(char) ,file)) {
        
        token = strtok(line,specialC);
        
        positionVecteurData = 0;
        
        int sizeStack = getWidthFile(fileName);
        
        arrayParam[positionArray].vecDouble = malloc(sizeStack *(sizeof(arrayParam[positionArray].vecDouble)));
    
        while (token != NULL) {
        
            double x = strtod(token, &name);
            
            if (strcmp(name,"")) {
            
                arrayParam[positionArray].name = malloc(strlen(name) * sizeof(char));
                char *nameToCpy = strtok(name,"\n");
                strcpy(arrayParam[positionArray].name,nameToCpy);
            
            }else{
                
                arrayParam[positionArray].vecDouble[positionVecteurData] = x;
            
            }
            
            positionVecteurData ++;
            token = strtok(NULL, specialC);
        }
        positionArray ++;
    }
    fclose(file);
}

/*************************************************************************/

void showData(arrayIrisData *array,int length,int width){
    for (int i =0;i < length ; i++) {
        printf("Name  %s \n",array[i].name);
        for (int j =0 ;j < width ; j++) {
            printf("valeur %d = %lf \n",j,array[i].vecDouble[j]);
        }
        printf("norme  %lf\n",array[i].norme);
        printf("*******************\n");
    }
}













