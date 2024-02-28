#include "/public/read.h"
#include "DoublyLL_Interface.h"
#include "DoublyLL.h"
#include "DoublyGPT.h"
#include "DoublySTL.h"
#include <chrono>
#include <memory>
using namespace std;


int main(int argc, char **argv) {
    const size_t SIZE = 10'000'000; // You will benchmark up to 10'000'000
                                   // Creating a constants about which mode you benchmark
    enum MODE { STL, YOU, GPT };
    int mode = STL;
    if (argc > 2) mode = atoi(argv[1]); //Read mode from command line parameters
                                        //If no command line parameter (a.out 0 or a.out 1) is provided, then read from keyboard
    else mode = read("Choose mode:\n0) STL DLL\n1) Your DLL\n2) GPT DLL\n");
    if (mode < STL or mode > GPT) mode = STL;
    cerr << "Mode == " << mode << endl;
    
    int runAmount = 5;
    if (argc > 2) runAmount = atoi(argv[2]);
    else runAmount = read("Enter the amount of times you want to run for benchmarking:\n");
    cerr << "Running benchmark " << runAmount << " times." << endl;

    unique_ptr<DoublyLL> list;
    if (mode == STL) list = make_unique<DoublySTL>();
    else if (mode == YOU) list = make_unique<DoubleLL>();
    else list = make_unique<DoublyGPT>();
    

    string choice;
    if (mode == STL) choice = "STL DLL";
    else if (mode == YOU) choice = "Your DLL";
    else if (mode == GPT) choice = "GPT DLL";
    cout << choice << " Implementation" << endl;
    for (int i = 1; i <= runAmount; i++) {
        list->clear(); // Clears the list to ensure controlled timings.
        auto start = chrono::high_resolution_clock::now();
        while (cin) { // While we are getting input from standard in...
            string s; // Take in the first word (SEARCH, INSERT, ERASE, REMOVE, etc.)
            cin >> s;
            if (!cin) break; // If input fails, break
            if (s == "INSERT") { // If insert, we take in a pos and the data.
             int position = 0, data = 0;
             cin >> position >> data;
             if (!cin) break; // Handle negatives
             // YOU: Implement ".insert(pos, data)" depending on Linked List
            }
            else if (s == "SEARCH") {
             int key;
             cin >> key;
             if (!cin) break;
             // YOU: Implement ".contains(key)" depending on linked list choice
            }
            else if (s == "REMOVE") {
             int position;
             cin >> position;
             if (!cin) break;
             // YOU: Implement ".erase(pos)" depending on linked list choice
            }
            // YOU: Do the following for the rest of the else if statements following
            // the patterns above.
            else if (s == "PUSH_FRONT") {
                // YOU: Implement ".push_front(data)" depending on linked list choice
            }
            else if (s == "PUSH_BACK") {
                // YOU: Implement ".push_back(data)" depending on linked list choice
            }
            else if (s == "POP_BACK") {
                // YOU: Implement ".pop_back()" depending on linked list choice
            }
            else if (s == "POP_FRONT") {
                // YOU: Implement ".pop_front()" depending on linked list choice
            }
            else if (s == "CLEAR") {
                // YOU: Implement ".clear()" depending on linked list choice
            }
            else break;
        }
        auto end = chrono::high_resolution_clock::now();
        cout << duration_cast<chrono::milliseconds>(end - start).count() << " milliseconds" << endl;
    }
}
