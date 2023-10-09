#include "link.h"

int main() {
	
	NODE* i = createhead();
	insertBytail(i, 9);
	insertBytail(i, 6);
	insertBytail(i, 4);

	plist(i);
	insertByhead(i, 5);
	plist(i);

	return 0;
}