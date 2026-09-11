#include <iostream> // enables usage of std::cin and std::cout

// bubbleSort function, is called by main, takes two arguments and returns void
void bubbleSort(long long arr[], int n) { // arguments are the array of elements and the number of elements n, long long was int before but caused overflow issues
    for (int i = 0; i < n - 1; ++i) {
        // We go through all elements but the last, because we always compare i with i+1
        for (int j = 0; j < n - i - 1; ++j) {
            // inner loop subtracts i because the largest elements add up already sorted in the end
            if (arr[j] > arr[j + 1]) { // compare element at hand with element to the right and swap if order is unsorted
                long long tempVar = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempVar;
            }
        }
    }
}

// main function, reading input, calling bubbleSort, and printing results
int main() {
    int n; // number of elements
    
    if (!(std::cin >> n)) { // read n = number of elements, exit when no input is given
        std::cout << std::endl; // newline before exit
        return 0;
    }

     if (n <= 0) { // invalid input: n is 0 or negative
         std::cout << std::endl; // newline before exit
         return 0;
    }

    long long* arr = new long long[n]; // array holding n elements

    for (int i = 0; i < n; ++i) { // reading elements of the array from input
        std::cin >> arr[i];
    }

    bubbleSort(arr, n); // invoking bubbleSort function

    // printing the sorted array element by element, followed by a space
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    
    std::cout << std::endl; // newline

    delete[] arr; // free up memory

    return 0; // exit program
}
