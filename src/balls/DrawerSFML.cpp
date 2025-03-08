#include "pch.h"
#include "DrawerSFML.h"
#include "GameObject.h"

DrawerSFML::DrawerSFML(HWND hWnd, BYTE* pixels, BITMAPINFOHEADER infoHeader){
    // Create the SFML window using the HWND from the Window
    _sfmlWindow = new sf::RenderWindow(hWnd);

    if (!_texture.create(infoHeader.biWidth, infoHeader.biHeight))
    {
        // erreur...
    }
    _texture.update(pixels);
}
DrawerSFML::~DrawerSFML() {
    if (_sfmlWindow) {
        delete _sfmlWindow;
    }
}

void DrawerSFML::Draw(std::vector<GameObject*> goList) {
    if (!_sfmlWindow) return;
    // Clear the SFML window with a blue color
    Clear();

    // Create GameObject shape
    for (int i = 0; i < goList.size(); i++)
    {
        GameObject* go = goList[i];
        if (go->_shape == Shape::ball) {
            _sprite.setTexture(_texture);
            _sprite.setPosition(sf::Vector2f(go->_posX, go->_posY));

            _sfmlWindow->draw(_sprite);
        }
        else {
            sf::RectangleShape shape;
            shape.setFillColor(sf::Color::Green);
            shape.setSize(sf::Vector2(go->_size, go->_size));
            shape.setPosition(sf::Vector2f(go->_posX, go->_posY));

            //_sfmlWindow->draw(shape);
        }
    }

    // Display the SFML content
    _sfmlWindow->display();
}

void DrawerSFML::Clear() {
    // Clear the SFML window with a blue color
    _sfmlWindow->clear(sf::Color::Blue);
}