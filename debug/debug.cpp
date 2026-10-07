
    

    
    if(board & (1ULL << position)) // verify if the bit at the position is 1 or not
        std::cout << "it s on the position\n";
    else 
        std::cout << "There's nothing\n";
    

        /*NOTE: if you want to show the bits of a value, you have to write the bits from the bigger position to 0 */
    for(int i = (BOARD_SIZE - 1); i >= 0; i--){//showing the bits with the blacks
        if(blackSquares & (1ULL << i))
            std::cout << 1;
        else
            std::cout << 0;
       
            if(i % BOARD_WIDTH == 0)
                std::cout << std::endl;
    }

    