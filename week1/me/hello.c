#include <cs50.h>
#include <stdio.h>

int main()
{

    // Have the user enter their name
    string user_name = get_string("Enter your name: ");

    //Greet the user
    printf("Hello, %s!\n", user_name);
    return 0;
}