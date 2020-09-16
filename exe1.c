//
//  main.c
//  exe1
//
//  Created by НУРИЯ on 9/15/20.
//  Copyright © 2020 НУРИЯ. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define n 20  //just for testing, the number can change depending on your choice
#define NULL_PTHREAD 0

void *Thread(void * arg)   //this's the fuction 
{
    pthread_t thread_id[n];
    pthread_t id=pthread_self();
    for (int i=0; i<n; ++i){
        if(pthread_equal(id, thread_id[n])){
            printf("Hello from thread %d\n",i);
            exit(0);
        }
    }
        
    return NULL;
}
   
int main()
{
    pthread_t thread_id[n];
    for (int i=0; i<n; ++i){
        pthread_create(&thread_id[i], NULL, &Thread, NULL);
        printf("Thread number: %d\n", i);
        pthread_join(thread_id[i], NULL);
        
    }
    return 0;

}

