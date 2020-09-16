//
//  main.c
//  exe3
//
//  Created by НУРИЯ on 9/17/20.
//  Copyright © 2020 НУРИЯ. All rights reserved.
// Nuriya Umirbekova exe 3;
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define max_buff 1000
#define NULL_PTHREAD 0

int buff=0; // it's a buffer, where objects from producers will transfer to consumers
int producer_sleep=1;
int consumer_sleep=0;
pthread_t tProducer;
pthread_t tConsumer;



void* Consumer(void *x){
    int i=0;
    while(1){
        while(buff==0);
        if(i%1000==0)
            printf("Consumer %d %d\n",i,buff);
        if(buff>0){
            i++; //Consumer takes product
            buff--; //leading the fact above the size of buffer is decreasing
        }
    }
}
void* Producer(void *x){
    int i=0;
    while(1){
        while(buff==max_buff );//Wait until buffer is not full
        if(i%1000==0)
            printf("Producer %d %d\n",i,buff);//Shows the number of made products by producer and demonstrates the size of the buffer
        if(buff<max_buff ){// Producer makes product
            i++;
            buff++;  //the size of buffer is increasing due to the producer increase the number of made products
        }
    }
}

int main(){
    pthread_create(&tProducer,NULL,&Producer,NULL);
    pthread_create(&tConsumer,NULL,&Consumer,NULL);
    pthread_join(tProducer,NULL);
}
