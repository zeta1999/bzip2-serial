#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>

#include "bzip2.h"
#include "file.h"

using namespace std;

int main(int argc, char* argv[])
{
    string word, bwt_word, mtf_list;
    std::map<char, double> huffman_freq;
    int len;
    
    cout << "Hello user!\nPlease enter a string: ";
    cin >> word;
    len = word.length();
    
    bwt(word, bwt_word);
    
    cout << "BWT done. Result: " << bwt_word << endl;
	
	mtf(bwt_word, mtf_list, huffman_freq);
	
	cout << "MTF done. Result:\n" << bwt_word << endl;
    
    return 0;
}

