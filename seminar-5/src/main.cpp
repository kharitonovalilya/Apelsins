#include <notes.h>

int main() {
  std::vector<Note> notes;
  std::unordered_map<std::string, std::vector<int>> tagIndex;
  std::stack<int> deletedIds;

  // Добавление заметок
  addNote(notes, tagIndex, deletedIds, "Купить молоко", {"покупки", "срочно"});
  addNote(notes, tagIndex, deletedIds, "Позвонить маме", {"семья", "срочно"});
  addNote(notes, tagIndex, deletedIds, "Написать отчёт", {"работа"});
  addNote(notes, tagIndex, deletedIds, "Записаться к врачу", {"здоровье"});

  std::cout << "=== Все заметки ===" << std::endl;
  printAllNotes(notes);

  // Поиск по тегу
  std::cout << "\n=== Заметки с тегом #срочно ===" << std::endl;
  auto urgent = findNotesByTag(notes, tagIndex, "срочно");
  for (const auto &note : urgent) {
    printNote(note);
  }

  // Статистика
  std::cout << "\n=== Статистика тегов ===" << std::endl;
  auto stats = getTagStats(tagIndex);
  for (const auto &[tag, count] : stats) {
    std::cout << "#" << tag << ": " << count << " заметок" << std::endl;
  }

  // Удаление
  deleteNote(notes, tagIndex, deletedIds, 2);
  std::cout << "\n=== После удаления ID=2 ===" << std::endl;
  printAllNotes(notes);

  return 0;
}