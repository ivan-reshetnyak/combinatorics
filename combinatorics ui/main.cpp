#include <string>
#include <iostream>

#include <combinatorics.h>

using namespace combin;
using std::cin;
using std::cout;
using std::endl;
using std::string;

void PrintHelp();

int main( int argc, char **argv ) {
  std::string Command;
  number N, K;

  cout << "Input command! (H for Help)" << endl;
  while (Command != "Q" && Command != "q") {
    cout << "> ";
    cin >> Command;

    if (Command.length() == 1)
      try {
        switch (Command[0]) {
        case 'H':
        case 'h':
          PrintHelp();
          break;
        case 'A':
        case 'a':
          cin >> N >> K;
          cout << "A(" << N << ", " << K << ") = " << Placements(N, K) << endl;
          break;
        case 'U':
        case 'u':
          cin >> N >> K;
          cout << "U(" << N << ", " << K << ") = " << PlacementsRepeat(N, K) << endl;
          break;
        case 'P':
        case 'p':
          cin >> N;
          cout << "P(" << N << ") = " << Permutations(N) << endl;
          break;
        case 'C':
        case 'c':
          cin >> N >> K;
          cout << "C(" << N << ", " << K << ") = " << Combinations(N, K) << endl;
          break;
        case 'S':
        case 's':
          cin >> N >> K;
          cout << "S(" << N << ", " << K << ") = " << Stirling(N, K) << endl;
          break;
        case 'B':
        case 'b':
          cin >> N;
          cout << "B(" << N << ") = " << Bell(N) << endl;
          break;
        case 'Q':
        case 'q':
          break;
        default:
          cout << "Unrecognised command! Type 'H' for more detailed help!" << endl;
        }
      } catch (std::exception) {
        cout << "Error: uint32 overflow" << endl;
      }
    else {
      cout << "All command consist from one letter! Type 'H' for more detailed help!" << endl;
    }
  }
}

void PrintHelp() {
  cout << "Available commands:" << endl
       << "Q: Exit program" << endl
       << "H: Print this help message" << endl
       << "A <n> <k>: Count placements" << endl
       << "U <n> <k>: Count placements with repeats" << endl
       << "P <n>: Count permutations" << endl
       << "C <n> <k>: Count combinations" << endl
       << "S <n> <k>: Count Stirling number" << endl
       << "B <n>: Count Bell number" << endl;
}
