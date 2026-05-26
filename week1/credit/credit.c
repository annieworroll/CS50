// Verify a credit card number
#include <cs50.h>
#include <stdio.h>

string luhn(long int n);
int digit_sum(int n);

int main()
{
    long int ccnum = 4003600000000014;
    string validity = luhn(ccnum);
        
    printf("%s\n", validity);
    return 0;
}

string luhn(long int n)
{   
    bool valid = true;

    int checksum = 0;
    int undouble_part = 0;
    int double_part = 0;

    int issuer_code = 0;
    // Generate checksum
    while(n > 0){
        // undoubled
        undouble_part += n % 10;
        n /= 10;

        //doubled
        double_part += digit_sum( (n % 10) * 2);
        n /= 10;

        // Check for issuer
        if(n < 100){
            issuer_code = n;
        }
    }
    checksum = undouble_part + double_part;

    // Check validity and if valid, issuer
    if(checksum % 10 == 0){
        if(issuer_code == 34 || issuer_code == 37){
            return "AMEX";
        }else if(issuer_code >= 40 || issuer_code <= 49){
            return "VISA";
        }else if(issuer_code >=51 || issuer_code <= 55){
            return "MASTERCARD";
        }
    }
    
    return "INVALID";
}

int digit_sum(int n)
{
    int sum = 0;

    while(n > 0){
        sum += n % 10;
        n /= 10;
    }

    return sum;
}