//https://massivealgorithms.blogspot.com/2014/07/dynamic-programming-set-27-maximum-sum_14.html?m=1
int kadane(int* arr, int* start, int* finish, int n){ //Kadane 1D Array
    int sum = 0, maxSum = INT_MIN, i;
    *finish = -1;
    int local_start = 0;
    for(i = 0; i < n; ++i){
        sum += arr[i];
        if(sum < 0){
            sum = 0;
            local_start = i+1;
        } else if (sum > maxSum){
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }
    if(*finish != -1) return maxSum;
    //Caso Especial: Todos los elementos de arr[] son negativos
    maxSum = arr[0];
    *start = *finish = 0;
    for (i = 1; i < n; i++){
        if (arr[i] > maxSum){
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

int findMaxSum(int M[][]){
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
    int left, right, i;
    int sum, start, finish;
    for(left = 0; left < COL; ++left){
        int temp[ROW]={0};
        for(right = left; right < COL; ++right){
            for(i = 0; i < ROW; ++i) temp[i] += M[i][right];
            sum = kadane(temp, &start, &finish, ROW);
            if (sum > maxSum){
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
    return maxSum;
}
