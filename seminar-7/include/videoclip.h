#ifndef VIDEOCLIP_H
#define VIDEOCLIP_H

#include "mediafile.h"
#include <string>

class VideoClip : public MediaFile {
private:
  std::string title;
  std::string resolution;
  int duration;

public:
  VideoClip(const std::string &title, const std::string &resolution,
            int duration);
  void play() override;
  void pause() override;
  int getDuration() const override;
  std::string getInfo() const override;
  ~VideoClip() override = default;
};

#endif