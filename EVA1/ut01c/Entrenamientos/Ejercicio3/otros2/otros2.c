#include <stdio.h>
#include <stdlib.h>

void generateCombinations(int n, int k) {
    // 计算可能的组合总数
    int totalCombinations = 1;
    for (int i = 0; i < k; i++) {
        totalCombinations *= n;
    }

    // 生成组合
    for (int i = 0; i < totalCombinations; i++) {
        int temp = i;
        char letters[k];

        // 生成组合中的每个字母
        for (int j = 0; j < k; j++) {
            letters[j] = 'a' + temp % n;
            temp /= n;
        }

        // 打印组合
        for (int j = k - 1; j >= 0; j--) {
            printf("%c", letters[j]);
        }
        printf(" ");
    }
}

int main() {
    int number;
    
    // 获取输入的数字
    printf("请输入一个数字：");
    scanf("%d", &number);

    // 生成字母组合
    generateCombinations(26, number);  // 26个字母
    
    return 0;
}