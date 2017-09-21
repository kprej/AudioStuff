#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <typeinfo>
using namespace std;

int main ()
{
	fstream audio ("test.mp3", fstream::in | fstream::out | fstream::binary);
	if (! audio)
		cout << "IT not there";

	unique_ptr<filebuf> inbuf;
	inbuf.reset (audio.rdbuf ());
	char c = inbuf->sbumpc ();
	while (c != EOF)
	{
		cout << c;
	}

	cout << "Type is " << typeid(audio).name () <<endl;
	return 0;
}
