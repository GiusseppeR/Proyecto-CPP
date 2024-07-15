//
// Created by hcatmin on 14/7/2024.
//
#include "Geometrics/Parser.hpp"

TriangleParser::TriangleParser(std::string path) {
    std::ifstream file(path);
    std::string line;

    if (file.is_open()) {
        // Read each line from the file and store it in the
        // 'line' variable.
        while (getline(file, line)) {
            std::istringstream iss((std::string) line);
            // Input string

            char ignore;
            // Variable to store number n
            double x1, y1, z1;
            double x2, y2, z2;
            double x3, y3, z3;

            // Stream a number till white space
            // is encountered
            iss >> ignore >> x1 >> y1 >> z1 >> ignore >> ignore ;
            iss >> ignore >> x2 >> y2 >> z2 >> ignore >> ignore ;
            iss >> ignore >> x3 >> y3 >> z3 >> ignore >> ignore;

            Point p1(x1,y1,z1), p2(x2,y2,z2), p3(x3,y3,z3);

            triangles.push_back(Triangle(p1,p2,p3));
        }

        // Close the file stream once all lines have been
        // read.
        file.close();
    }
    else {
        // Print an error message to the standard error
        // stream if the file cannot be opened.
        std::cerr << "Unable to open file!" << std::endl;
    }
}