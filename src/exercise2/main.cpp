#include <iostream>
#include <string>

template <class T>
void ignore_line(std::basic_istream<T>& i = std::cin) {
  i.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void foo() {}

void help() {
  std::cout << "Welcome aboard! What is your command?" << std::endl
            << " 1 - Clean the decks" << std::endl
            << " 2 - Full speed ahead" << std::endl
            << " 3 - Stop" << std::endl
            << " 100, Ctrl-C, Ctrl-D - Exit progam" << std::endl
            << " ?, h - Print this message" << std::endl
            << std::endl;
}

void ignore_input_line() {
  std::cin.clear();
  ignore_line(std::cin);
}

int main() {
  int command;

  help();

  while (true) {
    std::cout << "Enter command: ";

    if (!(std::cin >> command) || command < 1 || (command > 3 && command != 100)) {
      if (std::cin.eof()) {
        std::cout << std::endl;
        break;
      }

      if (std::cin.fail()) {
        std::string line;
        std::cin.clear();

        if (std::getline(std::cin, line) && (line == "?" || line == "h" || line == "H")) {
          help();
          continue;
        }
      }

      ignore_input_line();
      std::cerr << "Invalid command." << std::endl;

      continue;
    }

    bool stop = false;

    switch (command) {
      case 1:
        std::cout << "Clean the decks!" << std::endl;
        break;
      case 2:
        std::cout << "Full speed ahead!" << std::endl;
        break;
      case 3:
        std::cout << "Stop!" << std::endl;
        break;
      case 100:
        stop = true;
        break;
      default:
        std::logic_error("Unimplemented command.");
    }

    if (stop) {
      std::cout << "Get off my ship!" << std::endl;
      break;
    }
  };

  return 0;
}
