cmake_minimum_required(VERSION 3.10)
project(NomDeVotreProjet)

set(CMAKE_CXX_STANDARD 11)

# Emplacement de Google Test (ajustez le chemin en conséquence)
set(GTEST_DIR lib/googletest)

# Ajoutez Google Test à vos cibles
add_subdirectory(${GTEST_DIR})
include_directories(${GTEST_DIR}/include)

# Créez une cible pour vos tests-
add_executable(RunTests
    tests/test_main.cpp 
    tests/OAndDTest.cpp
 )
 
target_link_libraries(RunTests gtest_main)