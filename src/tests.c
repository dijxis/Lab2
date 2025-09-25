#include <stdio.h>

int check(int k, float resistance[], float resistance_final) {
  double sum = 0;
  for (size_t i = 0; i < k; i++) {
    sum += resistance[i] - resistance_final;
  }
  return abs(sum / k) <= 1e-9;
}
