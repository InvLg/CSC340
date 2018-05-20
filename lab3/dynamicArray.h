using namespace std;

bool my_less_equal(int &x, int&y);
bool my_greater_equal(int &x, int&y);


int * array_constructor(int * &intPtr, int &size);
int * array_resize(int * &intPtr, int& currSize, int& newSize);
void array_destructor(int * &intPtr);
void array_set(int * &intPtr, int &size);
void mysort(int* &intPtr, int size, bool(*comp)(int&, int&));
