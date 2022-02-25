# Description

This pair project is about creating a simple bash-like shell.

# Features
 - Displays **prompt** when waiting for a new command
 - Has a working **history**
 - Searches and launches the right executable (based on the PATH variable or using a relative or an absolute path)
 - Doesn't interpret unclosed quotes or special characters subject such as \ (backslash) or ; (semicolon)
 - ’ (single quote) prevents the shell from interpreting the metacharacters in the quoted sequence
 - " (double quote) prevents the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign)
 - **Redirections**:
 
   < redirects input
  
   \> redirects output 
  
    << should be given a delimiter, then reads the input until a line containing the delimiter is seen (however, it doesn’t update the history)
  
   \>> redirects output in append mode
 -  **Pipes** (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe
 -  **Environment variables** ($ followed by a sequence of characters) expand to their values
 -  **$?** expands to the exit status of the most recently executed foreground pipeline
 -  **ctrl-C, ctrl-D and ctrl-\\** behave like in bash
 -  built-ins:
    
    **echo** with option -n
    
    **cd** with only a relative or absolute path
    
    **pwd** with no options
    
    **export** with no options
    
    **unset** with no options
    
    **env** with no options or arguments
    
    **exit** with no options




# Usage
*Readline library is required*
```
git clone https://github.com/MeSugar/minishell.git
cd minishell
make
./minishell
```
