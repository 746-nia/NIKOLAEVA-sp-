#include <iostream>
#include <ctime>
using namespace std;
int main()
{
 srand(time(0));
 int n = rand() % 19 + 1;
 int *array = new int[n];
 cout<<endl<<"size array: "<<n<<"\n\n";
 asm(
  "mov $8, %%eax\n\t"           
  "mov %[n], %%ebx\n\t"           
  "dec %%ebx\n\t"                 
  "mull %%ebx\n\t"    
            
  "mov %[array], %%ebx\n\t"       
  "mov %[array], %%ecx\n\t"       
  "add %%eax, %%ecx\n\t"          
  "mov $0, %%eax\n\t"             
  "start_loop:\n\t"
  "inc %%eax\n\t"                 
  "cmp %%ebx, %%ecx\n\t"          
  "je last_single\n\t"            
  "add $4, %%ebx\n\t"
  "cmp %%ebx, %%ecx\n\t"          
  "je last_double\n\t"            
  "sub $4, %%ebx\n\t"             
  "mov %%eax, (%%ebx)\n\t"        
  "mov %%eax, (%%ecx)\n\t"        
  "add $4, %%ebx\n\t"             
  "sub $4, %%ecx\n\t"             
														           "jmp start_loop\n\t"            
   "last_single:\n\t"                  
   "mov %%eax, (%%ebx)\n\t"        
  "jmp end_asm\n\t"
   "last_double:\n\t"
         
   "sub $4, %%ebx\n\t"             
   "mov %%eax, (%%ebx)\n\t"        
   "mov %%eax, (%%ecx)\n\t"       

   "end_asm:\n\t"                     
 :
 :[n]"m"(n), [array]"m"(array) 
 :"%eax", "%ebx", "%ecx"         
														         );
																				     
														         for (int i=0; i<n; i++)

cout<<array[i] << " ";     
														         cout<<endl;
 delete [] array;
 														         return 0;
															 }
