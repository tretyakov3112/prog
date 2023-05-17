#include <iostream>


int main(){
    int M;
    int N;

    std::cin >> M;
    std::cin >> N;
    int arr[N];

    for (int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    for (int i = 0; i < N-1; i++) { 
        for (int j = 0; j < N-i-1; j++) { 
            if (arr[j] > arr[j+1]) { 
                int tmp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = tmp; 
            } 
        } 
    }  
    
    int cnt = 0; 
    int sum = 0;
    while(sum + arr[cnt] <= M && cnt <= N) {
        sum += arr[cnt];
        cnt++;
    }
    std::cout << cnt << std::endl;
    return 0;
}