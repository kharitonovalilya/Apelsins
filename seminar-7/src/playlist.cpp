#include "playlist.h"
#include <iostream>

Playlist::Playlist() {}

Playlist::~Playlist() {
  for (MediaFile *file : items) {
    delete file;
  }
}

void Playlist::addMedia(MediaFile *media) { items.push_back(media); }

void Playlist::playAll() {
  std::cout << "\n~~~ Воспроизведение ~~~\n";
  for (MediaFile *file : items) {
    file->play();
    file->pause();
    std::cout << "~~~\n";
  }
  std::cout << "~~~ Конец воспроизведения ~~~\n";
}

void Playlist::printPlaylist() {
  std::cout << "\n~~~ Плейлист ~~~\n";
  for (int i = 0; i < items.size(); i++) {
    std::cout << (i + 1) << ". " << items[i]->getInfo() << "\n";
  }
  std::cout << "~~~~~~~~~~~~~~~~~\n";
}

int Playlist::size() { return items.size(); }