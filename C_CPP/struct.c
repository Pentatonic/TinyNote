
struct medal_count {
	const char *country;
	int gold;
	int silver;
	int bronze;
};

int main() {
	struct medal_count spain = {"Spain", 1, 2, 3};
	struct medal_count france =	{
		.gold = 1,
		.silver = 2,
		.bronze = 3,
		.country = "France"
	};

}
