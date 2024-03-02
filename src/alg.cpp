// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double stepen = 1.0;
  for (uint64_t k = 0; k < n; k++) {
    stepen *= value;
  }
  return stepen;
}

uint64_t fact(uint16_t n) {
  uint64_t res = 1;
  if (n == 0 || n == 1) {
    return 1;
  } else {
    for (uint64_t k = n; k >= 1; k--) {
      res *= k;
    }
    return res;
    }
}

double calcItem(double x, uint16_t n) {
  return (pown(x, n) / fact(n));
}

double expn(double x, uint16_t count) {
  double res = 1.0;
  for (uint64_t k = 1; k <= count; k++) {
    double item = calcItem(x, k);
    res += item;
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double summa = 0.0;
  for (uint64_t perem1 = 0; perem1 < count; perem1++) {
    double a = calcItem(x, 2 * perem1 + 1);
    if (perem1 % 2 == 0) {
      summa += a;
    } else {
      summa -= a;
    }
  }
  return summa;
}

double cosn(double x, uint16_t count) {
  double result = 1;
  for (uint64_t i = 2; i <= count; i++) {
    double item = calcItem(x, (2 * i) - 2);
    double sign = 1.0;   
    if (i % 2 == 0) {
      sign = 1.0;
    } else {
      sign = -1.0;
    } 
    result += item * sign;
  }
  return result;
}
