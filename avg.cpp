#include <iostream>
#include <vector>


double avg(std::vector<double> input) {
    int VectorSize = input.size();
    double avgOfInput = 0;

    for(int i = 0; i < VectorSize; i++){
        avgOfInput += input[i];
    }
    avgOfInput /= VectorSize;

    return avgOfInput;
} 

int main(int argc, char *argv[])
{
    if(argc == 1) {
        std::cout << "\nCalculates the average of floating point numbers\n\nUsage:\n./avg number1 number2 ..." << std::endl;
        return 1;
    }

    std::vector<double> f_Input;
    
    for(int i = 1; i < argc; i++) {
        int k = 0;
        char currentChar = argv[i][k];
        //Check invalid chars
        while(currentChar != 0) {
            if(currentChar > 44 && currentChar < 58) {
                k++;
                currentChar = argv[i][k];
            }
            else {
                std::cout << "Invalid character detected! (Use a dot instead of a comma)" << std::endl;
                return 2;
            }
        }
        f_Input.push_back(atof(argv[i]));
    }
    std::cout << std::endl << avg(f_Input) << std::endl;
    return 0;
}


