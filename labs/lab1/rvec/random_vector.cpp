#include "random_vector.h"
#include <cstdlib>
#include <map>
#include <cmath>
#include <string>
// TODO: add any include you might require

RandomVector::RandomVector(int size, double max_val) { 
  for (int i = 0; i < size; i++)
    vect.push_back(static_cast<double>(std::rand()) / ((double)RAND_MAX / max_val));
}

void RandomVector::print(){
  for (auto &elem : vect)
    std::cout << elem << " ";
  std::cout << std::endl;
}

double RandomVector::mean(){
  double val = 0;
  for (auto &elem : vect)
    val += elem;
  return val / vect.size();
}

double RandomVector::max(){
  double max = -1.0;
  for (auto &elem : vect)
    max = elem > max ? elem : max;
  return max;
}

double RandomVector::min(){
  double min = 1.1;
  for (auto &elem : vect)
    min = elem < min ? elem : min;
  return min;
}

void RandomVector::printHistogram(int bins){
  double left,right,width;
  left = RandomVector::min();
  right = RandomVector::max();
  width = (right - left) / (double)bins;
  
  std::vector<int> b(bins, 0);
  for (auto &elem : vect) {
    int posn = 0;
    while ((elem = elem - width) >= left)
      posn++;
    if (posn >= bins)
      posn = bins - 1;
    b[posn]++;
  }

  int max_bin = 0;
  for (auto &elem : b) 
    max_bin = max_bin < elem ? elem : max_bin;
  
  std::vector<std::vector<std::string>> histogram(max_bin, std::vector<std::string>(bins,"   "));
  for (int i = histogram.size() - 1; i >= 0; i--) {
    for (int j = 0; j < histogram[i].size(); j++) {
      if (b[j] > 0) {
        histogram[i][j] = "***";
        b[j]--;
      }
    }
  }

  for (auto &a : histogram) {
    for (auto &b : a) {
      std::cout << b << " ";
    }
    std::cout << std::endl;
  }
  
  // TODO: Write your code here
}
