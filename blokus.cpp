#include <iostream>
#include <vector>
#include <map>

class Shapes { // class Shapes
    public:
        std:: string name; // enter shapes name
        std:: vector<std:: pair<int,int>> coordinates; // the coordinates of the shape

        Shapes() : name(""), coordinates() {} // initalizes that to no name and no coordinate if nothing is given

        Shapes( const std:: string &shapeName, // we use pass by reference for shape name
                const std:: vector<std:: pair<int,int>> &shapeCoordinates) // we use pass by reference for shape coordinate
                : name(shapeName), coordinates(shapeCoordinates) {} // pass those values in to the current Shape.

};

std:: map<std:: string, Shapes> initailizeShapes() { // creates an initalizer for the shapes, we will return a map of string and type Shapes.
    std:: map<std:: string, Shapes> shape; // create a map called shape that holds a string name key and a type strig


    //Shapes for the game
    shape["Single"] = Shapes("Single", std::vector<std::pair<int,int>>{{0,0}}); // we make a key in shape called "Single" to be of type Shape with name "Single" and coordinates of 0,0
    shape["Two"] = Shapes("Two", std::vector<std::pair<int,int>>{{0,0}, {1,0}});
    shape["Three"] = Shapes("Three", std::vector<std::pair<int,int>>{{0,0}, {1,0}, {2,0}});
    shape["Square"] = Shapes("Square", std::vector<std::pair<int,int>>{{0,0},{0,1}, {1,0}, {1,1}});
    shape["Short I"] = Shapes("Short I", std::vector<std::pair<int,int>>{{0,0}, {0,1}, {0,2}, {0,3}});
    shape["Long I"] = Shapes("Long I", std::vector<std::pair<int,int>>{{0,0}, {0,1}, {0,2}, {0,3}, {0,4}});
    shape["Big L"] = Shapes("Big L", std::vector<std::pair<int,int>>{{0,0}, {1,0}, {0,1}, {0,2}, {0,3}});
    shape["Short L"] = Shapes("Short L", std:: vector<std:: pair<int,int>>{{0,0}, {1,0}, {0,1}, {0,2}});
    shape["X Shape"] = Shapes("X Shape", std:: vector<std:: pair<int,int>>{{1,0},{0,1},{1,1},{2,1},{1,2}});
    shape["Big T"] = Shapes("Big T", std:: vector<std:: pair<int,int>>{{1,0},{1,1}, {1,2},{0,2}, {2,2}});
    shape["Short T"] = Shapes("Short T", std:: vector<std:: pair<int,int>>{{1,0},{1,1},{0,2},{2,2}});
    shape["U Shape"] = Shapes("U Shape", std:: vector<std:: pair<int,int>>{{0,0}, {1,0}, {2,0}, {0,1}, {2,1}});
    shape["Y Shape"] = Shapes("Y Shape", std:: vector<std:: pair<int,int>>{{0,0},{1,0},{2,0},{3,0},{1,1}});
    shape["V Shape"] = Shapes("V Shape", std:: vector<std:: pair<int,int>>{{0,0},{1,0},{2,0},{2,1},{2,2}});
    shape["Short Z"] = Shapes("Short Z", std:: vector<std:: pair<int,int>>{{0,0},{1,0},{1,1},{2,1}});
    shape["Big Z"] = Shapes("Big Z", std:: vector<std:: pair<int,int>>{{0,0}, {1,0}, {1,1}, {1,2}, {2,2}});
    shape["P Shape"] = Shapes("P Shape", std:: vector<std:: pair<int,int>>{{0,0}, {0,1}, {0,2}, {1,1}, {2,2}});
    shape["Mini L"] = Shapes("Mini L", std:: vector<std:: pair<int,int>>{{0,0},{0,1},{1,0}});
    shape["Big Z"] = Shapes("Big Z", std:: vector<std:: pair<int,int>>{{0,0}, {1,0}, {1,1}, {1,2}, {2,2}});
    shape["N Shape"] = Shapes("N Shape", std:: vector<std:: pair<int,int>>{{0,0},{1,0},{1,0},{2,1},{2,2}});



    return shape;

}

void printShapes (const std:: map<std:: string, Shapes>&shapes) { // we pass a reference value of shapes which is of type map and has a string key and type Shape

    for (const auto &pair : shapes) { // for each pair in shapes ex: "Name", coordiante
        const std:: string& shapeName = pair.first; // current shapes name
        const Shapes &shape = pair.second; // reference a shape for the current Shape object within the shapes we passed in the function
        std:: cout << std:: endl;

        // we are trying to find the largest x and y coordinate of the shape slist of coordinates
        int maxX = 0, maxY = 0; // we wet both maxes to 0
        for (const auto &coordinate : shape.coordinates) { // uisng the referenced shape above we loop through the current shapes list of coordinates
            if (coordinate.first > maxX) maxX = coordinate.first; //checks if the current x coordinate is greater than maxX, if it is we update maxX
            if (coordinate.second > maxY) maxY = coordinate.second; // checks if the current y coordinate is greates than maxY, if it is we update maxY
        }

        std:: cout << shapeName << std:: endl;
        std:: cout <<"---------";
        std:: cout<< std:: endl;
        // for this two for loops we are essentail checking if a coordinate exists within the coordinates in the current shape
        for (int y = 0; y <= maxY; ++y) { // this loops over the rows
            for (int x = 0; x <= maxX; ++x) { // this lops over the columns
                bool found = false; //temp bool to see if the coordinate exits sets it to false
                for (const auto& coord : shape.coordinates) { // coord checks through each of the pairs within the list of pairs in shapes coordinates
                    if (coord.first == x && coord.second == y) { // if the x and y values in the current coordniate matches the x and y we found a pair
                        found = true; // we set found to true
                        break; //break of of this loop
                    }
                }
                std::cout << (found ? "X" : " "); // prints X if true else " " if false
            }
            std::cout << std::endl; // end line for current coorniate
        }
        std:: cout << std::endl; // end line for the next shape

    }
}

std:: vector<std:: vector<int>> gameMap (20, std:: vector<int>(20, 0));

void updateMap(int xCoordinate, int yCoordinate, int playerNumber) {
    if (xCoordinate < 0 || xCoordinate >= 20 || yCoordinate < 0 || yCoordinate >= 20) {
        std:: cout << "Invalid Coordinates" << std:: endl;
        return;
    }

    if (gameMap[yCoordinate][xCoordinate] != 0) {
        std:: cout << "Cell is taken or out of bounds" << std:: endl;
        return;
    }
    gameMap[yCoordinate][xCoordinate] = playerNumber;

   
}

void printMap() {
    for (const auto row : gameMap) {
        for (const auto element : row) {
            std:: cout << element << " ";
        }
        std:: cout << std:: endl;
    }

    std:: cout << std:: endl;
    std:: cout << std:: endl;
}

int main() {
    // int playerCount;
    // std:: cout << "Enter player count: ";
    // std:: cin >> playerCount;

    // while (playerCount < 2 || playerCount > 4) {
    //     std:: cout << "Game must have 2-4 players" << std:: endl;
    //     std:: cout << "Enter player count: ";
    //     std:: cin >> playerCount;
    // }

    std:: map<std:: string, Shapes> shapes = initailizeShapes();

    printShapes(shapes);
}