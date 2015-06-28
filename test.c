#include <stdio.h>
#include <stormlauncher.h>

int
main(int argc, char* argv[]) {
	stormLauncher_t l;

	if( !stormlauncher_open(&l) ) {
		printf("Storm Launcher not found.\n");
		return 0;
	}

	stormlauncher_setled(&l, 1);
	stormlauncher_left_step(&l);
	stormlauncher_fire(&l);
	stormlauncher_setled(&l, 0);	

	return 0;
}

