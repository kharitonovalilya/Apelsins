#ifndef AUDIOTRACK_H
#define AUDIOTRACK_H

#include "mediafile.h"
#include <string>
class AudioTrack : public MediaFile {
private:
  std::string title;
  std::string artist;
  int duration;
  int sampleRate;

public:
  AudioTrack(const std::string &title, const std::string &artist, int duration,
             int sampleRate);
  void play() override;
  void pause() override;
  int getDuration() const override;
  std::string getInfo() const override;
};
#endif