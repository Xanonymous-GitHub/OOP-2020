#ifndef UTIL_H
#define UTIL_H

#include "circle.h"
#include "convexPolygon.h"
#include "shape.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef string sort_method;
typedef string sort_reference;

Vector &string_to_vector(string origin_data) {
    origin_data.pop_back();
    origin_data.erase(origin_data.begin());
    istringstream origin_data_container(origin_data);
    string partition_data;
    vector<double> new_tmp_vector;
    while (getline(origin_data_container, partition_data, ',')) {
        new_tmp_vector.push_back(stod(partition_data));
    }
    return *new Vector(new_tmp_vector, new_tmp_vector.size());
}

vector<Shape *> handleInput(string path) {
    ifstream file(path);
    string line;
    vector<Shape *> result;
    if (file.is_open()) {
        string name, radius;
        vector<Vector> vector_vector;
        while (getline(file, line)) {
            if (line == "circle {") {
                getline(file, name);
                string tmp;
                getline(file, tmp);
                getline(file, radius);
                Vector new_vector = string_to_vector(tmp);
                result.push_back(new Circle(stoi(radius), name, new_vector));
            } else if (line == "convex polygon {") {
                getline(file, name);
                string tmp;
                vector_vector.clear();
                while (true) {
                    getline(file, tmp);
                    if (tmp == "}") {
                        break;
                    }
                    vector_vector.push_back(string_to_vector(tmp));
                }
                result.push_back(new ConvexPolygon(vector_vector, name));
            }
        }
        file.close();
    }
    return result;
}

vector<Shape *> handleSort(vector<Shape *> shapes, sort_reference reference, sort_method method) {
    vector<Shape *> sorted_shapes = shapes;
    sort(sorted_shapes.begin(), sorted_shapes.end(), [reference, method](Shape *shape_pointerA, Shape *shape_pointerB) {
        string type = reference + method;
        if (type == "areainc")
            return shape_pointerA->area() < shape_pointerB->area();
        if (type == "areadec")
            return shape_pointerA->area() > shape_pointerB->area();
        if (type == "perimeterinc")
            return shape_pointerA->perimeter() < shape_pointerB->perimeter();
        if (type == "perimeterdec")
            return shape_pointerA->perimeter() > shape_pointerB->perimeter();
        return false;
    });
    return sorted_shapes;
}

void handleOutput(string path, vector<Shape *> shapes) {
    ofstream file;
    file.open(path, ios::trunc);
    if (file.is_open()) {
        for (auto shape : shapes) {
            file << shape->toString();
        }
        file.close();
    }
}

#endif