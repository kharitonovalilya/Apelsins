#include "audiotrack.h"
#include "playlist.h"
#include "podcast_episode.h"
#include "videoclip.h"
#include <iostream>
#include <memory>

int main() {
  Playlist playlist;

  playlist.addMedia(new AudioTrack("Bohemian Rhapsody", "Queen", 354, 44100));
  playlist.addMedia(
      new AudioTrack("Blinding Lights", "The Weeknd", 200, 48000));
  playlist.addMedia(new VideoClip("Never Gonna Give You Up", "1920x1080", 217));
  playlist.addMedia(new VideoClip("Bad Guy", "1280x720", 193));
  playlist.addMedia(
      new PodcastEpisode("The Art of Code", "Jane Doe", 42, 2700));
  playlist.addMedia(
      new PodcastEpisode("Design Patterns", "John Smith", 15, 1850));

  std::cout << "=== Playlist summary ===" << std::endl;
  playlist.printPlaylist();

  std::cout << "\n=== Playing all ===" << std::endl;
  playlist.playAll();

  return 0;
}