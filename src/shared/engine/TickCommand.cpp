#include "TickCommand.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

namespace engine{
    int TickCommand::Execute(state::Etat& state){
            listePersonnage = state.getPersonnages;
            for(auto perso : listePersonnage){
                perso.setCompteur(perso.getCompteur+perso);
            }
    }
}