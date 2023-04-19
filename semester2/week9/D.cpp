#include <iostream>

using namespace std;

void swap(int &lha, int &rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
}

void heaper(int arr[], int i, int size){
    int parent = i;
    int l_child = 2*i + 1;
    int r_child = 2*i + 2;

    if (l_child < size && arr[l_child] > arr[parent]){
        parent = l_child;
    }

    if (r_child < size && arr[r_child] > arr[parent]){
        parent = r_child;
    }

    if (parent != i){
        swap(arr[parent], arr[i]);
        heaper(arr, parent, size);
    }
}

void cheops_sort(int arr[], int N){
    for (int i = N/2 + 1; i >= 0; i--){
        heaper(arr, i, N);
    }
    for (int k = N - 1; k >= 0; k--){
        swap(arr[0], arr[k]);
        heaper(arr, 0, k);
    }
}

int archiv(int N, int a[], int m){
    int cnt = 0; 
    int sum = 0;
    while(sum + a[cnt] <= m && cnt <= N) {
        sum += a[cnt];
        cnt++;
    }
    return cnt;
}

int main(){
    int M;
    int N;

    cin >> M;
    cin >> N;
    int memory[N];

    for (int i = 0; i < N; i++){
        cin >> memory[i];
    }
    
    cheops_sort(memory, N);
    cout << archiv(N, memory, M) << endl;
    return 0;
}