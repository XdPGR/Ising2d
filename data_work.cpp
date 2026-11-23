#include "data_work.h"

std::ofstream Data_work::outFile; 
void Data_work::init(const std::string& filename) {
    outFile.open(filename);
    if (outFile.is_open()) {
        outFile << "Step\tEnergy\n"; 
    }
}

void Data_work::update_output_data(int step, double energy) {
    if (outFile.is_open()) {
        outFile << step << "\t" << energy << "\n";
    }
}

void Data_work::close() { 
    if (outFile.is_open()) {
        outFile.close();
    }
}
