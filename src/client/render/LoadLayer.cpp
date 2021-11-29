#include "../render.h"
#include "../render.h"
#include <iostream>

#include <cstdlib>
using namespace std;
using namespace sf;
using namespace state;
namespace render{

bool LoadLayer::loadPersonnage(state::State &state, sf::Texture &textureTileset, sf::Vector2u tile_Size, unsigned int width, unsigned int height)
{
    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    quads.setPrimitiveType(sf::Quads);
    quads.resize(width * height * 4);
    // on remplit le tableau de vertex, avec un quad par tuile
    for (unsigned int i = 0; i < width; ++i)
    {
        // only showing not death characters
        if (state.getPersonnage()[i]->getEtatPerso() != Dead)
        {
            int tileNumber = state.getPersonnage()[i]->getTileCode();
            texture = textureTileset;

            // on en déduit sa position dans la texture du tileset
            int tu = tileNumber % (texture.getSize().x / tile_Size.x);
            int tv = tileNumber / (texture.getSize().x / tile_Size.x);

            // on récupère un pointeur vers le quad à définir dans le tableau de vertex
            sf::Vertex *quad = &quads[i * 4];

            // on définit ses quatre coins
            quad[0].position = sf::Vector2f(state.getPersonnage()[i]->getPosition().getX() * tile_Size.x, state.getPersonnage()[i]->getPosition().getY() * tile_Size.y);
            quad[1].position = sf::Vector2f((state.getPersonnage()[i]->getPosition().getX() + 1) * tile_Size.x, state.getPersonnage()[i]->getPosition().getY() * tileSize.y);
            quad[2].position = sf::Vector2f((state.getPersonnage()[i]->getPosition().getX() + 1) * tile_Size.x, (state.getPersonnage()[i]->getPosition().getY() + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(state.getPersonnage()[i]->getPosition().getX() * tile_Size.x, (state.getPersonnage()[i]->getPosition().getY() + 1) * tile_Size.y);

            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * tile_Size.x, tv * tile_Size.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tile_Size.x, tv * tile_Size.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tile_Size.x, (tv + 1) * tile_Size.y);
            quad[3].texCoords = sf::Vector2f(tu * tile_Size.x, (tv + 1) * tile_Size.y);
            /*
            Color color = (state.getPersonnage()[i]->getPlayerOwner() == 1) ? Color(0,0,255) : Color(255,0,0);
            quad[0].color = color;
            quad[1].color = color;
            quad[2].color = color;
            quad[3].color = color;
             */
        }
    }

    return true;
}

bool LoadLayer::loadTextures (state::State& state, sf::Texture& Tile_texture, sf::Vector2u tile_Size, unsigned int width, unsigned int height)
{
    texture = Tile_texture;

    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    quads.setPrimitiveType(sf::Quads);
    quads.resize(width * height * 4);

    // on remplit le tableau de vertex, avec un quad par tuile
    for (unsigned int i = 0; i < state.getMap().size(); ++i)
    {
        for (unsigned int j = 0; j < state.getMap()[0].size(); j++)
        {
            // get the current tile number
            int tileNumber = state.getMap()[i][j]->getTileCode();
            // on en déduit sa position dans la texture du tileset
            int tu = tileNumber % (texture.getSize().x / tile_Size.x);
            int tv = tileNumber / (texture.getSize().x / tile_Size.x);

            // on récupère un pointeur vers le quad à définir dans le tableau de vertex
            sf::Vertex *quad = &quads[(i + j * width)*4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(j * tile_Size.x, i * tile_Size.y);
            quad[1].position = sf::Vector2f((j + 1) * tile_Size.x, i * tile_Size.y);
            quad[2].position = sf::Vector2f((j + 1) * tile_Size.x, (i + 1) * tile_Size.y);
            quad[3].position = sf::Vector2f(j * tile_Size.x, (i + 1) * tile_Size.y);

                        // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tile_Size.x, tv * tile_Size.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tile_Size.x, tv * tile_Size.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tile_Size.x, (tv + 1) * tile_Size.y);
            quad[3].texCoords = sf::Vector2f(tu * tile_Size.x, (tv + 1) * tile_Size.y);
             
        }
    }
    return true;
}
      

void LoadLayer::draw (sf::RenderTarget& target, sf::RenderStates states){
    {
        // apply the transform
        states.transform *= Transform();

        // apply the tileset texture
        states.texture = &texture;

        // draw the vertex array
        target.draw(quads, states);
    }

}

};
