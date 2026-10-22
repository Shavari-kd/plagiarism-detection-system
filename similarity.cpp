#include "similarity.h"

double calculateSimilarity(int lcsLength, int len1, int len2) {
    return (2.0 * lcsLength / (len1 + len2)) * 100;
}