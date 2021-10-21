/* date = October 14th 2021 0:29 pm */
#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "tetromino.hpp"
#include "renderWindow.hpp"
#include <ctime>
#include <random>


short int scoreMultiplier(short int row);
TilesType getRandomTetromino();
void deleteRowAt(std::vector<Mino>& grid, int h);
bool isFullRowAt(const std::vector<Mino>& grid, unsigned short int);
void setGrid(std::array<Mino, 56>& g);

void Tetris(sf::RenderWindow& window);

#endif //GAME_H