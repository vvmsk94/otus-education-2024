#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Octets {
  int first;
  int second;
  int third;
  int fourth;
};

int main() {
  std::cout << "Enter count IP addresses!\n";
  int count = 0;
  std::string str;
  std::vector<std::string> vStr;
  int pointsIndex[3]{
      0,
  };
  Octets octets;
  std::vector<Octets> OctVec;
  int status = 0;
  std::cin >> count;
  std::cout << "Input " << count << " ip addresses" << std::endl;
  std::cout << "To break enter ip input b" << std::endl;

  while (count) {
    std::cin >> str;
    str = str.substr(0, str.find_first_of('\t'));
    count--;
    if (str.at(0) != 'b')
      vStr.push_back(str);
    if (str.at(0) == 'b')
      break;
  }
  std::sort(vStr.begin(), vStr.end());
  std::reverse(vStr.begin(), vStr.end());

  for (auto el : vStr) {
    int ii = 0;
    for (int i = 0; i < el.size(); i++) {
      if (el[i] == '.') {
        pointsIndex[ii] = i;
        ii++;
        if (ii > 2)
          break;
      }
    }
    octets.first = atoi(el.substr(0, pointsIndex[0]).c_str());
    octets.second = atoi(el.substr(pointsIndex[0] + 1, pointsIndex[1]).c_str());
    octets.third = atoi(el.substr(pointsIndex[1] + 1, pointsIndex[2]).c_str());
    octets.fourth = atoi(el.substr(pointsIndex[2] + 1, el.size()).c_str());

    OctVec.push_back(octets);

    std::cout << octets.first << "." << octets.second << "." << octets.third
              << "." << octets.fourth << std::endl;
  }

  std::cout << '\n' << '\n';
  std::cout << "You can filtered this ip-addresses" << std::endl;
  std::cout << "Enter 1 to filter by first byte" << std::endl;
  std::cout << "Enter 2 to filter by first and second byte" << std::endl;
  std::cout << "Enter 3 to filter by any byte" << std::endl;
  int choose = 0;
  int command[2];
  std::cin >> choose;
  switch (choose) {
  case 1:
    std::cin >> command[0];
    for (auto el : OctVec) {
      if (el.first == command[0]) {
        status = 1;
        std::cout << el.first << "." << el.second << "." << el.third << "."
                  << el.fourth << std::endl;
      }
    }
    if (status != 1)
      std::cout << "Doesn't exist" << std::endl;
    break;
  case 2:
    std::cin >> command[0];
    std::cout << "Enter second byte" << std::endl;
    std::cin >> command[1];
    for (auto el : OctVec) {
      if (el.first == command[0] && el.second == command[1]) {
        status = 1;
        std::cout << el.first << "." << el.second << "." << el.third << "."
                  << el.fourth << std::endl;
      }
    }
    if (status != 1)
      std::cout << "Doesn't exist";
    break;
  case 3:
    std::cin >> command[0];
    for (auto el : OctVec) {
      if (el.first == command[0] || el.second == command[0] ||
          el.third == command[0] || el.fourth == command[0]) {
        status = 1;
        std::cout << el.first << "." << el.second << "." << el.third << "."
                  << el.fourth << std::endl;
      }
    }
    if (status != 1)
      std::cout << "Doesn't exist";
    break;
  default:
    break;
  }
}
