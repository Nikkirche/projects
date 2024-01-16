#include <SFML/Graphics.hpp>
#include "sim.h"
#include <random>
#include <iostream>
namespace details {
sf::RenderWindow window (sf::VideoMode(SIM_X_SIZE, SIM_Y_SIZE), "Simulation");
sf::Image image;
sf::Texture tex;
sf::Sprite sprite;
std::random_device rd;
std::mt19937_64 gen(rd());

std::uniform_int_distribution<int> dis;
}
extern void simSetPixel(long long  int x, long long  int y, long long  int argb) {
  details::image.setPixel(x, y, sf::Color(argb));
}
extern void simFlush() {
  details::window.clear();
  details::tex.loadFromImage(details::image);
  details::sprite.setTexture(details::tex);
  details::window.draw(details::sprite);
  sf::sleep(sf::seconds(0.1));
  details::window.display();

}

extern long long int simRand() {
  auto r = details::dis(details::gen);
  return r;
}

extern long long int simAbs(long long  int a) {
  return abs(a);
}
extern void init() {
  details::image.create(SIM_X_SIZE, SIM_Y_SIZE);

}