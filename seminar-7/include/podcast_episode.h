#ifndef PODCASTEPISODE_H
#define PODCASTEPISODE_H

#include "mediafile.h"
#include <string>

class PodcastEpisode : public MediaFile {
private:
    std::string title;
    std::string host;
    int episodeNumber;
    int duration;

public:
    PodcastEpisode(const std::string& title, const std::string& host, int episodeNumber, int duration);

    void play() override;
    void pause() override;
    int getDuration() const override;
    std::string getInfo() const override;
};

#endif