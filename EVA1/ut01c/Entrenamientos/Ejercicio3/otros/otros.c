#include <stdio.h>
#include <stdlib.h>

void generateCombinationsUtil(char* prefix, int n, int k, int index) {
    if (index == k) {
        printf("%s ", prefix);
        return;
    }

    for (int i = 0; i < n; i++) {
        char newPrefix[index + 2];
        sprintf(newPrefix, "%s%c", prefix, 'a' + i);
        generateCombinationsUtil(newPrefix, n, k, index + 1);
    }
}

void generateCombinations(int n, int k) {
    char prefix[1] = "";  // Empty prefix to start with
    generateCombinationsUtil(prefix, n, k, 0);
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