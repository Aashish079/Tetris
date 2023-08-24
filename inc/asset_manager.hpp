#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include <map>
#include <SFML/Audio.hpp>

namespace sf
{
    class Texture;
    class Font;
}

namespace tetris
{
    class AssetManager
    {
    public:
        AssetManager() {}
        ~AssetManager() {}

        void loadTexture(std::string name, std::string fileName);
        sf::Texture &getTexture(std::string name);

        void loadFont(std::string name, std::string fileName);
        sf::Font &getFont(std::string name);

        void loadBuffer(std::string name, std::string fileName);
        sf::SoundBuffer &getBuffer(std::string name);

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
        std::map<std::string, sf::SoundBuffer> _buffers;

    };
}

#endif // ASSET_MANAGER_HPP
