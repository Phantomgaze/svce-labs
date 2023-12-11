#include<stdio.h>
void
main () 
{
  
char STR[100], PAT[100], REP[100], ans[100];
  
int i, j, c, m, k, flag = 0;
  
printf ("\nEnter the MAIN string: \n");
  
fgets (STR, 100, stdin);
  
printf ("\nEnter a PATTERN string: \n");
  
fgets (PAT, 100, stdin);
  
printf ("\nEnter a REPLACE string: \n");
  
fgets (REP, 100, stdin);
  
i = m = c = j = 0;
  
while (STR[c] != '\0')
    
    {
      
// Checking for Match
	if (STR[m] == PAT[i])
	
	{
	  
i++;
	  
m++;
	  
flag = 1;
	  
if (PAT[i] == '\0')
	    
	    {
	      
//copy replace string in ans string
		for (k = 0; REP[k] != '\0'; k++, j++)
		
ans[j] = REP[k];
	      
i = 0;
	      
c = m;
	    
}
	
}
      
      else			//mismatch
	{
	  
ans[j] = STR[c];
	  
j++;
	  
c++;
	  
m = c;
	  
i = 0;
	
}
    
}
  
 
 
if (flag == 0)
    
    {
      
printf ("Pattern doesn't found!!!");
    
}
  
  else
    
    {
      
ans[j] = '\0';
      
printf ("\nThe RESULTANT string is:%s\n", ans);
    
}
  
 
printf ("\nPress enter to exit...");
  
getchar ();			// wait for user input
}
