#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t ppid;

	ppid = getppid();

	dprintf(1, "This is the process id %u\n", ppid);

	return (0);
}
