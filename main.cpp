#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

int NUMBER_SIMULATIONS = 15;
int ROWS = 4;
int COLUMNS = 3;

int main() {
    vector<string> vector1;
    list<string> list1;
    set<string> set1;
    int arr[NUMBER_SIMULATIONS][ROWS][COLUMNS];
    int avgs[ROWS][COLUMNS];

    for (size_t i = 0; i < NUMBER_SIMULATIONS; i++)
    {
        //Reading
        ifstream fin("codes.txt");
        string code;

        //vector
        auto start = high_resolution_clock::now();
        while (fin >> code)
        {
            vector1.push_back(code);
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        arr[i][0][0] = duration.count();

        //list
        start = high_resolution_clock::now();
        while (fin >> code)
        {
            list1.push_back(code);
        }
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        arr[i][0][1] = duration.count();

        //set
        start = high_resolution_clock::now();
        while (fin >> code)
        {
            set1.insert(code);
        }
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        arr[i][0][2] = duration.count();

        fin.close();
        //Sorting

        start = high_resolution_clock::now();
        sort(vector1.begin(), vector1.end());
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        arr[i][1][0] = duration.count();

        start = high_resolution_clock::now();
        list1.sort();
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        arr[i][1][1] = duration.count();

        arr[i][1][2] = -1;

        //Inserting
        string test = "TESTCODE";
        int mid = 10000;

        start = high_resolution_clock::now();
        vector1.insert(vector1.begin() + mid, test);
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        arr[i][2][0] = duration.count();

        start = high_resolution_clock::now();
        list<string> :: iterator it1 = list1.begin();
        advance(it1, mid);
        list1.insert(it1, test);
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        arr[i][2][1] = duration.count();

        start = high_resolution_clock::now();
        set<string> :: iterator it2 = set1.begin();
        advance(it2, mid);
        set1.insert(it2, test);
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        arr[i][2][2] = duration.count();

        //Deleting

        start = high_resolution_clock::now();
        vector1.erase(vector1.begin()+19999);
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        arr[i][3][0] = duration.count();

        start = high_resolution_clock::now();
        list<string> :: iterator it3 = list1.begin();
        advance(it3, mid);
        list1.erase(it3);
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        arr[i][3][1] = duration.count();

        start = high_resolution_clock::now();
        set<string> :: iterator it4 = set1.begin();
        advance(it4, mid);
        set1.erase(it4);
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        arr[i][3][2] = duration.count();
    }

    int sum = 0;

    for (size_t i = 0; i < ROWS; i++)
    {
        for (size_t j = 0; j < COLUMNS; j++)
        {
            for (size_t k = 0; k < NUMBER_SIMULATIONS; k++)
            {
                sum += arr[k][i][j];
            }
            avgs[i][j] = sum/NUMBER_SIMULATIONS;
            sum = 0;
        } 
    }
    
    cout << "Number of simulations: " << NUMBER_SIMULATIONS << endl;
    cout << "Operation  Vector  List    Set" << endl;

    cout << "Read   ";
    for (size_t i = 0; i < COLUMNS; i++)
    {
        cout << avgs[0][i] << "   ";
    }
    cout << endl;
    
    cout << "Sort   ";
    for (size_t i = 0; i < COLUMNS; i++)
    {
        cout << avgs[1][i] << "   ";
    }
    cout << endl;

    cout << "Insert   ";
    for (size_t i = 0; i < COLUMNS; i++)
    {
        cout << avgs[2][i] << "   ";
    }
    cout << endl;

    cout << "Delete   ";
    for (size_t i = 0; i < COLUMNS; i++)
    {
        cout << avgs[3][i] << "   ";
    }
    cout << endl;
    
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/