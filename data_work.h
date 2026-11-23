#pragma once
#include <fstream>
#include <string>

class Data_work {
private:
    static std::ofstream outFile;
public:
    static void init(const std::string& filename);
    static void update_output_data(int step, double energy);
    static void close(); };
