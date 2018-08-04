#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <time.h> 

using namespace std;

int main()
{
	/* code */
	string plainText, result;
	int index;
	srand (time(NULL));
	// string :: iterator it;
	// string::size_type pos;

	getline(cin, plainText);
	int key = (rand()%26)+97;

	// for( it = plainText.begin(); it != plainText.end(); ++it){
	int len = plainText.length();
	cout<<" key = "<<(char)key<<" ";

	for(int i = 0; i<len; i++ ){
		// cout<<"pt = "<<(int)plainText[i]<<endl; 
		if((int)plainText[i] != 32){
			index = ((int)plainText[i]) - 96;
			// cout<<"index = "<<index<<endl;
			cout<<(char)((((key + index)%26) + 97)%122)<<" ";
		} else {
			key = (rand()%26)+97;
			cout<<" key = "<<(char)key<<" ";
		}
	}

	return 0;
}