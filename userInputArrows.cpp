#include <iostream>
#include <vector>
#include <conio.h>   // for _getch() — get keypress instantly
#include <windows.h> // for system("cls") — clear the terminal
#undef max // removes the Windows macro that conflicts with std::max
#undef min // removes the Windows macro that conflicts with std::min

void drawMap(const std::vector<std::vector<int>>& map, int px, int py) { // passes the vector of vector of ints and the x and y coordinates that will be passed
    system("cls"); // Clears the terminal aka screen
    for (int y = 0; y < map.size(); ++y) { // loops through the y axis
        for (int x = 0; x < map[0].size(); ++x) { // loops through the x axis
            if (x == px && y == py) std::cout << "X "; // if the current x and y values from the loops equals the px and py values we inputed
            else std::cout << ". "; // print the x else print a space
        }
        std::cout << std:: endl; // end line for the the current row
    }
}

int main() {
    const int width = 20, height = 20; 
    int x = 0, y = 19; // default x and y values for the map. X will be on the bottom left corner of the map

    std::vector<std::vector<int>> gameMap(height, std::vector<int>(width, 0)); // creates the map

    drawMap(gameMap, x, y); // creates an inital state of the map

    while (true) { // while loop to continuasly print the map and new placement of the X
        int ch = _getch(); //_getch comes from the conio.h library, reading users singel input without waiting to press enter, it retuirns 224 a special charater
        if (ch == 224) { // Arrow keys prefix, if the ch entered == 224 or in other words a input form the arrow keys
            int arrow = _getch(); // the the direction of the inputed arrow
            switch (arrow) { // switch case depending on the key pressed
                case 72: y = std::max(0, y - 1); break; // Up (in order to out NOT go out of bounds in the y direction we return 0 if y is out of bounds)
                case 80: y = std::min(height - 1, y + 1); break; // Down (in order to out NOT go out of bounds in the y direction we return 0 if y is out of bounds)
                case 75: x = std::max(0, x - 1); break; // Left
                case 77: x = std::min(width - 1, x + 1); break; // Right
            }
        } else if (ch == 'q' || ch == 'Q') { // entering q break us out the while loop
            break; // game ends
        }

        drawMap(gameMap, x, y); // prints the final coordinates we had on the map
    }

    return 0;
}


// in order to run this you hace to do wnd + R, type cmd and enter
// then enter path of the .exe file, in my case cd C:\Users\elder\OneDrive\Desktop\BlokusGame\BlocusGame\ 
// then run the .exe file in my case userInputArrows.exe