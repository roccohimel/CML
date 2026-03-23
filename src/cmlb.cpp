#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        std::cout << "Usage: program <input_file> <output_exe>\n";
        return 1;
    }

    const char* inputFile = argv[1];
    const char* outputFile = argv[2];

    // Step 1: copy cmlint.cpp -> cmltemp.cpp
    std::ifstream src("cmlint.cpp", std::ios::binary);
    std::ofstream dst("cmltemp.cpp", std::ios::binary);

    if (!src || !dst)
    {
        std::cout << "Error opening cmlint.cpp or cmltemp.cpp\n";
        return 1;
    }

    dst << src.rdbuf();
    src.close();

    // Step 2: append input file to cmltemp.cpp
    std::ifstream add(inputFile, std::ios::binary);
    if (!add)
    {
        std::cout << "Error opening input file\n";
        return 1;
    }

    dst << add.rdbuf();
    dst.close();
    add.close();

    // Step 3: compile using g++
#ifdef _WIN32
    std::string cmd = "g++ cmltemp.cpp -o " + std::string(outputFile);
#else
    std::string cmd = "g++ cmltemp.cpp -o " + std::string(outputFile);
#endif

    int result = std::system(cmd.c_str());
    if (result != 0)
    {
        std::cout << "Compilation failed\n";
        std::remove("cmltemp.cpp");
        return 1;
    }

    // Step 4: delete temp file
    std::remove("cmltemp.cpp");

    std::cout << "Done.\n";
    return 0;
}