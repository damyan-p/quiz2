#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define true 1
#define false 0

// An array x contains n non-negative integers.
// Write a function that determines if you can add together any k of the elements in x and get precisely v.

void baseTest();
void repeatedTest();
void normalTest();
void fillRandom(uint* x, uint len);
void fill(uint* x, uint len, uint fill);

int recursiveSubsetSum(uint x[], uint n, uint k, uint v);

int main(void) {
    baseTest();
    repeatedTest();
    normalTest();
    printf("All tests passed!\n");
    return 0;
}

void baseTest() {
    uint temp = rand() % 100;
    uint x[temp];
    fillRandom(x, temp);
    assert(recursiveSubsetSum(x,temp,0,0));
    assert(!(recursiveSubsetSum(x,0,1,1)));
    assert(!(recursiveSubsetSum(x,temp,0,2)));
    printf("Base tests confirmed.\n");
}

void repeatedTest() {
    uint temp = rand() % 100;
    int x[temp];
    fill(x, temp, 1);
    assert(recursiveSubsetSum(x,temp,2,2));
    assert(recursiveSubsetSum(x,temp,1,1));
    printf("Duplicate numbers test confirmed.\n");
}

void normalTest() {
    uint temp = rand() % 100;
    int x[temp];
    fillRandom(x, temp);
    assert(recursiveSubsetSum(x,temp,2,x[0]+x[temp-1]));
    assert(recursiveSubsetSum(x,temp,2,x[0]+x[0]));
    printf("Standard test confirmed.\n");
}

void fillRandom(uint* x, uint len) {
    for(int i = 0; i < len; i++) {
        x[i] = rand() % 100;
    }
}

void fill(uint* x, uint len, uint fill) {
    for(int i = 0; i < len; i++) {
        x[i] = fill;
    }
}

int recursiveSubsetSum(uint x[], uint n, uint k, uint v) {
    // base cases
    if(v == 0 && k == 0) {
        return true;
    }
    if(v != 0 && k == 0) {
        return false;
    }
    if(n == 0) {
        return false;
    }
    int temp = 0;
    if(v >= x[0]) {
        temp = recursiveSubsetSum(x+1, n-1, k-1, v-x[0]);
        int temp1 = recursiveSubsetSum(x+1, n-1, k, v);
        return temp + temp1 > 0;
    }

}