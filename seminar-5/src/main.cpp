#include <notes.h>
#include <print_note.h>
#include <statistics.h>

int main() {
  int nextId = 0;
  std::vector<Note> notes;
  std::unordered_map<std::string, std::vector<int>> tagIndex;
  std::stack<int> deletedIds;

  // Добавление заметок
  addNote(notes, tagIndex, deletedIds, nextId, "Купить молоко",
          {"покупки", "срочно"});
  addNote(notes, tagIndex, deletedIds, nextId, "Позвонить маме",
          {"семья", "срочно"});
  addNote(notes, tagIndex, deletedIds, nextId, "Написать отчёт", {"работа"});
  addNote(notes, tagIndex, deletedIds, nextId, "Записаться к врачу",
          {"здоровье"});

  std::cout << "=== Все заметки ===" << std::endl;
  printAllNotes(notes);

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