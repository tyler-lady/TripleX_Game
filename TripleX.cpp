#include <iostream> //'#' denotes a preprocessor file, <> denotes a header file - the file to be preprocessed or compiled first. These are typically libraries written by other programmers. These lines do not have to end with a semicolon
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Print welcome statements
    //below we use the standard (std) namespace, then reach into it with the double colon. We use cout and endl functions from the std namespace
    std::cout << "\n\nYou are an international intelligence agent attempting to gather level " << Difficulty;
    std::cout << " life saving information.\nEnter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    //Declare our three number code
    //VARIABLES - can not be assigned before declaration, will throw an exception. Const functions the same. Reassignment of a variable does not require typing (c=14)
    //Unreal naming conventions use UpperCamelCase
    const int CodeA = rand() % Difficulty + Difficulty; //rand() returns value between 0 and at least 37,xxx. Using mod on this (%),  will return a remainder value always one less than modulus value
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    //declare our sum and product vars
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print our sum and product to the terminal
    std::cout << ">> There are 3 numbers in the code.";
    std::cout << "\n>> The codes add up to give: " << CodeSum;
    std::cout << "\n>> The codes multiply to give: " << CodeProduct << std::endl;
    //we have been using cout - which is CharacterOut - outputting to the console. We will begin using cin >> - for CharacterInput ('>>' known as the extraction operator)

    //Variable to be used for storing our user input
    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //CONDITIONAL checking the input values against expected values
    //using \initiates an escape sequence, allowing us to put statements in quotes in strings. \n initiates an escape sequence creating a new line
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou download the data, and quickly move to the next terminal.";
        return true;
    } 
    else
    {
        std::cout << "\nYou hear police enter the building through the door. They sound suspicious...";
        return false;
    }
}

int main() //int lets us know that the function will be returning an integer; every CPP application requires a main function, w/o it won't build
{
    srand(time(NULL)); //creates a new random sequence based on the time of day

    int LevelDifficulty = 1;
    int MaxLevelDifficulty = 5;

    while(LevelDifficulty <= MaxLevelDifficulty) //We will loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty); //here we initialize bLevelComplete with the result of the function PlayGame() -- This also serves to call the function 
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if(bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    
    std::cout << "\nGreat work, agent! You collected all the data! Now get back home!\n";

    //End our program
    return 0; //returning 0 allows us to tell the program that it has completed it's code
}