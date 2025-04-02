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
    
    void printSingleShape(const Shapes &shape) {
        std:: cout << shape.name << std:: endl;
        std:: cout << "---------" << std:: endl;
    
        std:: cout << "Shapes Coordinates: ";
        for (const auto &pair : shape.coordinates) {
            std:: cout << "(" << pair.first << "," << pair.second << ")";
        }
        std:: cout << std:: endl;

        int maxX = 0, maxY = 0;
        int minX = 0, minY = 0;
        for (const auto &coordinate : shape.coordinates) {
            if (coordinate.first > maxX) maxX = coordinate.first;
            if (coordinate.second > maxY) maxY = coordinate.second;
            if (coordinate.first < minX) minX = coordinate.first;
            if (coordinate.second < minY) minY = coordinate.second;
        }

        for (int y = minY; y < maxY; ++y) {
            for (int x = minX; x < maxX; ++x) {
                bool found = false;
                for (const auto &coord : shape.coordinates) {
                    if (coord.first == x && coord.second == y) {
                        found = true;
                        break;
                    }
                }
                std:: cout << (found ? "X" : " ");
            }
            std:: cout << std:: endl;
        }
        std:: cout << std:: endl;
    }

    Shapes flipShapeHorizontal() const {
        std:: string flippedShapeName = this->name;
        std:: vector<std:: pair <int,int>> flippedCoordinates;

        int maxX = this->coordinates[0].first;
        int minX = this->coordinates[0].first;
        for (const auto &coord : this->coordinates) {
            if (coord.first > maxX) maxX = coord.first;
            if (coord.first < minX) minX = coord.first;
        }

        for (const auto &pair : this->coordinates) {
            int newX = maxX - pair.first;
            flippedCoordinates.push_back({newX, pair.second});
        }
        return Shapes(flippedShapeName, flippedCoordinates);
    }

    Shapes flipShapeVertical() const {
        std:: string flippedShapeName = this->name;
        std:: vector<std:: pair<int,int>> flippedCoordinates;

        int maxY = this->coordinates[0].second;
        int minY = this->coordinates[0].second;

        for (const auto &coord : this->coordinates) {
            if (coord.second > maxY) maxY = coord.first;
            if (coord.second < minY) minY = coord.first;
        }

        for (const auto &pair : this->coordinates) {
            int newY = maxY - pair.second;
            flippedCoordinates.push_back({pair.first, newY});
        }
        return Shapes(flippedShapeName, flippedCoordinates);
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
        std:: vector<std::vector<int>> boardSize;

        // BoardGame() : boardSize() {std:: cout << "No Size passed for the game" << std:: endl;}
        // BoardGame(const std:: vector<std::vector<int>> &passedSize) : boardSize(passedSize) {}

        std:: vector<std:: vector<int>> initailizeMap() {
            std:: vector<std:: vector<int>> gameMap (20, std:: vector<int>(20, 0));

            return gameMap;
        }

        void printMap (BoardGame &gameMap) {
            std:: vector<std::vector<int>> printableMap = this->initailizeMap();

            for (const auto row : printableMap) {
                for (const auto element : row) {
                    std:: cout << element << " ";
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

            std:: vector<std:: pair<int,int>> shapesCoordinates = shape.coordinates;

            for ( auto &pair : shapesCoordinates) { // add the x and y coordinates to the corrdinates of the Shapes object that was passed
                pair.first += xCoordinate;
                pair.second += yCoordinate;
            }

            for (auto &pair : shapesCoordinates) {
                if (pair.first < 0 || pair.second >= 20 || pair.second < 0 || pair.second >= 20) {
                    std:: cerr << "One or more x/y coordinates is out of bounds" << std:: endl;
                    std:: cerr << "Cant place the piece at desired coordinate" << std:: endl;
                    return
                }
            }

            for (auto &pair : shapesCoordinates) {
                if (gameMap[pair.first][pair.second] == 0) {
                    gameMap[pair.first][pair.second] = currentPlayer;
                }
            }

        }
};


// class BoardGameManager {
//     protected:
//         std:: vector<std:: vector<int>> boardSize;
//         BoardGameManager() {
//             BoardGame dummyBoardGame;
//             boardSize = dummyBoardGame;
//         }
// };



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

int main() {
    BoardGame board;
    board.initailizeMap();
    board.printMap(board);

    std:: cout << std:: endl;
    std:: cout << std:: endl;


    const auto &shapeMap = ShapesManager::getInstance().getShapeMap();

    Shapes fShape = shapeMap.at("F Shape");

    // // fShape.printSingleShape(fShape);

    // // fShape = fShape.rotated90();

    // // fShape.printSingleShape(fShape);

    // // fShape = fShape.rotated90();

    // // fShape.printSingleShape(fShape);



    // // Shapes HorizontalNShape = shapeMap.at("N Shape");

    // // HorizontalNShape.printSingleShape(HorizontalNShape);
    
    // // HorizontalNShape = HorizontalNShape.flipShapeHorizontal();

    // // HorizontalNShape.printSingleShape(HorizontalNShape);


    // // Shapes VerticalNShape = shapeMap.at("N Shape");

    // // VerticalNShape.printSingleShape(VerticalNShape);
    
    // // VerticalNShape = VerticalNShape.flipShapeVertical();

    // // VerticalNShape.printSingleShape(VerticalNShape);
}