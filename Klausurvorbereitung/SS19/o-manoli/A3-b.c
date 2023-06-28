#include <stdio.h>

unsigned short int si; // doesn't do anything

void main()
{
	int i, k;
	int *iPtr;
	int *kPtr;
	int **iPtrPtr;
	unsigned short int *siPtr; // doesn't do anything
	void *vPtr;
	i = 3;
	k = 7;
	iPtr = &i;
	kPtr = &k;
	iPtrPtr = &iPtr;
	*kPtr += 2;	// k = k + 2, k = 7 + 2 = 9

	// i = 3 initial value didn't changed
	// k = 9 #Line 16
	// *iPtr refers to the value stored at the address of i -> 3
	// *kPtr refers to the value stored at the address of k -> 9
	// **iPtrPtr: follow the address stored iPtrPtr
	//    to get the address of i
	//    and then fetch the value stored there which is i -> 3
	printf("a) i=%d, k=%d, *iPtr=%d, *kPtr=%d, **iPtrPtr=%d \n",
			 i, k, *iPtr, *kPtr, **iPtrPtr);

	// dereference then increment.
	(*iPtr)++; // Updates the value of i-> i = i+1 = 3+1 = 4

	// iPtrPtr holds the address of iPtr
	*iPtrPtr = kPtr; // rewrites the address stored in iPtr to points to kPtr

	// iPtr now points to k. therefor i will updated
	i += *iPtr; // i = i + k = 4 + 9 = 13

	// dereferening takes priority over arithmetics
	--(*kPtr); // kPtr -> k. k = k-1 = 9-1 = 8

	kPtr = &i; // kPtr now points to i
	// kPtr and iPtr have be swapped their initial values


	// i = 13.	#Line35
	// k = 8		#Line38
	// iPtr now points to k -> *iPtr = 8
	// kPtr now points to i -> *kPtr = 13
	// iPtrPtr still points to iPtr but iPtr points to k -> **iPtrPtr = 8
	printf("b) i=%d, k=%d, *iPtr=%d, *kPtr=%d, **iPtrPtr=%d \n",
			 i, k, *iPtr, *kPtr, **iPtrPtr);
}

