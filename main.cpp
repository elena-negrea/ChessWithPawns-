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


void initialposition_Pawns( uint64_t& whitePawns, uint64_t& blackPawns, const int BOARD_WIDTH){
    //the initial pozitions of whitePawns and blackPawns

    whitePawns = 0;
    blackPawns = 0;

    const int WHITE_START_ROW = 2;
    const int BLACK_START_ROW = 7;
    for(int col = 0; col < BOARD_WIDTH; col++){
        int whiteIndex = (WHITE_START_ROW - 1) * BOARD_WIDTH + col;//we use it to find out what bit corresponds with ex: E2 = 12
        int blackIndex = (BLACK_START_ROW - 1) * BOARD_WIDTH + col;//index is the position for one single bit

        whitePawns |= (1ULL << whiteIndex); // Set the bit corresponding to the pawn's position on the chessboard.
        blackPawns |= (1ULL << blackIndex);
        
        
    }
    /*ALTERNATIVE:otherwise we could have whitePawns = 255ULL << 8; to just put directly the  row of bits */
}

void input_player( const int BOARD_WIDTH, int fromIndex, int toIndex){
    std::string from, to;
     std::cout <<"Enter your move (letternumber)." << std::endl;
    std::cout <<"From: ";
    std::cin >> from;
    std::cout << std::endl;
    std::cout <<" to ";
    std::cin >> to;

    //convert from ASCII to values into our board
    int fromCol = from[0] - 'A';
    int fromRow = from[1] - '0';
    fromIndex = (fromRow - 1) * BOARD_WIDTH + fromCol;

    int toCol = to[0] - 'A';
    int toRow = to[1] - '0';

    toIndex = (toRow - 1) * BOARD_WIDTH + toCol;
}

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
    
    initialposition_Pawns(whitePawns, blackPawns, BOARD_WIDTH);
    print_board(BOARD_WIDTH, whitePawns, blackPawns);

    //variables connected to the input_player
    int fromIndex, toIndex;

    input_player(BOARD_WIDTH, fromIndex, toIndex);
    

    return 0;
}
