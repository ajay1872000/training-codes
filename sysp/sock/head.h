struct date{
	int d;
	int m;
	int y;
};
struct address
{
	char area[30];
	char location[30];
	char hno[10];
	char state[10];
	unsigned long int pincode;
};
struct nominee{
	unsigned long int adno;
	char name[32];
	unsigned long int phno;
};
struct regis{
	unsigned long int u_id;
	unsigned long int phno;
	unsigned long int adno;
	unsigned long int acno;
	unsigned int bal;
	char name[33];
	char pass[17];
	char gen;
	struct address add;
	struct date dob;
	struct nominee n;
	char rdt[100];
};
struct login{
	unsigned long int u_id;
	char pass[17];
};
