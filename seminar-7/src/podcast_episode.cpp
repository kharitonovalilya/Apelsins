#include "podcast_episode.h"
#include <iostream>

PodcastEpisode::PodcastEpisode(const std::string& title, const std::string& host, int episodeNumber, int duration)
    : title(title), host(host), episodeNumber(episodeNumber), duration(duration) {}

void PodcastEpisode::play() {
    std::cout << "Playing podcast: " << title << " (Episode #" << episodeNumber << ") hosted by " << host << std::endl;
}

void PodcastEpisode::pause() {
    std::cout << "Paused podcast: " << title << std::endl;
}

int PodcastEpisode::getDuration() const {
    return duration;
}

std::string PodcastEpisode::getInfo() const {
    return "[Podcast] " + title + " — Ep. " + std::to_string(episodeNumber) + " with " + host + " (" + std::to_string(duration) + " sec)";
}