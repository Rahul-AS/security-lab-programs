#include <stdio.h>

//This function will return the modulo 26 value
int modVal(int val,int mod)
{
    return val%mod;
}

//This function will return the modular inverse
int modInverse(int val,int mod)
{
    if (val<0)
        val+=26;
    val = val%mod; 
    for (int x=1; x<mod; x++) 
       if (modVal(val*x,mod) == 1) 
          return x;
}


int main()
{
    //declaration of variables
    int key[3][3], cipher[3][1], plain[3][1], keyInverse[3][3];
    char string[4];
    
    //getting the input from the user
    printf("Enter the Cipher text of length 3:");
    scanf("%s", string);
    
    //Change the plain text into Nx1 matrix
    for(int i=0;i<3;i++)
    {
        cipher[i][0]=((int)string[i])-65;
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
    
    //Find the determinant of the key matrix
    int determinant=0;
	for(int i = 0; i < 3; i++)
	    determinant += (key[0][i] * (key[1][(i+1)%3] * key[2][(i+2)%3] - key[1][(i+2)%3] * key[2][(i+1)%3]));
    
    int detInverse=modInverse(modVal(determinant,26),26);
    
    //Finding the inverse of the key matrix
    for(int i = 0; i < 3; i++)
    {
		for(int j = 0; j < 3; j++)
		{
			int val=((key[(j+1)%3][(i+1)%3] * key[(j+2)%3][(i+2)%3]) - (key[(j+1)%3][(i+2)%3] * key[(j+2)%3][(i+1)%3]));
			val=((val%26)*detInverse)%26;
			if (val<0)
			    val+=26;
			keyInverse[i][j]=val;
		}
	}
    
    //Multiply the keyInverse and the cipher to get the plain text
	for(int i = 0; i < 3; i++)
	{ 
		int j = 0;
		plain[i][j]=0;
		for(int k = 0; k < 3; k++)
		{
			plain[i][j]+= (keyInverse[i][k] * cipher[k][j]);
		}
	}
	
	//Print the Decrypted text
	printf("\nDecrypted Text:");
	for(int i=0;i<3;i++)
	{
	    printf("%c",plain[i][0]%26+97);
	}
  return 0;
  
}
