#include <iostream>
#include "CacheSim.h"
using namespace std;


int main() {
    char  test_case [100]= "/home/find/ddown/traces/gcc.trace";

    int line_size[] = {32, 64, 128};
    int ways[] = {1, 2, 4, 8, 12, 16};
    int i,j;

    for (i=0; i<sizeof(line_size)/sizeof(int); i++){
        for (j=0; j<sizeof(ways)/sizeof(int); j++){
            for (int k = CACHE_SWAP_FIFO; k < CACHE_SWAP_MAX; ++k) {
                CacheSim cache =CacheSim(0x8000, line_size[i], ways[j]);
                cache.set_swap_style(k);
                cache.load_trace(test_case);

            }
        }
    }
    return 0;
}