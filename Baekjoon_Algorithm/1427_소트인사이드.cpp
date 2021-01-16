#include <iostream>

using namespace std;

string s;
string temp;
void merge(int left, int mid, int right){
    int i = 0, j = 0, position = 0;
    int llength = mid - left;
    int rlength = right - mid + 1;
    while( i < llength && j < rlength){
        if(s[left + i] > s[mid + j]){
            temp[position++] = s[left + i];
            i++;
        }
        else{
            temp[position++] = s[mid + j];
            j++;
        }
    }

    while(i < llength){
        temp[position++] = s[left + i];
        i++;
    }

    while(j < rlength){
        temp[position++] = s[mid + j];
        j++;
    }

    for(int k = 0; k < position; k++){
        s[left + k] = temp[k];
    }

}

void mergesort(int left, int right){
    if(left < right){
        int mid = (left + right ) / 2;

        mergesort(left, mid);
        mergesort(mid + 1, right);
        merge(left, mid + 1, right);
    }
}


int main() {
	cin >> s;
	mergesort(0, s.size()-1);
	cout << s <<endl;
	return 0;
}

