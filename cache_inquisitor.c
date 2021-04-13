
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>   // for INT_MAX
#include <time.h>     // for seeding srand, clock(),

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

void access_array_randomly(int* array, long array_size, int loop_count) {
    for (int i = 0; i < loop_count; i++) {
        int target_index = custom_random(0, array_size);

        if (target_index % 8 == 0) {
            dont_forget_me_plz = array[target_index] % 2;
        }
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
    long array_size = 8;
    int step = sizeof(int);
    // int* byte_array = (int*)malloc(array_size);

    printf("%s\n", "Am I alive?");
    for (int i = step; i < (sizeof(int)<<22); i*=step) {
        array_size = i;
        printf("array_size = %lu,\n", array_size);
        printf("i: %d\n", i);
        printf("stuff: %d\n", sizeof(int)<<20);
        // byte_array = realloc(byte_array, array_size);
        int* byte_array = (int*)malloc(sizeof(int) * array_size);
        printf("byte_array = %p,\n", byte_array);
        populate_array(byte_array, array_size);
        printf("%s,\n", "*****************");
        clock_t initial_time = clock();
        access_array_randomly(byte_array, array_size, 1000000);
        clock_t final_time = clock();
        free(byte_array);
        double time_diff = 1000 * ((double) final_time - initial_time)/ CLOCKS_PER_SEC;

        printf("%f,", time_diff);
        printf("%lu,", array_size);
        printf("%lu,\n", dont_forget_me_plz);

        // sleep(1);
    }

    // free(byte_array);

    return 0;
}
