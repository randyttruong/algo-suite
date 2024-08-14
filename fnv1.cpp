//
// Created by Randy Truong on 8/14/24.
//

#include "fnv1.h"

#include <vector>

uint64_t hash(std::string input, int size) {
 if (FNV_PRIMES.find(size) == FNV_PRIMES.end()) {
  std::cerr << "[ERROR] Hashing size: " << size << " not found.";
  std::exit(1);
 }

 if (FNV_OFFSET_BASES.find(size) == FNV_OFFSET_BASES.end()) {
  std::cerr << "[ERROR] Offset base size: " << size << " not found.";
  std::exit(1);
 }

 uint64_t hash = FNV_OFFSET_BASES.at(size);
 uint64_t fnvPrime = FNV_PRIMES.at(size);

 for (int i = 0; i < input.size(); i++) {
  int charToByte = int(input[i]);

  for (int j = 0; j < sizeof(charToByte); j++) {
   hash = hash * fnvPrime;
   hash = hash ^ charToByte;
  }
 }

 return hash;
}

uint64_t hash(std::vector<int> input, int size) {
 if (FNV_PRIMES.find(size) == FNV_PRIMES.end()) {
  std::cerr << "[ERROR] Hashing size: " << size << " not found.";
  std::exit(1);
 }

 if (FNV_OFFSET_BASES.find(size) == FNV_OFFSET_BASES.end()) {
  std::cerr << "[ERROR] Offset base size: " << size << " not found.";
  std::exit(1);
 }

 uint64_t hash = FNV_OFFSET_BASES.at(size);
 uint64_t fnvPrime = FNV_PRIMES.at(size);

 for (int i = 0; i < input.size(); i++) {

  int currInt = input[i];

  for (int j = 0; j < sizeof(currInt); j++) {

   uint8_t currByte = (currInt >> (j * 8)) & 0xFF;
   hash = hash * fnvPrime;
   hash = hash ^ currByte;

  }
 }

 return hash;
}

uint64_t hash(int input, int size) {
 if (FNV_PRIMES.find(size) == FNV_PRIMES.end()) {
  std::cerr << "[ERROR] Hashing size: " << size << " not found.";
  std::exit(1);
 }

 if (FNV_OFFSET_BASES.find(size) == FNV_OFFSET_BASES.end()) {
  std::cerr << "[ERROR] Offset base size: " << size << " not found.";
  std::exit(1);
 }

 uint64_t hash = FNV_OFFSET_BASES.at(size);
 uint64_t fnvPrime = FNV_PRIMES.at(size);

 for (int i = 0; i < sizeof(input); i++) {
  uint8_t currByte = (input >> (i * 8)) & 0xFF;
  hash = hash * fnvPrime;
  hash = hash ^ currByte;
 }

 return hash;
}

