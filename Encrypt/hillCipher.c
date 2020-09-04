#include <stdio.h>
int main()
{
    //declaration of variables
    int key[3][3], len,cipher[3][1],plain[3][1];
    char string[101];
    
    //getting the plain text from the user
    printf("Enter the Plain text of length 3:");
    scanf("%s", string);
    
    //Change the plain text into Nx1 matrix
    for(int i=0;i<3;i++)
    {
        plain[i][0]=((int)string[i])-97;
    }
    
    //Get the Key matrix from the user
    printf("Enter the 3x3 key matrix: ");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d", &key[i][j]);
        }
    }
    
    //Multiply the Key matrix and the plain text matrix to form the cipher text.
    for(int i = 0; i < 3; i++)
	  { 
		  int j = 0;
		  cipher[i][j]=0;
		  for(int k = 0; k < 3; k++)
		  {
			  cipher[i][j]+= (key[i][k] * plain[k][j]);
		  }
	  }
    
    
    //print the encrypted string
    printf("\nEncrypted Text:\n");
	  for(int i = 0; i < 3; i++)
		  printf("%c", ((cipher[i][0])%26)+65);
    return 0;
}
