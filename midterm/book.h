#define NAME_MAX 30

struct Book{
	int id;
	char bookName[NAME_MAX];
	char author[NAME_MAX];
	int year;
	int borrowCount;
	int borrow;
};
