#include <stdio.h>
int main()
{
    //declaration of variables
    int key, len, choice, mul=1;
    char string [101];
    
    //getting the input from the user
    printf("Enter the plain text: ");
    scanf("%s%n", string, &len);
    printf("Enter the key: ");
    scanf("%d", &key);
   
    //Iterate every character in the string
    for (int i = 0; i < len; ++i)
    {
        int val = 97;
        if(string[i] >= 65 && string[i] <= 90)
        {
            val = 65;
        }
        
        //logic to encrypt the characters
        string[i]= ((((string[i] - val) + (key * mul)) % 26) + val);
    }
    
    //print the string
    printf("Encrypted Text: %s", string);
    return 0;
}
