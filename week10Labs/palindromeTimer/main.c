#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game(int sig)
{
    printf("\nFinalscore: %i\n", score);
    exit(0);
}

int catch_signal(int sig, void (*handler)(int))
{
    struct sigaction action;
    action.sa_handler= handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction (sig, &action, NULL);
}
void times_up(int sig)
{
    puts("\nTIME'S UP!");
    raise(SIGINT);
}

int testPalindrome(int len) 
{ 
    char s[len]; 
    int i,j; 
    printf("\nEnter a word of length %d:\n",len); 
    fflush(stdin); 
    gets(s); 
    for (i=0,j=len-1;i<j;i++,j--)
    { 
        if (s[i]!=s[j])
        { 
            printf("\nNot a Palindrome\n"); 
            raise(SIGINT); 
        } 
    } 
     printf("\nPalindrome\n"); 
return 1;
}

int main()
{
    int i = 20; //timer count
    int l = 3; //length counter
    catch_signal(SIGALRM, times_up);
    catch_signal(SIGINT,end_game);
    srandom (time (0));
    while (1) 
    {
        alarm(i);
        testPalindrome(l);
        i += 10;
        l += 1;
        score +=1;
    }   
return 0;
}
