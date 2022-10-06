#include "random.h"

#include <time.h>

void randomize()
{
	srand((unsigned int)time(0));
}