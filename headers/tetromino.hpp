#pragma once
#include <SFML/Graphics.hpp>
#include "mino.hpp"
#include "keyboard.hpp"

#include <iostream>
#include <array>

class Tetromino
{
    private:
    std::vector<Mino> mino;
    TilesType Type;
    short int nRotation = 0;
	Keyboard keyboard;
	bool onFloor = false;
	
	sf::Vector2f tPos;
	
	
	
	
	// ------------Working*
	//Mino test[4];
	//std::array<Mino, 4> test;
	// ------------
    
    public:
    Tetromino(TilesType Type);
    Tetromino(TilesType Type, sf::Vector2f Position);
    Tetromino(const Tetromino& tetromino);
    
    void updateMinoPosition(sf::RenderWindow *window);
    void setPosition(sf::Vector2f newPosition);
    void setEachMinoPosition(); // Private?
    std::vector<sf::FloatRect> getMinosBounds();
	
    bool isOnFloor() const { return onFloor; }
	
    void handleMovement(Directions d, std::vector<Mino>& Minos); // d = direction
    bool canMove(std::vector<Mino>& Minos);
	void checkInput(const std::vector<Tetromino*>& t); // NOTE(AloneTheKing): Pass as reference to not make a copy maybe. __DELETE__
	void checkInput(std::vector<Mino>& t); // NOTE(AloneTheKing): Pass as reference to not make a copy maybe.
	
	std::vector<Mino> getMino() const { return mino; };
	
    //-------- Rotate Tetromino
    void rotateTetromino();
	
	//-------- Update
	void Update(std::vector<Mino>& Minos);
	
    
    private:
    void updateRotationPosition();
    void setTetrominoGeometry();
	void setMinoType();
	
	//----------
	public:
	Tetromino& operator=(const Tetromino& t);
	//----------
};