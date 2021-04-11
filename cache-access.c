#include <stdlib.h>
#include <stdio.h>
#include <limits.h>   // for INT_MAX

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

void populate_array(int* array, long array_size) {
    for (int i = 0; i < array_size; ++i) {
        int temp = simplerand();
        array[i] = temp;
        if (i % 50000 == 0) {
            printf("%d\n", array[i]);
        }
    }
}

int main() {
    int gb_size = 2<<30;
    //long array_size = gb_size * 8;

    /*
    because 2 << 27 is slightly over 1 billion, we cannot simply
    multiply by 8 to get 8 gigs. We will get an overflow. Thus,
    7 * 2 << 27 is used
    */
    
    long array_size = 7 * (2<<27);

    int* byte_array = (int*)malloc(sizeof(int) * array_size);

    //printf("%lu", array_size);
    populate_array(byte_array, array_size);

    free(byte_array);
    return 0;
}
