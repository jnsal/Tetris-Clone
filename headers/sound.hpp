#ifndef SOUND_HPP
#define SOUND_HPP
#include <SFML/Audio.hpp>
#include <string>
#include <thread>
#include <iostream>
#include "options.hpp"

enum class Sounds
{
    Drop,
    Clean,
    OST
};

class SoundTrack
{
    public:
    SoundTrack(const SoundTrack&) = delete;

    static void play(Sounds sound);
    static void playOST();
    static void stopOST();
    static void setVolume(float value);
    static bool OST_isPlaying();
    static void muteOST();
    static void unmuteOST();
    static std::string getPath(Sounds sound);

    private:
    SoundTrack();
    static float m_volume;
    // NOTE: Create a string class maybe. 
    static sf::Music ost;
    static float ost_volume;
    static bool loop;
    static bool stop;
    static bool q_free;
    static bool mute;

    friend void Options(RenderWindow& window);
    friend class Defaults;
};


#endif 

