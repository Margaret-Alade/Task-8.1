//
//  main.cpp
//  Task-8.1
//
//  Created by Маргарет  on 02.11.2023.
//

#include <iostream>
#include <string>

class bad_length : public std::exception {
public:
const char* what() const noexcept override { return "Вы ввели слово запретной длины! До свидания";}
};


int function(std::string str, int forbidden_length) {
    int length = static_cast<int>(str.length());
    if (str.length() == forbidden_length) {
        throw bad_length();
    }
    return length;
}

int main() {
    std::string user_str;
    int forbidden_length;
    do {
      std::cout << "Введите запретную длину: ";
      std::cin >> forbidden_length;
      std::cout << '\n';
      std::cout << "Введите слово: ";
      std::cin >> user_str;
      std::cout << '\n';
      try {
          std::cout << "Длина слова \"" << user_str << "\" равна " << function(user_str,forbidden_length) << '\n';
      } catch (const bad_length& e) {
        std::cout << e.what() << '\n';
      }
  } while (user_str.length() != forbidden_length);


    return 0;
}
