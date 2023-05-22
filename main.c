#include <stdio.h>
#include "moving_average.h"

int main()
{
    average avg1, avg2; //two instances of moving_average
    mov_avg_init(&avg1); //lets initialize them
    mov_avg_init(&avg2);

    //push some numbers to the average 1
    mov_avg_push(&avg1, 1.0f);
    mov_avg_push(&avg1, 2.5f);
    mov_avg_push(&avg1, 3.0f);

    //push some numbers to the average 2
    mov_avg_push(&avg2, 100.0f);
    mov_avg_push(&avg2, 150.0f);

    //lets see whats the average
    printf("Moving average avg1 is = %f\n", mov_avg_get(&avg1));
    printf("Moving average avg2 is = %f\n", mov_avg_get(&avg2));

    //lets push more numbers to average 1
    mov_avg_push(&avg1, 100.0f);
    mov_avg_push(&avg1, 97.0f);

    //lets see whats the average now
    printf("Now moving average avg1 is = %f\n", mov_avg_get(&avg1)); //it should display 66,(6) as we are now computing (3,0+100,0+97,0)/3

    //lets now clear average 1 and see whats in it
    mov_avg_clear(&avg1);
    printf("Moving average avg1 after clear is = %f\n", mov_avg_get(&avg1));

    //lets see if average 2 stayed untouched
    printf("Moving average avg2 is = %f\n", mov_avg_get(&avg2));

    return 0;
}