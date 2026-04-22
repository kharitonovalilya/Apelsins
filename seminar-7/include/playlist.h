#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "mediafile.h"
#include <vector>

class Playlist {
private:
  std::vector<MediaFile *> items;

public:
  Playlist();
  ~Playlist();
  void addMedia(MediaFile *media);
  void playAll();
  void printPlaylist();
  int size();
};

#endif