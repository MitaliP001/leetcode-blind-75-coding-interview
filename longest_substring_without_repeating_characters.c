#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int hashMap[256] = {0};
    int maxLength = 0, start = 0;
    
    for (int end = 0; end < n; end++) {
        hashMap[s[end]]++;
        
        while (hashMap[s[end]] > 1) {
            hashMap[s[start]]--;
            start++;
        }
        
        maxLength = (maxLength > (end - start + 1)) ? maxLength : (end - start + 1);
    }
    
    return maxLength;
}

int main() {
    char s[] = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    printf("Length of longest substring: %d\n", result);
    return 0;
}
