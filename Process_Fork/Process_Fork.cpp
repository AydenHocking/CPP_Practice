#include <iostream>
#include <unistd.h>

int main()
{
	pid_t id = fork();

	if(id == -1) {
		std::cout << "Error creating process\n";
	} else if (id == 0) {
		std::cout << "I am a child process!\n";
	} else {
		std::cout << "I just became a parent!\n";
	}

	return 0;
}
