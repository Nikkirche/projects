#include "sim.h"
#define REPEAT_SIZE 8

int getColor(unsigned t) {

  if (t != 0) {
    return 0x0000000 + t * 0xFFF;
  } else {
    return 0xFFFFFFFF;
  }
}
void drawGen(const unsigned *gen) {

  for (int y = 0; y < SIM_Y_SIZE; y++)
    for (int x = 0; x < SIM_X_SIZE; x++) {
      simSetPixel(x, y, getColor(gen[y * SIM_X_SIZE + x]));
    }
  simFlush();
}

void calcGen(unsigned *nextGen, const unsigned *prevGen) {

  for (int y = 0; y < SIM_Y_SIZE; y++) {
    for (int x = 0; x < SIM_X_SIZE; x++) {
      int c = 0;
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (!(dx == 0 && dy == 0) &&
          prevGen[simAbs(y - dy) % SIM_Y_SIZE * SIM_X_SIZE + simAbs(x - dx) % SIM_Y_SIZE] != 0) {
            c++;
          }
        }
      }
      unsigned curr = prevGen[y * SIM_X_SIZE + x];
      if (c == 3 || (curr != 0 && c == 2)) {
        nextGen[y * SIM_X_SIZE + x] = prevGen[y * SIM_X_SIZE + x] + 1;
      } else {
        nextGen[y * SIM_X_SIZE + x] = 0;
      }
    }
  }
}

int main() {
  unsigned gen1[SIM_Y_SIZE * SIM_X_SIZE];
  unsigned gen2[SIM_Y_SIZE * SIM_X_SIZE];
  unsigned *nextGen = gen1;
  unsigned *prevGen = gen2;
  init();
  for (int y = 0; y < SIM_Y_SIZE; y++)
    for (int x = 0; x < SIM_X_SIZE; x++) {
      prevGen[y * SIM_X_SIZE + x] = simRand() % 2;
    }
  drawGen(prevGen);

  for (int i = 0; i < REPEAT_SIZE; i++) {
    calcGen(nextGen, prevGen);
    drawGen(nextGen);
    unsigned *tmp = prevGen;
    prevGen = nextGen;
    nextGen = tmp;
  }
  return 0;
}