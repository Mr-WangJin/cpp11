// mutex example

#include "testMutex.h"
#include "testlockgrard.h"
#include "testTimeMutex.h"
#include "testTryLock.h"

int main()
{
	//testMutex();
	
	//testTimeMutex();
	//testlockgrard();
	testTryLock();

	system("pause");
	return 0;
}