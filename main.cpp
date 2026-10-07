#include <iostream> 
#include <cstdint>

void print_board(const int BOARD_WIDTH, uint64_t whitePawns, uint64_t blackPawns){

    std::cout << "    A   B   C   D   E   F   G   H   " << std::endl;
    for(int row = BOARD_WIDTH; row >= 1; row--){
        std::cout<<"  +---+---+---+---+---+---+---+---+\n";
        std::cout<< row << " |";
    
        for(int col = 0; col < BOARD_WIDTH; col++){

            //VERYFY PAWNS
            // Convert a chess coordinate (row + column) into the matching bit index.
            /*

 Internally, the board uses indexes from 0 to 63:
 A1 = 0, B1 = 1, ..., H1 = 7
 A2 = 8, B2 = 9, ..., H8 = 63
 row uses chess numbering: 1 to 8
 col uses internal numbering: A = 0, B = 1, ..., H = 7

 (row - 1) * BOARD_WIDTH gives the first index of that row.
 Adding col gives the exact square index.
Example: E2
 row = 2, col = 4
 (2 - 1) * 8 + 4 = 12
 So E2 corresponds to bit 12.
            */
            
        int index = (row - 1) * BOARD_WIDTH + col;

        if (whitePawns &(1ULL << index))
            std::cout <<" @ |";
        else if(blackPawns & (1ULL << index))
            std::cout <<" # |";
        else
            std::cout << "   |";
        }
        std::cout << '\n';
    }
    std::cout<<"  +---+---+---+---+---+---+---+---+\n";
}

int initialposition_Pawns(const int BOARD_WIDTH){
    for (int row = BOARD_WIDTH; row >= 1; row--){
        
        for(int col = 0; col <= BOARD_WIDTH; col++){}

    }


}/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////aici am ramas


int main(){

    uint64_t board = 0; // occupied or free

    const int BOARD_SIZE = 64;
    const int BOARD_WIDTH = 8;

    enum Board_pos {
        A1, B1, C1, D1, E1, F1, G1, H1,
        A2, B2, C2, D2, E2, F2, G2, H2,
        A3, B3, C3, D3, E3, F3, G3, H3,
        A4, B4, C4, D4, E4, F4, G4, H4,
        A5, B5, C5, D5, E5, F5, G5, H5,
        A6, B6, C6, D6, E6, F6, G6, H6,
        A7, B7, C7, D7, E7, F7, G7, H7,
        A8, B8, C8, D8, E8, F8, G8, H8
    }; //digits = line, letter = collumn

    uint64_t blackSquares = 0;
    uint64_t whiteSquares = 0; 

    //mark the black squares with 1
    for(int i = 0; i < BOARD_SIZE; i++){
        int row = i / BOARD_WIDTH; 
        int col = i % BOARD_WIDTH;
        if((row + col) % 2 == 0){
            blackSquares |= (1ULL << i); // | here is used to can add the bit where we want withouth changing the others
        }

    }

    uint64_t whitePawns = 0;
    uint64_t blackPawns = 0;
    
    

    print_board(BOARD_WIDTH, whitePawns, blackPawns);
    

    return 0;
}
