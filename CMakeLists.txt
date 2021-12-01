cmake_minimum_required(VERSION 3.20)
project(3Dbox)

set(CMAKE_CXX_STANDARD 14)

add_executable(3Dbox main.cpp src/Screen.cpp include/Screen.h src/Space.cpp include/Space.h src/Point3D.cpp include/Point3D.h src/Line3D.cpp include/Line3D.h src/Vector3D.cpp include/Vector3D.h include/GraphicsGems.h src/Prism.cpp include/Prism.h src/Sphere.cpp include/Sphere.h src/Polyhedron.cpp include/Polyhedron.h)
