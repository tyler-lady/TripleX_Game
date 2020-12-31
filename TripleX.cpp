#include <iostream> //'#' denotes a preprocessor file, <> denotes a header file - the file to be preprocessed or compiled first. These are typically libraries written by other programmers. These lines do not have to end with a semicolon

void PlayGame()
{
    //Declare our three number code
    //VARIABLES - can not be assigned before declaration, will throw an exception. Const functions the same. Reassignment of a variable does not require typing (c=14)
    //Unreal naming conventions use UpperCamelCase
    int CodeA = 4;
    int CodeB = 3;
    int CodeC = 2;

    //declare our sum and product vars
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

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
        std::cout << "\nYou download the data, and make a quick escape!";
    } 
    else
    {
        std::cout << "\nYou hear police enter the building before bursting through the door. They don't take spies prisoner...";
    }
}

void PrintIntroduction()
{
    //Print welcome statements
    //below we use the standard (std) namespace, then reach into it with the double colon. We use cout and endl functions from the std namespace
    std::cout << "You are an international intelligence agent attempting to gather life saving information.\n";
    std::cout << "Enter the correct codes to continue...\n\n";
}

int main() //int lets us know that the function will be returning an integer; every CPP application requires a main function, w/o it won't build
{
    PlayGame();
    
    //End our program
    return 0; //returning 0 allows us to tell the program that it has completed it's code
}