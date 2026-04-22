#include "videoclip.h"
#include <iostream>

VideoClip::VideoClip(const std::string &title, const std::string &resolution,
                     int duration)
    : title(title), resolution(resolution), duration(duration) {}

void VideoClip::play() {
  std::cout << "Playing video: " << title << " at " << resolution << std::endl;
}

void VideoClip::pause() { std::cout << "Paused video: " << title << std::endl; }

int VideoClip::getDuration() const { return duration; }

std::string VideoClip::getInfo() const {
  return "[Video] " + title + " — " + resolution + " (" +
         std::to_string(duration) + " sec)";
}