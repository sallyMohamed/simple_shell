<h1>ALX Simple Shell Project</h1>                                                                                        
                                                                                                                              
This is an ALX project on Shell.                                                                                                     
                                                                                                                              
<h2>Project Used</h2>                                                                                               
<ul>                                                                                                                          
<li>C language</li>                                                                                                           
<li>Shell</li>                                                                                                                          
</ul>                                                                                                                                                                                                                                         
<h2>Status </h2>                                                                                                                  
hsh returns the exit status of the last command executed, with zero indicating success and non-zero indicating failure.       
                                                                                                                              
If a command is not found, the return status is 127; if a command is found but is not executable, the return status is 126.   
                                                                                                                          
<h2>Replacement</h2>                                                                                                          
Interprets the $ character for variable replacement.                                                                     


Comments 
                                                                                                                    Ignores all words and characters preceeded by a # character on a line.                                                                                                                                                              


Operator characters:

; - Command separator                                                                                                         
Commands separated by a ; are executed sequentially.                                                                                                               



The operators && and || have equal precedence, followed by ;.                                                                 
                                                                                                                              
<b>Commands </b>                                                                                                         

cd                                                                                                                            

Usage: cd [DIRECTORY]                                                                                                         

Changes the current directory


PWD and OLDPWD are updated after a change of directory.                                      


alias                                                                                                                         

Usage: alias [NAME[='VALUE'] ...]                                                                                           
alias: Prints a list of all aliases, one per line, in the form NAME='VALUE'.                                              

exit                                                                                                                          

Usage: exit [STATUS]                                                                                                          

Exits the shell.                                                                                                              

The STATUS argument is the integer used to exit the shell.                                                                    

If no argument is given, the command is interpreted as exit 0.                                                        
env

Usage: env                                                                                                                    

Prints the current environment.                                                                                        
setenv                                                                                                                        

Usage: setenv [VARIABLE] [VALUE]                                                                                              

Initializes a new environment variable, or modifies an existing one.                                                          

                                                                                                    
<h2>Authors</h2>                                                                                                              
                                                                                                                    

Sally Mohamed Abdel Rasoul

Sara Ahmed Mohamed
