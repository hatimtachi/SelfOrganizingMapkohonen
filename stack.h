//
//  stack.h
//  Som
//
//  Created by hatim tachi on 28/11/2017.
//  Copyright © 2017 hatim tachi. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    double value;
    int posiX;
    int posiY;
    struct stack *prec;
}stack;

// insert un nouveau element dans la liste
void    push                (stack **p,double value,int positionX,int positionY);
// supression de la liste
void    Clear               (stack **p);

int     Length              (stack *p);

void    view                (stack *p);

stack   getStackFormPosition (stack *p,int position);

#endif /* stack_h */
