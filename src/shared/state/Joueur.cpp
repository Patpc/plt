#include "Joueur.h"
#include <iostream>
namespace state {

void testc(){
    std::cout << "test";
}

Joueur::Joueur (std::string IDPlayer, ID_PlayerType PlayerType){
    this->PlayerType = PlayerType;
    this->IDPlayer = IDPlayer;
    

}

std::vector<Personnage> Joueur::getPersonnage(){
    return Personnages;
    
}

ID_PlayerType Joueur::getPlayerType() const{
    return PlayerType;
    
}

void Joueur::setPlayerType(ID_PlayerType PlayerType){
    PlayerType = PlayerType;
    
}

ID_GameStatus Joueur::getGameStatus() const{
    return GameStatus;
    

}

void Joueur::setGameStatus(ID_GameStatus GameStatus){
    GameStatus = GameStatus;
    
}

}


