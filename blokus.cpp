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
};

class ShapesManager{
    private:
        std:: map<std:: string, Shapes> shapeMap;
        ShapesManager() {
            Shapes dummyShape;
            shapeMap = dummyShape.initailizeShapes();
        }

        ShapesManager(const ShapesManager&) = delete;
        ShapesManager& operator=(const ShapesManager&) = delete;

    public:
        static ShapesManager& getInstance() {
            static ShapesManager instance;
            return instance;
        }

        const std:: map<std:: string, Shapes> &getShapeMap() const {
            return shapeMap;
        }
};


class BoardGame {
    public:
        std:: vector<std::vector<int>> boardSize;

        BoardGame() : boardSize() {}
        BoardGame(const std:: vector<std::vector<int>> &passedSize) : boardSize(passedSize) {}

        void printMap () {
            std:: vector<std::vector<int>> printableMap = this->boardSize;

            for (const auto row : printableMap) {
                for (const auto element : row) {
                    std:: cout << element << " ";
                }
                std:: cout << std:: endl;
            }
        }

        void placePiece(Shapes &shape, int xCoordinate, int yCoordinate, int currentPlayer) {

        }
};

void printSingleShape(const Shapes &shape) {
    std:: cout << shape.name << std:: endl;
    std:: cout << "---------" << std:: endl;

    for (const auto &pair : shape.coordinates) {
        std:: cout << "(" << pair.first << "," << pair.second << ")";
    }
    std:: cout << std:: endl;
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

int main() {
    // BoardGame board(std:: vector<std:: vector<int>>(20, std:: vector<int>(20,0)));
    // board.printMap();

    // std:: cout << std:: endl;
    // std:: cout << std:: endl;


    const auto &shapeMap = ShapesManager::getInstance().getShapeMap();

    Shapes fShape = shapeMap.at("F Shape");

    printSingleShape(fShape);

    fShape = fShape.rotated90();

    printSingleShape(fShape);


    // const auto &shapes = ShapesManager::getInstance().getShapeMap();

    // if (shapes.find("F Shape") != shapes.end()) {
    //     const Shapes &single = shapes.at("F Shape");
    //     single.rotated90();
    //     printSingleShape(single.name);
    // }

}