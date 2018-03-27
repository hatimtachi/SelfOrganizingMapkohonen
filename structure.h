//
//  structure.h
//  Som
//
//  Created by hatim tachi on 01/11/2017.
//  Copyright © 2017 hatim tachi. All rights reserved.
//

#ifndef structure_h
#define structure_h

typedef struct{
    double  * vecDouble;
    char    * name;
    double    norme;
}arrayIrisData;

typedef struct {
    double *vecteur;
    double activation;
    char   *etiquete;
}Neurone;

typedef struct{
    Neurone **map;
}MapNeurone;


#endif /* structure_h */
