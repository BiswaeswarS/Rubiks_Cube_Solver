//
// Created by bsaha on 15-10-2023.
//

#include<bits/stdc++.h>
#include "C:\Users\bsaha\OneDrive\Desktop\CLionProjects\Rubiks Cube Solver\Representations\Generic_Rubiks_Cube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function

template<typename T>
class DFSSolver {
private:

    vector<Generic_Rubiks_Cube::MOVE> moves;
    int max_search_depth;

//    DFS code to find the solution (helper function)
    bool dfs(int dep) {
        if (rubiksCube.isSolved()) return true;
        if (dep > max_search_depth) return false;
        for (int i = 0; i < 18; i++) {
            rubiksCube.move(Generic_Rubiks_Cube::MOVE(i));
            moves.push_back(Generic_Rubiks_Cube::MOVE(i));
            if (dfs(dep + 1)) return true;
            moves.pop_back();
            rubiksCube.invert(Generic_Rubiks_Cube::MOVE(i));
        }
        return false;
    }

public:
    T rubiksCube;

    DFSSolver(T _rubiksCube, int _max_search_depth = 8) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<Generic_Rubiks_Cube::MOVE> solve() {
        dfs(1);
        return moves;
    }

};


#endif //RUBIKS_CUBE_SOLVER_DFSSOLVER_H