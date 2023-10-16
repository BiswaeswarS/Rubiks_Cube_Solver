#include <bits/stdc++.h>
#include "Representations\rubikscube3D.cpp"
#include "Solvers\DFSSolver.h"
#include "Solvers\BFSSolver.h"

using namespace std;
int main() {
    rubikscube3D obj;
    cout<<"Initial Solved State Cube : "<<endl;
    obj.print();
    vector<Generic_Rubiks_Cube::MOVE>moves_done=obj.randomShuffleCube(5);
    cout<<"The cube after shuffling : "<<endl;
    obj.print();
    cout<<"Moves done : ";
    for(auto move:moves_done){
        cout<<obj.getMove(move)<<" ";
    }
    cout<<endl;
    /*DFSSolver<rubikscube3D,Hash3d> dfssolver(obj,8);
    vector<Generic_Rubiks_Cube::MOVE>moves_to_solve=dfssolver.solve();*/
    BFSSolver<rubikscube3D,Hash3d> bfssolver(obj);
    vector<Generic_Rubiks_Cube::MOVE>moves_to_solve=bfssolver.solve();
    cout<<"Moves to Solve : ";
    for(auto move:moves_to_solve){
        cout<<obj.getMove(move)<<" ";
    }
    cout<<endl;
    return 0;
}
