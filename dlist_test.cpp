#include "dlist.h"
#include <iostream>
#include <string>

using namespace std;

enum Job {STUDENT, FACULTY, STAFF};

struct Record {
  string name;
  string uniqname;
  Job job;
};

int main() {

  Dlist<Record*> wolverineaccess; //records are big, so store pointer

  Record* p = new Record;
  p->name = "Andrew DeOrio";
  p->uniqname = "awdeorio";
  p->job = FACULTY;
  wolverineaccess.insertFront( p );

  // do something with "wolverineaccess"

  // don't forget to delete objects on the heap
  while ( !wolverineaccess.isEmpty() ) {
    Record *r = wolverineaccess.removeFront();
    cout << r->uniqname << endl;
    delete r;
  }

  return 0;
}
