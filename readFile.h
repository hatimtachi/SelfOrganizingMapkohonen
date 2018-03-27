//
//  readFile.h
//  Som
//
//  Created by hatim tachi on 01/11/2017.
//  Copyright © 2017 hatim tachi. All rights reserved.
//

#ifndef readFile_h
#define readFile_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structure.h"

void            getDataFromFile (char* fileName,arrayIrisData* ArrayParam);
int             getLengthFile   (char* fileName);
int             getWidthFile    (char* fileName);
int             getBuffer       (char* fileName);
void            showData        (arrayIrisData* ArrayParam,int length,int width);


#endif /* readFile_h */
