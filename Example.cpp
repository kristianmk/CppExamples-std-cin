#include <iostream>


int integerInput(const std::string& message)
{
    const std::string conditionalEndline(message.back() == '\n' ? "" : "\n");

    while(true)
    {
        std::cout << message << conditionalEndline << std::flush;

        int value(0);

        // The std::istream will skip any leading whitespace, find sign if any, start reading a number, then stop at first non-numeric character.
        // See documentation here for details: https://en.cppreference.com/w/cpp/io/basic_istream/operator_gtgt
        // std::cin >> results in a call to this function: basic_istream& operator>>( int& value );
        if (std::cin >> value) 
        {
            return value; // Return if and only if a valid int is input through cin.
        }

        std::cerr << "Invalid value entered, try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}


int main() 
{
    const int value = integerInput("Enter an integer number:");
    std::cout << "Your number is " << value << std::endl;
}
