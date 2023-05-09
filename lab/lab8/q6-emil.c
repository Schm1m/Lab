#include <stdio.h>

char getFirstCapitalLetter(char *str, int i)
{
    if (str[i] == '\0')
    {
        return ' '; // returns " " if the index reaches the end of the string
    }
    return (str[i] >= 'A' && str[i] <= 'Z') ? str[i] : getFirstCapitalLetter(str, i + 1); // character printed if it's capital, process repeated if none of the conditions is met

}

int main(void)
{
    char str[20], capt;
    int i = 0;

    scanf("%s", str);
    capt = getFirstCapitalLetter(str, i);
    printf("%c", capt);

    return 0;
}