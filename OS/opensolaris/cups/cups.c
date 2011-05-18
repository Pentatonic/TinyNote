#include <cups/cups.h>


int main() {
	cups_dest_t *dests;
	int num_dests = cupsGetDests(&dests);
	cups_dest_t *dest;
	int i;
	const char *value;

	printf("num_dest:%d\n", num_dests);
	for (i = num_dests, dest = dests; i > 0; i --, dest ++) {
		if (dest->instance == NULL)
		{
			value = cupsGetOption("printer-info", dest->num_options, dest->options);
			printf("%s (%s)\n", dest->name, value ? value : "no description");
		}
	}

	cupsFreeDests(num_dests, dests);
}

