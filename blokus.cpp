#include <iostream>
#include <vector>
#include <map>
#include <conio.h>
#include <windows.h>
#undef max
#undef min

class Shapes { // class Shapes
    public:
        std:: string name; // enter shapes name
        std:: vector<std:: pair<int,int>> coordinates; // the coordinates of the shape

        Shapes() : name(""), coordinates() {} // initalizes that to no name and no coordinate if nothing is given

        Shapes( const std:: string &shapeName, // we use pass by reference for shape name
                const std:: vector<std:: pair<int,int>> &shapeCoordinates) // we use pass by reference for shape coordinate
                : name(shapeName), coordinates(shapeCoordinates) {} // pass those values in to the current Shape.

        Shapes rotated90() const {
            std:: string rotatedName = this->name + " Rotated 90 degrees"; //references tha name within the current Shape
            std:: vector<std::pair<int,int>> rotatedCoordinates; //creates a new vector of pairs to store values in
            int minX = this->coordinates[0].first, minY = this->coordinates[0].second; // sets the current minX and minY to the first pair of coordinates within the vector of pairs

            for(const auto &pair : this->coordinates) { //cycle through the orifinal pairs
                int xCoordniate = pair.second; // swap the y to x
                int yCoordniate = pair.first; // swap the x to y 
                rotatedCoordinates.push_back({xCoordniate, yCoordniate}); // push those new non normalized coordinates in the rotaed coordinates
            }
            if(!rotatedCoordinates.empty()) { // if the vector of pairs is not empty continue
                int minX = rotatedCoordinates[0].first; // set minX to first pairs X and sets minY to fisst pairs Y within rotaedCoordinates
                int minY = rotatedCoordinates[0].second;

                for (const auto &pair : rotatedCoordinates) { // cycle through rotaedCoordinates to find the smallest X and Y values
                    if(pair.first < minX) minX = pair.first;
                    if(pair.second < minY) minY = pair.second;
                }

                for(auto &pair : rotatedCoordinates) { // cycle through the vector of pairs again and subtract the minX and minY from the nonnormalized values to make them normalized
                    pair.first -= minX;
                    pair.second -= minY;
                }
            }
            return Shapes(rotatedName, rotatedCoordinates); //return the new name and rotated coordinates
        }
        
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
        shape["N Shape"] = Shapes("N Shape", std:: vector<std:: pair<int,int>>{{0,0},{1,0},{1,1},{2,1},{3,1}});
        shape["W Shape"] = Shapes("W Shape", std:: vector<std:: pair<int,int>>{{0,0},{1,0},{1,1},{2,1},{2,2}});
        shape["F Shape"] = Shapes("F Shape", std:: vector<std::pair<int,int>>{{1,1},{0,1},{1,0},{1,2},{2,2}});
        
        return shape;
    }

    void printAllShapes () {

        std:: map<std:: string, Shapes> shapes = this->initailizeShapes(); //everytime we call print shape we reinitalize all shapes then cycle through them within the function

        for (const auto &pair : shapes) { // for each pair in shapes ex: "Name", coordiante
            const std:: string &shapeName = pair.first; // current shapes name
            const Shapes &shape = pair.second; // reference a shape for the current Shape object within the shapes we passed in the function
            std:: cout << std:: endl;
    
            // we are trying to find the largest x and y coordinate of the shape slist of coordinates
            int maxX = 0, maxY = 0; // we get both maxes to 0
            int minX = 0, minY = 0; // we get both mins to 0
            for (const auto &coordinate : shape.coordinates) { // uisng the referenced shape above we loop through the current shapes list of coordinates
                if (coordinate.first > maxX) maxX = coordinate.first; //checks if the current x coordinate is greater than maxX, if it is we update maxX
                if (coordinate.second > maxY) maxY = coordinate.second; // checks if the current y coordinate is greates than maxY, if it is we update maxY
                if (coordinate.first < minX) minX = coordinate.first; // checks if the current x coordinate is less than minX, if it is we update minX to that value
                if (coordinate.second < minY) minY = coordinate.second; // checks if the current y coordinate is less than minY, if it is we update minY to that value
            }
    
            std:: cout << shapeName << std:: endl;
            std:: cout <<"---------";
            std:: cout<< std:: endl;
            // for this two for loops we are essentail checking if a coordinate exists within the coordinates in the current shape
            for (int y = minY; y <= maxY; ++y) { // we loop from the smallest y value to largest, this is the rows
                for (int x = minX; x <= maxX; ++x) { // we loop from the smallest x value to larges, this is the columns
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
    
    void printSingleShape(const Shapes &shape) { // passes instance of Shapes Onject
        std:: cout << shape.name << std:: endl; // prints shapes name
        std:: cout << "---------" << std:: endl;
    
        std:: cout << "Shapes Coordinates: ";
        for (const auto &pair : shape.coordinates) {
            std:: cout << "(" << pair.first << "," << pair.second << ")"; // prints all pairs of x and y within the vector of coordinates
        }
        std:: cout << std:: endl;

        //setting the min and max x and y values to 0
        int maxX = 0, maxY = 0;
        int minX = 0, minY = 0;
        for (const auto &coordinate : shape.coordinates) { // find the smallest x and y values within all pairs in the vector
            if (coordinate.first > maxX) maxX = coordinate.first;
            if (coordinate.second > maxY) maxY = coordinate.second;
            if (coordinate.first < minX) minX = coordinate.first;
            if (coordinate.second < minY) minY = coordinate.second;
        }

        for (int y = minY; y < maxY; ++y) { // y is for the row, goes from smallest y to largest y
            for (int x = minX; x < maxX; ++x) { //x is for the columns, goes from smallest x to largest x
                bool found = false; // temp bool to 
                for (const auto &coord : shape.coordinates) { // cycles through all pairs in the vector
                    if (coord.first == x && coord.second == y) { // if the x in coord and y in coord are equal to the x and y within the loops
                        found = true; // we found a match and set found to true 
                        break; // break out of the loop
                    }
                }
                std:: cout << (found ? "X" : " "); // if found it true we print X else a space
            }
            std:: cout << std:: endl; // end line for the next line in the shape
        }
        std:: cout << std:: endl; // end line for the complete shape
    }

    Shapes flipShapeHorizontal() const {
        std:: string flippedShapeName = this->name; // get the shapes name
        std:: vector<std:: pair <int,int>> flippedCoordinates; // creates new vector of pairs to hold flipped coordinates

        int maxX = this->coordinates[0].first; //initalizes maxX to the shapes first pair x value
        for (const auto &coord : this->coordinates) { // for loop to find the smallest and largest x values within all pairs
            if (coord.first > maxX) maxX = coord.first; // if cuurent x value in pair is greater then previous maxX swap the values
        }

        for (const auto &pair : this->coordinates) { // cycles through the pairs in vector again
            int newX = maxX - pair.first; // new x value is equal to the cuurent maxX - current x value in the pair
            flippedCoordinates.push_back({newX, pair.second}); // push the newX and same y to the vector of pairs in flippedCoordinates
        }
        return Shapes(flippedShapeName, flippedCoordinates); // returns the flipped coordinates
    }

    Shapes flipShapeVertical() const {
        std:: string flippedShapeName = this->name; // gets the shapes name
        std:: vector<std:: pair<int,int>> flippedCoordinates; // creates new vector of pairs to hold flipped coordinates

        int maxY = this->coordinates[0].second; // sets the maxY to the first y value in the the first pair of the shapes coordinates
        for (const auto &coord : this->coordinates) { // for each loop to find largest Y value in all pairs
            if (coord.second > maxY) maxY = coord.first; // changes maxY to another y value if its larger
        }

        for (const auto &pair : this->coordinates) { // cycles through pairs again
            int newY = maxY - pair.second; // newY is equal to the maxY - current y in the pair
            flippedCoordinates.push_back({pair.first, newY}); // pushes back the original x and newY for all pairs
        }
        return Shapes(flippedShapeName, flippedCoordinates); // returns the flipped coordinates
    }
};


class ShapesManager{
    protected: // Only this class will be able to access these constructors
        std:: map<std:: string, Shapes> shapeMap; //create a map of string and Shapes called shape map. This is to store our initalized shapes
        ShapesManager() { // Private constructor for the singleton
            Shapes dummyShape; // creates an instance of Shapes called dummyShapes
            shapeMap = dummyShape.initailizeShapes(); // we pass the initalized map of shapes from dummyShape to shapeMap
        }

        ShapesManager(const ShapesManager&) = delete; // this is a copy contructor. But it is saying is we try to copy ex: ShapesManger a = b, delete the copy constructor
        ShapesManager &operator= (const ShapesManager&) = delete; // // this is a assignment constructor. We are saying is we want to assign ex: a = b of type ShapesManager, you cant and deletes that process from happeing

    public:
        static ShapesManager& getInstance() { // Statis function that only returns the one and only instance created it can only be caalled without an object ex: ShapesManager &manager = ShapesManage::getInstance();
            static ShapesManager instance; // Creates a static (single) instance of Shapes Manager within the fucntion. It is created once called and is resued everytime.
            return instance; //returns a refernece of the instance of ShapesManager
        }

        const std:: map<std:: string, Shapes> &getShapeMap() const { //creates a map of string and Shapes called shapeMap. This is read only and constant so we cant change it
            return shapeMap;
        }
};


class BoardGame {
    public:
        std:: vector<std::vector<int>> boardSize; // creats a vecotr of vector of ints call boardSize

        BoardGame() { // constructor to initalize the boardSize
            boardSize = initailizeMap(); // sets boardSize to initalizeMap() function
        }

        std:: vector<std:: vector<int>> initailizeMap() { // function to create a vector of vector of ints called initalizeMap
            std:: vector<std:: vector<int>> gameMap (20, std:: vector<int>(20, 0)); //creates a 20x20 map and sets all values to 0

            return gameMap; // return the map
        }

        void printMap () { // print map fucntion
            for (const auto row : boardSize) { // gets the current row
                for (const auto element : row) { // cycles through all elements in that row (20)
                    // if and else statments for players current number to print different colored shapes
                    if (element == 1) { 
                        std:: cout << "\033[31m" << element << "\033[0m" << " ";
                    } else if (element == 2) {
                        std:: cout << "\033[32m" << element << "\033[0m" << " ";
                    } else if (element == 3) {
                        std:: cout << "\033[33m" << element << "\033[0m" << " ";
                    } else if (element == 4) {
                        std:: cout << "\033[34m" << element << "\033[0m" << " ";
                    } else {
                        std:: cout << element << " ";
                    }
                }
                std:: cout << std:: endl;
            }
        }

        void placePiece(Shapes &shape, int xCoordinate, int yCoordinate, int currentPlayer) { //pasisng the x and y coordinates of where the user wants to place the shape, passing Shapes object, alson with the name of the shape to find it and the players numebr
            if (xCoordinate < 0 || xCoordinate >= 20 || yCoordinate < 0 || yCoordinate >= 20) { // checks the bounds of the board to see if the x and y values inputed are within the games boundries
                std:: cerr << "Invalid coordinate" << std:: endl; // 2 error messeges in case user does input outside of the boundry
                std:: cerr << "X and Y coordinate must be within the 20x20 grid square" << std:: endl;
                return;
            }

            std:: vector<std:: pair<int,int>> shapesCoordinates = shape.coordinates; // creates a new vector of pairs called shapes coordinates and sets the passes shapes coordinates to it

            for ( auto &pair : shapesCoordinates) { // add the x and y coordinates of where the user wants to place the piece to all x and y coordinates of all pairs in the the shapes coordinates
                pair.first += xCoordinate;
                pair.second += yCoordinate;
            }

            for (auto &pair : shapesCoordinates) { // boundry checker to see if the new chapes coordinates are in bounds of the 20x20 map
                if (pair.first < 0 || pair.first >= 20 || pair.second < 0 || pair.second >= 20) {
                    std:: cerr << shape.name << " cannot be placed. One or more x/y coordinates are out of bounds" << std:: endl;
                    std:: cerr << "Cant place the piece at desired coordinate" << std:: endl;
                    std:: cout << std:: endl;
                    return;
                } else if (boardSize[pair.first][pair.second] == 0) { // hoenstly forgot what this line does

                } else {
                    std:: cerr << "A cell within the coordinates is taken or shape is out of bounds" << std:: endl;
                    std:: cout << std:: endl;
                    return;
                }
            }

            // finally if the shpes coordinates are within the bounds we can place it
            for(auto &pair : shapesCoordinates) { // cycles through the pairs of coodinates
                boardSize[pair.first][pair.second] = currentPlayer; // the board at the current x and y value coordniates is equal to the players number
            }
            std:: cout << shape.name << " has been placed at " << "(" << xCoordinate << "," << yCoordinate << ")" << std:: endl; // checker messege to see that piece has been placed
            std:: cout << std:: endl;
        }
};


int main() {
    BoardGame board;
    board.initailizeMap();

    auto shapesMap = ShapesManager::getInstance().getShapeMap();
    Shapes single = shapesMap.at("Single");
    Shapes nShape = shapesMap.at("N Shape");
    Shapes bigTShape = shapesMap.at("Big T");
    bigTShape = bigTShape.rotated90();
    Shapes pShape = shapesMap.at("P Shape");
    Shapes square = shapesMap.at("Square");

    board.placePiece(single, 0,0,1);
    board.placePiece(square, 18,0,2);
    board.placePiece(single, 0,19,3);
    board.placePiece(single, 19,19,4);

    // board.placePiece(nShape, 19,0,2);

    // board.placePiece(bigTShape, 0,19, 3);

    // board.placePiece(pShape, 19, 19, 4);

    board.printMap();
}