
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>   // for INT_MAX
#include <time.h>     // for seeding srand, clock(),

int x = 1, y = 4, z = 7, w = 13;

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
        //printf("%d, %d\n", array[target_index], target_index);
    }
}

void access_cached_value(int* array, long array_size, int loop_count) {
    for (int i = 0; i < loop_count; i++) {
        int target_index = custom_random(0, array_size);
        int x = array[target_index];  // trivial assignment
        //printf("%d, %d\n", array[target_index], target_index);
    }
}

// populate all indices with the same value
void populate_array(int* array, long array_size) {
    for (int i = 0; i < array_size; ++i) {
        int temp = 100;
        array[i] = temp;
    }
}

int main() {

    /*
    because 2 << 27 is slightly over 1 billion, we cannot simply
    multiply by 8 to get 8 gigs. We will get an overflow. Thus,
    7 * 2 << 27 is used
    */

    long array_size = 7 * (2<<27);
    int* byte_array = (int*)malloc(sizeof(int) * array_size);

    populate_array(byte_array, array_size);

    clock_t initial_time = clock();
    access_array_randomly(byte_array, array_size, 1000000);
    clock_t final_time = clock();

    double time_diff = 1000 * ((double) final_time - initial_time)/ CLOCKS_PER_SEC;

    printf("%f,\n", time_diff);

    free(byte_array);
    return 0;
}
