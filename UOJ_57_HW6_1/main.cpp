#include <iostream>

void parallel_count(int array[], int array_size, int counts[], int max_value);

int main(){
    int array_size, max_value;
    std::cin >> array_size >> max_value;
    int* array = new int[array_size];
    int* counts = new int[max_value + 1];

    for(int i = 0; i < array_size; i++){
        std::cin >> array[i];
    }

    parallel_count(array, array_size, counts, max_value);

    for(int i = 0; i < max_value; i++){
        std::cout << counts[i] << " ";
    }
    std::cout << counts[max_value] << std::endl;

    delete[] array;
    delete[] counts;
    
    return 0;
}
