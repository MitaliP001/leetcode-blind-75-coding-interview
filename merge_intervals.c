#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compare(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    qsort(intervals, intervalsSize, sizeof(struct Interval), compare);
    
    struct Interval* result = (struct Interval*)malloc(intervalsSize * sizeof(struct Interval));
    result[0] = intervals[0];
    int count = 1;
    
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i].start <= result[count - 1].end) {
            result[count - 1].end = (intervals[i].end > result[count - 1].end) ? intervals[i].end : result[count - 1].end;
        } else {
            result[count] = intervals[i];
            count++;
        }
    }
    
    *returnSize = count;
    return result;
}

int main() {
    struct Interval intervals[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int returnSize;
    
    struct Interval* result = merge(intervals, 4, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }
    printf("\n");
    
    free(result);
    return 0;
}
