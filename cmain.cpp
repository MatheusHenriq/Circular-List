#include "CircList.h"

using namespace std;

int main(){

	cList c("A");
	
	c.Insert(1);
	c.Insert(2);
	c.Insert(3);
	c.Insert(4);
	c.Insert(5);
	c.Insert(6);
	c.Josephus(10);
	

	

	c.show();


	

	return 0;
}