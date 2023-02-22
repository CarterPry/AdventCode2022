#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream input("input.txt");
  std::string line;
  std::vector<int> calories;
  int total = 0;

  while (std::getline(input, line)) {
    if (!line.empty()) {
      int calorie = std::stoi(line);
      total += calorie;
      calories.push_back(calorie);
    } else {
      int elf_total = 0;
      for (int calorie : calories) {
        elf_total += calorie;
      }
      if (elf_total > total) {
        total = elf_total;
      }
      calories.clear();
    }
  }

  int elf_total = 0;
  for (int calorie : calories) {
    elf_total += calorie;
  }
  if (elf_total > total) {
    total = elf_total;
  }

  std::cout << "The Elf carrying the most Calories is carrying " << total
            << " Calories." << std::endl;

  return 0;
}
