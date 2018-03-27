//
//  stack.c
//  Som
//
//  Created by hatim tachi on 28/11/2017.
//  Copyright © 2017 hatim tachi. All rights reserved.
//

#include "stack.h"


void push(stack **p,double value,int positionX,int positionY){
    
    stack *element   = malloc(sizeof(stack));
    if (!element) exit(EXIT_FAILURE);
    element->value  = value;
    element->posiX  = positionX;
    element->posiY  = positionY;
    element->prec   = *p;
    *p = element;
}

/*************************************************************************/


void Clear(stack **p){
    
    stack *tmp;
    while (*p) {
        tmp = (*p)->prec;
        free(*p);
        *p  = tmp;
    }
    
}

/*************************************************************************/


int Length(stack *p){

    int len = 0;
    while (p) {
        len++;
        p = p->prec;
    }
    return len;
}

/*************************************************************************/


stack getStackFormPosition(stack *p,int position){
    int count = 0;
    int posiY = 0;
    int posiX = 0;
    double value = .0;
    stack *element   = malloc(sizeof(stack));
    while (p) {
        if (count == position) {
            posiY = p->posiY;
            posiX = p->posiX;
            value = p->value;
        }
        count++;
        p = p->prec;
    }
    element->posiX = posiX;
    element->posiY = posiY;
    element->value = value;
    return *element;
}

/*************************************************************************/


void view(stack *p){
    
    while (p) {
        printf("value %lf , in postion ->> x : %d , y : %d\n",p->value,p->posiX,p->posiY);
        p   = p->prec;
    
    }
}



