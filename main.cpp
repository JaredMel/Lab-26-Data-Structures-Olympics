#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;


int main() {
    vector<string> vector1;
    list<string> list1;
    set<string> set1;

    cout << "Operation  Vector  List    Set" << endl;
    //Reading
    cout << "Read   ";
    ifstream fin("codes.txt");
    string code;
    
    auto start = high_resolution_clock::now();
    while (fin >> code)
    {
        vector1.push_back(code);
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << "   ";

    start = high_resolution_clock::now();
    while (fin >> code)
    {
        list1.push_back(code);
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << "   ";

    start = high_resolution_clock::now();
    while (fin >> code)
    {
        set1.insert(code);
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << endl;

    fin.close();
    //Sorting
    cout << "Sort   ";

    start = high_resolution_clock::now();
    sort(vector1.begin(), vector1.end());
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << "   ";

    start = high_resolution_clock::now();
    list1.sort();
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << "   ";

    cout << "-1" << endl;

    //Inserting
    cout << "Insert   ";
    string test = "TESTCODE";
    int mid = 10000;

    start = high_resolution_clock::now();
    vector1.insert(vector1.begin() + mid, test);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << "   ";

    start = high_resolution_clock::now();
    list<string> :: iterator it1 = list1.begin();
    advance(it1, mid);
    list1.insert(it1, test);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << "   ";

    start = high_resolution_clock::now();
    set<string> :: iterator it2 = set1.begin();
    advance(it2, mid);
    set1.insert(it2, test);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << endl;

    //Deleting
    cout << "Delete   ";

    start = high_resolution_clock::now();
    vector1.erase(vector1.begin()+19999);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << "   ";

    start = high_resolution_clock::now();
    list<string> :: iterator it3 = list1.begin();
    advance(it3, mid);
    list1.erase(it3);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << "   ";

    start = high_resolution_clock::now();
    set<string> :: iterator it4 = set1.begin();
    advance(it4, mid);
    set1.erase(it4);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << endl;
    
    
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/