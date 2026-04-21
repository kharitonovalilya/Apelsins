#ifndef MEDIAFILE_H
#define MEDIAFILE_H

#include <string>

class MediaFile {
public:
  virtual ~MediaFile() {}
  virtual void play() = 0;
  virtual void pause() = 0;
  virtual int getDuration() const = 0;
  virtual std::string getInfo() const = 0;
};

#endif