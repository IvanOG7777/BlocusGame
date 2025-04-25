#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <conio.h>
#include <windows.h>
#include <limits>
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
        
       static std:: map<std:: string, Shapes> initailizeShapes() { // creates an initalizer for the shapes, we will return a map of string and type Shapes.
        std:: map<std:: string, Shapes> shape; // create a map called shape that holds a string name key and a type strig
        
        //Shapes for the game
        shape["Single"] = Shapes("Single", std::vector<std::pair<int,int>>{{0,0}}); // we make a key in shape called "Single" to be of type Shape with name "Single" and coordinates of 
        shape["Two"] = Shapes("Two", std::vector<std::pair<int,int>>{{0,0}, {1,0}});
        shape["Three"] = Shapes("Three", std::vector<std::pair<int,int>>{{0,0}, {1,0}, {2,0}});
        shape["Square"] = Shapes("Square", std::vector<std::pair<int,int>>{{0,0},{0,1}, {1,0}, {1,1}});
        shape["Short I"] = Shapes("Short I", std::vector<std::pair<int,int>>{{0,0}, {0,1}, {0,2}, {0,3}});
        shape["Long I"] = Shapes("Long I", std::vector<std::pair<int,int>>{{0,0}, {0,1}, {0,2}, {0,3}, {0,4}});
        shape["Big L"] = Shapes("Big L", std::vector<std::pair<int,int>>{{0,0}, {1,0}, {0,1}, {0,2}, {0,3}});
        shape["Short L"] = Shapes("Short L", std:: vector<std:: pair<int,int>>{{0,0}, {1,0}, {0,1}, {0,2}});
        shape["X Shape"] = Shapes("X Shape", std:: vector<std:: pair<int,int>>{{1,1},{1,2},{2,1},{0,2},{1,0}});
        shape["Big T"] = Shapes("Big T", std:: vector<std:: pair<int,int>>{{1,1},{1,2}, {0,2},{2,2}, {1,0}});
        shape["Short T"] = Shapes("Short T", std:: vector<std:: pair<int,int>>{{1,1},{0,1},{2,1},{1,0}});
        shape["U Shape"] = Shapes("U Shape", std:: vector<std:: pair<int,int>>{{0,0}, {1,0}, {2,0}, {0,1}, {2,1}});
        shape["Y Shape"] = Shapes("Y Shape", std:: vector<std:: pair<int,int>>{{0,0},{1,0},{2,0},{3,0},{1,1}});
        shape["V Shape"] = Shapes("V Shape", std:: vector<std:: pair<int,int>>{{0,0},{1,0},{2,0},{2,1},{2,2}});
        shape["Short Z"] = Shapes("Short Z", std:: vector<std:: pair<int,int>>{{0,0},{1,0},{1,1},{2,1}});
        shape["Big Z"] = Shapes("Big Z", std:: vector<std:: pair<int,int>>{{0,0}, {1,0}, {1,1}, {1,2}, {2,2}});
        shape["P Shape"] = Shapes("P Shape", std:: vector<std:: pair<int,int>>{{0,0}, {0,1}, {0,2}, {1,1}, {2,2}});
        shape["Mini L"] = Shapes("Mini L", std:: vector<std:: pair<int,int>>{{0,0},{0,1},{1,0}});
        shape["N Shape"] = Shapes("N Shape", std:: vector<std:: pair<int,int>>{{0,0},{1,0},{1,1},{2,1},{3,1}});
        shape["W Shape"] = Shapes("W Shape", std:: vector<std:: pair<int,int>>{{0,0},{1,0},{1,1},{2,1},{2,2}});
        shape["F Shape"] = Shapes("F Shape", std:: vector<std::pair<int,int>>{{1,1},{0,1},{1,2},{2,2},{1,0}});
        
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

    Shapes rotated90() const {
        std:: string rotatedName = this->name + " Rotated 90 degrees"; //references tha name within the current Shape
        std:: vector<std::pair<int,int>> rotatedCoordinates; //creates a new vector of pairs to store values in

        for(const auto &pair : this->coordinates) { //cycle through the orifinal pairs
            int xCoordniate = pair.second; // swap the y to x
            int yCoordniate = -pair.first; // swap the x to y 
            rotatedCoordinates.push_back({xCoordniate, yCoordniate}); // push those new non normalized coordinates in the rotaed coordinates
        }

        int minX = 0, minY = 0;
        for (const auto &pair : rotatedCoordinates) {
            if (pair.first < minX) minX = pair.first;
            if (pair.second < minY) minY = pair.second;
        }

        if (minX < 0 || minY < 0) {
            for (auto &pair : rotatedCoordinates) {
                pair.first -= minX;
                pair.second -=minY;
            }
        }
        return Shapes(rotatedName, rotatedCoordinates); //return the new name and rotated coordinates
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

        void printMapDynamically(const std::vector<std::vector<int>>& board, const Shapes &shape, int xCoord, int yCoord, int playerNumber) {
             auto tempBoard = board; // creates a temp board

             std:: vector<std:: pair<int,int>> absoluteCoordinates; // vector of pairs to hold absolute coordinates of the shape

             // initalizes the max and min of x and y values for out width check for the current shape
             int maxX = 0, maxY = 0;
             int minX = 0, minY = 0;
             // initializes the shapes width and height to 0
             int shapeWidth = 0, shapeHeight = 0;

             int boardWidth = static_cast<int>(board[0].size()); // gets the board width, 19
             int boardHeight = static_cast<int>(board.size()); // gets the board height 19

             for (auto &pair : shape.coordinates) { // cycles through the pairs to find the smallest x and y values of the all the pairs
                if (pair.first > maxX) maxX = pair.first;
                if (pair.first < minX) minX = pair.first;
                if (pair.second > maxY) maxY = pair.second;
                if (pair.second < minY) minY = pair.second;
             }

             //getting the shapes width and height
             shapeWidth = maxX - minX + 1;
             shapeHeight = maxY - minY + 1;

             //calculates the max x and y off sets based on the boards width - shapes width and boards height - shapes height
             int maxXOffSet = boardWidth - shapeWidth;
             int maxYOffSet = boardHeight - shapeHeight;

             // if statements to adjust the x and y coordinates
             if (xCoord < 0) {
                xCoord = 0;
             } else if (xCoord > maxXOffSet) {
                xCoord = maxXOffSet;
             }

             if (yCoord < 0) {
                yCoord = 0;
             } else if (yCoord > maxYOffSet) {
                yCoord = maxYOffSet;
             }

             for (const auto pair : shape.coordinates) { // for loop to find the absulute coordinates 
                int newX = pair.first + xCoord; //adds the passed x value to the current pairs x valuie
                int newY = pair.second + yCoord; // adds the passed y value to the current pairs y value

                // boundry checker for the coordinates to see if they are within the boundry of the map
                if (newX >= 0 && newX < static_cast<int>(board[0].size()) && // if the newX is NOT negative and if the newX is less than 19 (0-19 index)
                    newY >= 0 && newY < static_cast<int>(board.size())) { // AND if the newY is NOT negative and if the newY is less than 19 (0-19 index)
                        absoluteCoordinates.push_back({newX, newY}); // if conditions above pass, pass the coordinates to the new vector of pairs absolute coordinates
                    }
             }

             for (const auto &pair : absoluteCoordinates) { // goes through the absoluteCoordinates vector of pairs
                tempBoard[pair.second][pair.first] = playerNumber; // sets the values from the coordinates to the temp board and changes it to the players number
             }

             system("cls"); // clear the terminal to prepare it form the next itteration of printing

             // this for loop actually pritns our dynamic movement of the shape
             for (const auto &row : tempBoard) { // goes through each row in the tempboard 
                for (const auto &cell : row) { // cell cell or element within the current row
                    if (cell == 1) { // if the cell or element is equal to the currentPlayers number
                        std::cout << "\033[31m" << cell << "\033[0m" << " "; // we print the cell or element, in this case the players numebr in green
                    } else if (cell == 2) {
                        std:: cout << "\033[32m" << cell << "\033[0m" << " ";
                    } else if (cell == 3) {
                        std:: cout << "\033[33m" << cell << "\033[0m" << " ";
                    } else if (cell == 4) {
                        std:: cout << "\033[34m" << cell << "\033[0m" << " ";
                    } else {
                        std:: cout << cell << " "; // else print a space
                    }
                }
                std:: cout << std:: endl; // end line for the current shape
             }
        }

        bool isPieceDiagonal(Shapes &shape, int xCoordinate, int yCoordinate, int currentPlayer) { // function to check if piece is diagonal to another of the current users pieces, takes in the shape, x and y coordinates and the players number as parameters
            if (xCoordinate < 0 || xCoordinate >= 20 || yCoordinate < 0 || yCoordinate >= 20) { // checks if the shapes coordinates are within the maps boundries
                return false; // if it isnt we return false, cant place the piece
            }

            std:: vector<std:: pair<int,int>> shapesCoordinates = shape.coordinates; // create a new vector of shapescoordinates and pass the shapes coordinates to this so we dont change the original coordinates
            for (auto &pair : shapesCoordinates) { // for each loop that add the current x and y coordinate to all pairs within the shape
                pair.first += xCoordinate; // adding the current x 
                pair.second += yCoordinate; // adding the current y
            }
            for (auto &pair : shapesCoordinates) { // for each loop to then check if the absolute coordinates of the shape are within bounds of the map
                if (pair.first < 0 || pair.first >= 20 || pair.second < 0 || pair.second >= 20) {
                    return false; // if it isnt we return false, cane place the piece
                }
            }
            
            int edgeCounter = 0; // edge counter to count how many edges the current shape is touching
            bool isDiagonal = false; // bool to check if the shape only has one diagonal cell touching the other piece

            for (const auto &pair : shapesCoordinates) { // for each loop to check diagonally of each pair within the shpaes absolutes coordinates
                int x = pair.first;
                int y = pair.second;

                if (x - 1 >= 0 && y - 1 >= 0) { // if the current pairs x - 1 is less than or = to 0 and if the current piars y - 1 >= 0
                    if (boardSize[y - 1][x - 1] == currentPlayer) isDiagonal = true;
                }

                if (x + 1 < static_cast<int>(boardSize[0].size()) && y - 1 >= 0) {
                    if (boardSize[y - 1][x + 1] == currentPlayer) isDiagonal = true;
                }

                if (x - 1 >= 0 && y + 1 < static_cast<int>(boardSize.size())) {
                    if (boardSize[y + 1][x - 1] == currentPlayer) isDiagonal = true;
                }

                if (x + 1 < static_cast<int>(boardSize[0].size()) && y + 1 < static_cast<int>(boardSize.size())) {
                    if (boardSize[y + 1][x + 1] == currentPlayer) isDiagonal = true;
                }
            }

            for (const auto &pair : shapesCoordinates) {
                int x = pair.first;
                int y = pair.second;

                if (x + 1 < boardSize[0].size() && boardSize[y][x + 1] == currentPlayer ) {
                    edgeCounter++; 
                }

                if (x - 1 >= 0 && boardSize[y][x - 1] == currentPlayer) {
                    edgeCounter++;
                }

                if (y + 1 < boardSize.size() && boardSize[y + 1][x] == currentPlayer) {
                    edgeCounter++;
                }

                if (y - 1 >= 0 && boardSize[y - 1][x] == currentPlayer) {
                    edgeCounter++;
                }

                if (edgeCounter > 0) {
                    return false;
                }
            }
            return isDiagonal;
        }

        bool isFirstPlacement(Shapes &shape, int xCoordinate, int yCoordinate, int currentPlayer) {
            if (xCoordinate < 0 || xCoordinate >= 20 || yCoordinate < 0 || yCoordinate >= 20) { // checks if the shapes coordinates are within the maps boundries
                return false; // if it isnt we return false, cant place the piece
            }

            std:: vector<std:: pair<int,int>> shapesCoordinates = shape.coordinates; // create a new vector of shapescoordinates and pass the shapes coordinates to this so we dont change the original coordinates
            for (auto &pair : shapesCoordinates) { // for each loop that add the current x and y coordinate to all pairs within the shape
                pair.first += xCoordinate; // adding the current x offset
                pair.second += yCoordinate; // adding the current y offset
            }
            for (auto &pair : shapesCoordinates) { // for each loop to then check if the absolute coordinates of the shape are within bounds of the map
                if (pair.first < 0 || pair.first >= 20 || pair.second < 0 || pair.second >= 20) {
                    return false; // if it isnt we return false, cane place the piece
                }
            }

            bool isFirstPiece = true; // bool to check if its the players first time placing a piece
            for (const auto &row : boardSize) { // cylces through each row and all the cells within that row to find the players number,
                for (const auto &cell : row) {
                    if (cell == currentPlayer) { // if found that means the player has a piece on the map already
                        isFirstPiece = false; // else they dont have a piece on the map
                        break;
                    }
                }
            }
            return isFirstPiece; // we return eihter true or false
        }

        bool placePiece(Shapes &shape, int xCoordinate, int yCoordinate, int currentPlayer) { //pasisng the x and y coordinates of where the user wants to place the shape, passing Shapes object, alson with the name of the shape to find it and the players numebr
            int rows = boardSize.size();
            int columns = boardSize[0].size();
            if (xCoordinate < 0 || xCoordinate >= 20 || yCoordinate < 0 || yCoordinate >= 20) { // checks the bounds of the board to see if the x and y values inputed are within the games boundries
                std:: cerr << "Invalid coordinate" << std:: endl; // 2 error messeges in case user does input outside of the boundry
                std:: cerr << "X and Y coordinate must be within the 20x20 grid square" << std:: endl;
                return false;
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
                    return false;
                } else if (boardSize[pair.second][pair.first] == 0) { // hoenstly forgot what this line does

                } else {
                    std:: cerr << "A cell within the coordinates is taken or shape is out of bounds" << std:: endl;
                    std:: cout << std:: endl;
                    return false;
                }
            }

            bool hasPlayerPlacedPiece = false; // bool for first loop through game to see if the player has already placed a piece
            bool hasPlacedInCorner = false; // bool to chekc if the player has placed in the corner of the map

            for (const auto &pair : shapesCoordinates) { // for loop to cycle through the shpapes absolute coordinates
                int x = pair.first; // sets the x value of the current pair
                int y = pair.second; // sets the y value of the current pair

                if ((x == 0 && y == 0) || // if x and y == the top left corner
                    (x == columns - 1 && y == 0) || // if x and y == the top right corner
                    (x == 0 && y == rows - 1) || // if x and y == the bottom left corner
                    (x == columns - 1 && y == rows - 1)) { // if x and y == the bottom right corner
                        hasPlacedInCorner = true; // if any condition above is true we have placed in the corner
                        break;
                    }
            }

            for (auto &row : boardSize) { // cycle through the board to find a cell with the current players number
                for (auto &cell : row) {
                    if (cell == currentPlayer) { // if a cell is equal to the current players number we return true meaning player has placed a piece already
                        hasPlayerPlacedPiece = true; // sets it to true, we found a piece
                        if (!isPieceDiagonal(shape, xCoordinate, yCoordinate, currentPlayer)) { // calls the isPIeceDiagonal function forcing user to place diagonal to their own shapes
                            return false;
                        }
                        break; // break out of this loop
                    }
                }
            }
            

            // finally if the shapes coordinates are within the bounds we can place it
            for(auto &pair : shapesCoordinates) { // cycles through the pairs of coodinates
                boardSize[pair.second][pair.first] = currentPlayer; // the board at the current x and y value coordniates is equal to the players number
            }
            std:: cout << shape.name << " has been placed at " << "(" << xCoordinate << "," << yCoordinate << ")" << std:: endl; // checker messege to see that piece has been placed
            std:: cout << std:: endl;
            return true;
        }
};

class Player {
    public:
        std:: string playerName;
        int playerPoints = 0;

        std:: map<std:: string, Shapes> personalShapes = Shapes::initailizeShapes();

        std:: map<std:: string, Shapes> removePiece(Shapes &currentShape) {
            auto shapeToDelete = personalShapes.find(currentShape.name);

            if (shapeToDelete != personalShapes.end()) {
                personalShapes.erase(shapeToDelete);
            }
            return personalShapes;
        }

        void availablePieces() {
            std:: cout << "Availale Pieces" << std:: endl;
            for (const auto shape : personalShapes) {
                std:: cout << shape.first << std:: endl;
            }
            std:: cout << std:: endl;
        }

        bool findSpecificPiece(Shapes &currentShape) {
            auto shapeTofind = personalShapes.find(currentShape.name);

            if (shapeTofind != personalShapes.end()) {
                return true;
            }
            return false;
        }

        int piecesPlaced = 0;

        bool isFirstMove() const { return piecesPlaced == 0;}
        void notePLaced() {++piecesPlaced;}

        void setName(std:: string passedName) {
            playerName = passedName;
        }

        std:: string getName() {
            return playerName;
        }
};


int main() {
    BoardGame board;
    int playerCount = 0;
    std:: vector<Player> playervector;
    bool hasPickedPiece = false;
    bool hasPlacedPiece = false;
    bool continueGame = false;
    int currentPlayer = 1;
    int offSetX = 0;
    int offSetY = 0;
    const auto &shapesMap = ShapesManager::getInstance().getShapeMap();    

    std:: cout << "Enter amount of players (2-4): ";
    std:: cin >> playerCount;

    while (playerCount <= 1 || playerCount > 4) {
        std:: cout << "Enter amount of players (2-4): ";
        std:: cin >> playerCount;
    }

    playervector.resize(playerCount);

    for (auto &player : playervector) {
        std:: string playerName;
        std:: cout << "Enter Name: ";
        std:: cin >> playerName;
        player.setName(playerName);
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    
    while (playervector.size() > 1) {
        for (int current = 0; current < playervector.size(); current++) {
            hasPickedPiece = false;
            hasPlacedPiece = false;
            std:: string pieceName;
            Shapes choosenShape;
            int options;

            while (!hasPickedPiece) {
                std:: cout << playervector[current].getName() << std:: endl;
                std:: cout << "Enter 1 to see current available pieces" << std:: endl;
                std:: cout << "Enter 2 to see movements for shape" << std:: endl;
                std:: cout << "Enter 3 to type piece name" << std:: endl;
                std:: cin >> options;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (options == 1) {
                    std:: cout << "You have the current pieces:" << std:: endl;
                    playervector[current].availablePieces();
                } else if (options == 2) {
                    std:: cout << "Controls:" << std:: endl;
                    std:: cout << "Arrow keys - move shape" << std:: endl;
                    std:: cout << "R/r rotate 90°" << std:: endl;
                    std:: cout << "H/h flip horizontal" << std:: endl;
                    std:: cout << "V/v flip vertical" << std:: endl;
                    std:: cout << "Enter to place piece" << std:: endl;
                } else if (options == 3) {
                    do {
                        std:: cout << playervector[current].getName() << ", type piece name: ";
                        std:: getline(std:: cin, pieceName);
                        choosenShape = shapesMap.at(pieceName);

                        if (shapesMap.find(pieceName) == shapesMap.end()) {
                            std:: cerr << "Piece doesnt exist or was misspelled. Try again" << std:: endl;
                            continue;
                        }

                        if (!playervector[current].findSpecificPiece(choosenShape)) {
                            std:: cerr << "You have used this piece already, Try again" << std:: endl;
                            continue;
                        }
                        hasPickedPiece = true;
                        
                    } while (!hasPickedPiece);
                } else {
                    std:: cerr << "Please enter 1, 2, or 3" << std:: endl;
                }
            }

            offSetX = 0;
            offSetY = 0;
            while (!hasPlacedPiece) {
                board.printMapDynamically(board.boardSize, choosenShape, offSetX, offSetY, current + 1);
                int ch = _getch();
                if (ch == 224) {
                    int arrow = _getch();
                    switch(arrow) {
                        case 72: offSetY = std:: max(0, offSetY - 1); break;
                        case 80: offSetY = std:: min(19, offSetY + 1); break;
                        case 75: offSetX = std:: max(0, offSetX - 1); break;
                        case 77: offSetX = std:: min(19, offSetX + 1); break;
                        default: break;
                    }
                } else if (ch == 'r' || ch == 'R') {
                    choosenShape = choosenShape.rotated90();
                } else if (ch == 'v' || ch == 'V') {
                    choosenShape = choosenShape.flipShapeVertical();
                } else if (ch == 'h' || ch == 'H') {
                    choosenShape = choosenShape.flipShapeHorizontal();
                } else if (ch == 13) { // Enter key
                    // Attempt to place the piece permanently.
                    if (board.placePiece(choosenShape, offSetX, offSetY, current+1)) {
                        hasPlacedPiece = true;
                    // Remove the piece from the player's personalShapes:
                        playervector[current].removePiece(choosenShape);
                    } else {
                        std:: cout << "Invalid placement. Try again." << std:: endl;
                    }
                } else if (ch == 'q' || ch == 'Q') {
                return 0;
                }
            }
        }
    }
    board.printMap();
}