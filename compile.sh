#!/bin/bash
g++ -c ./src/Prism.cpp ./src/Line3D.cpp ./src/Point3D.cpp ./src/Screen.cpp ./src/Vector3D.cpp ./src/Space.cpp ./src/Sphere.cpp
g++ main.cpp Prism.o Line3D.o Point3D.o Screen.o Vector3D.o Space.o Sphere.o
