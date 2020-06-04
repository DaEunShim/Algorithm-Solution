#include <iostream>
using namespace std; 

int main(void){
	int n; 
	cin >> n; 
	int i = 1, s = 0; 
	while(true) { 
		if (n - i <= 0) break;  
		n -= i; 
		i++; 
		s++; 
	} 

	if (s % 2 == 0) 
		 cout << s + 2 - n << "/" << n; 
	else  cout << n << "/" << s + 2 - n; 
	return 0;
}
