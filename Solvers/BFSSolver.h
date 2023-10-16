//
// Created by bsaha on 17-10-2023.
//

#include<bits/stdc++.h>
#include "C:\Users\bsaha\OneDrive\Desktop\CLionProjects\Rubiks Cube Solver\Representations\Generic_Rubiks_Cube.h"

#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function

template<typename T, typename H>
class BFSSolver {
private:
    vector<Generic_Rubiks_Cube::MOVE> moves;
    unordered_map<T, bool, H> visited;
    unordered_map<T, Generic_Rubiks_Cube::MOVE, H> move_done;

//    bfs() -> performs breadth-first-search and returns a solved Rubik's Cube
//    move_done[] -> Back-Pointer map as to how we reached that state
    T bfs() {
        queue<T> q;
        q.push(rubiksCube);
        visited[rubiksCube] = true;

        while (!q.empty()) {
            T node = q.front();
            q.pop();
            if (node.isSolved()) {
                return node;
            }
            for (int i = 0; i < 18; i++) {
                auto curr_move = Generic_Rubiks_Cube::MOVE(i);
                node.move(curr_move);
                if (!visited[node]) {
                    visited[node] = true;
                    move_done[node] = curr_move;
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
        return rubiksCube;
    }

public:
    T rubiksCube;

    BFSSolver(T _rubiksCube) {
        rubiksCube = _rubiksCube;
    }

//    Performs BFS and returns the vector of moves done to solve the cube
    vector<Generic_Rubiks_Cube::MOVE> solve() {
        T solved_cube = bfs();
        //assert(solved_cube.isSolved());
        T curr_cube = solved_cube;
        while (!(curr_cube == rubiksCube)) {
            Generic_Rubiks_Cube::MOVE curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        rubiksCube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
};

#endif //RUBIKS_CUBE_SOLVER_BFSSOLVER_H