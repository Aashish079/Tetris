#include <SFML/Graphics.hpp>
#include "asset_manager.hpp"

namespace tetris
{
    void AssetManager::loadTexture(std::string name, std::string fileName)
    {
        sf::Texture tex;
        if (tex.loadFromFile(fileName))
        {
            _textures[name] = tex;
        }
    }

    sf::Texture &AssetManager::getTexture(std::string name)
    {
        return _textures.at(name);
    }

    void AssetManager::loadFont(std::string name, std::string fileName)
    {
        sf::Font font;
        if (font.loadFromFile(fileName))
        {
            _fonts[name] = font;
        }
    }

    sf::Font &AssetManager::getFont(std::string name)
    {
        return _fonts.at(name);
    }

    void AssetManager::loadBuffer(std::string name, std::string fileName)
    {
        sf::SoundBuffer buffer;
        if (buffer.loadFromFile(fileName))
        {
            _buffers[name] = buffer;
        }

    }

    sf::SoundBuffer& AssetManager::getBuffer(std::string name)
    {
        return _buffers.at(name);
    }
}
