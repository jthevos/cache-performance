
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>   // for INT_MAX
#include <time.h>     // for seeding srand, clock(),
#include <math.h>

int x = 1, y = 4, z = 7, w = 13;

long dont_forget_me_plz;

int simplerand(void) {
  int t = x;
  t ^= t << 11;
  t ^= t >> 8;
  x = y;
  y = z;
  z = w;
  w ^= w >> 19;
  w ^= t;

  return w;
}

long custom_random(int min, int max) {
    srand(simplerand());
    return min + rand() / (RAND_MAX / (max-min+1) + 1);
}


void access_array_offset(int* array, long array_size, long offset) {
    for(int i = 0; i < offset; i++){
        dont_forget_me_plz = array[i];
    }
}

// populate all indicies with a random value
void populate_array(int* array, long array_size) {
    printf("populate_array array param = %p\n", array);
    for (int i = 0; i < array_size; i+=sizeof(int)) {
        //int temp = 42;
        // printf("index = %d,", i);
        array[i] = i;

    }
    printf("\n");
}

int main() {

    /*
    because 2 << 27 is slightly over 1 billion, we cannot simply
    multiply by 8 to get 8 gigs. We will get an overflow. Thus,
    7 * 2 << 27 is used
    */
    long array_size = 262144;
    int step = sizeof(int);
    int count = 0;
    long pp =  (long)pow(step, 20);
    long offset = 1;
    int* byte_array = (int*)malloc(sizeof(int) * array_size);
    populate_array(byte_array, array_size);

    printf("%ld\n", pp);
    // for (int i = step; i < (sizeof(int)<<28); i*=step) {
    for (long i = 1; i < 32; i++) {
        // array_size = i;
        // offset = i;
        // count++;
        
        for(int j = 0; j < 50; j++){
            clock_t initial_time = clock();
            access_array_offset(byte_array, 10000000, i);
            clock_t final_time = clock();
            double time_diff = 1000 * ((double) final_time - initial_time)/ CLOCKS_PER_SEC;

            printf("offset: %lu, ", i);
            // printf("count: %d,", count);
            printf("time diff: %f,", time_diff);
            printf("array size: %lu,", array_size);
            printf("%lu,\n", dont_forget_me_plz);
        }
        printf("-------------------------------------\n");
        

        // sleep(1);
    }

    free(byte_array);

    return 0;
}
