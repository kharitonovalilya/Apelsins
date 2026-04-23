#include "audiotrack.h"
#include <iostream>

AudioTrack::AudioTrack(const std::string &title, const std::string &artist,
                       int duration, int sampleRate)
    : title(title), artist(artist), duration(duration), sampleRate(sampleRate) {
}

void AudioTrack::play() {
  std::cout << "Playing audio: " << title << " by " << artist << " at "
            << sampleRate << " Hz" << std::endl;
}

void AudioTrack::pause() {
  std::cout << "Paused track: " << title << std::endl;
}

int AudioTrack::getDuration() const { return duration; }

std::string AudioTrack::getInfo() const {
  return "[Audio] " + title + " — " + artist + "(" + std::to_string(duration) +
         " sec)";
}