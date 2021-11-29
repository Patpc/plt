#include "../state.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;

namespace state{

Position::Position(){
    this->x=0;
    this->y=0;
}

Position::Position(int x, int y){
    this->x=x;
    this->y=y;
}

int Position::getX(){
    return this->x;
}

int Position::getY(){
    return this->y;
}

void Position::setX(int newX){
    this->x = newX;
}

void Position::setY(int newY){
    this->y = newY;
}



};
