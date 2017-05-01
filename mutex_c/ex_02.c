#include <stdlib.h>
#include <stdio.h>

int lock_var = 0; // actual lock global variable used to provide synchronization
int value; // variable contain lock value merely to explain current state

void acquire_lock()
{
	__asm__("mov %eax, 1;"	// EAX is a 32 bit register in which we are assigning 1
		"xchg %eax, lock_var;" // Exchange eax and lock_var atomically
		"mov value, %eax;" // merely saving for printing purpose
	);
}

void free_lock()
{
	__asm__ (
		"mov %eax, 0;"
		"xchg %eax, lock_var;"  // This could have been a single assignment lock_var = 0
		"mov value, %eax;" // But we are merely using xchg again to see the previous value
	);
}

int main()
{
	acquire_lock();
	if(value == 0) // Value would contain the previous value in lock_var before acquiring lock
		printf("Lock was available so acquired now");

	acquire_lock();
		if(value == 1)
			printf("Already locked so cannot acquire until free");

	free_lock();
	if(value == 1)
		printf("Freed now (though was locked earlier) and can be acquired");

	acquire_lock();
	if(value == 0)
		printf("Lock was available again so acquired now");

	return 0;
}
