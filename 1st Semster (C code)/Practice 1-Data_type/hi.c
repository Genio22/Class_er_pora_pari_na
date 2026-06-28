#include <stdio.h>
#include <stdlib.h>

void create_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
}

int main() {
    // Array of C file contents
    const char *files[][2] = {
        {"remainder.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int num1, num2, remainder;\n\n"
         "    printf(\"Enter two integers: \");\n"
         "    scanf(\"%d %d\", &num1, &num2);\n\n"
         "    if (num2 != 0) {\n"
         "        remainder = num1 %% num2;\n"
         "        printf(\"Remainder: %%d\\n\", remainder);\n"
         "    } else {\n"
         "        printf(\"Division by zero is not allowed.\\n\");\n"
         "    }\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"swap_numbers.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int a, b;\n\n"
         "    printf(\"Enter two integers: \");\n"
         "    scanf(\"%d %d\", &a, &b);\n\n"
         "    printf(\"Before swapping: a = %%d, b = %%d\\n\", a, b);\n\n"
         "    a = a + b;\n"
         "    b = a - b;\n"
         "    a = a - b;\n\n"
         "    printf(\"After swapping: a = %%d, b = %%d\\n\", a, b);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"square_cube.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int num, square, cube;\n\n"
         "    printf(\"Enter an integer: \");\n"
         "    scanf(\"%d\", &num);\n\n"
         "    square = num * num;\n"
         "    cube = num * num * num;\n\n"
         "    printf(\"Square: %%d\\n\", square);\n"
         "    printf(\"Cube: %%d\\n\", cube);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"integer_part.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    float num;\n"
         "    int integerPart;\n\n"
         "    printf(\"Enter a floating-point number: \");\n"
         "    scanf(\"%f\", &num);\n\n"
         "    integerPart = (int)num;\n"
         "    printf(\"Integer part: %%d\\n\", integerPart);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"ascii_value.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    char ch;\n\n"
         "    printf(\"Enter a character: \");\n"
         "    scanf(\" %%c\", &ch);\n\n"
         "    printf(\"ASCII value of '%c': %%d\\n\", ch, (int)ch);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"discriminant.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    float a, b, c, discriminant;\n\n"
         "    printf(\"Enter coefficients a, b, and c: \");\n"
         "    scanf(\"%f %f %f\", &a, &b, &c);\n\n"
         "    discriminant = (b * b) - (4 * a * c);\n"
         "    printf(\"Discriminant: %.2f\\n\", discriminant);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"convert_time.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int total "    int totalMinutes, hours, minutes;\n\n"
         "    printf(\"Enter total minutes: \");\n"
         "    scanf(\"%d\", &totalMinutes);\n\n"
         "    hours = totalMinutes / 60;\n"
         "    minutes = totalMinutes % 60;\n\n"
         "    printf(\"Equivalent time: %d hours and %d minutes\\n\", hours, minutes);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"fibonacci.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int n, t1 = 0, t2 = 1, nextTerm;\n\n"
         "    printf(\"Enter the number of terms: \");\n"
         "    scanf(\"%d\", &n);\n\n"
         "    printf(\"Fibonacci Series: \");\n\n"
         "    for (int i = 1; i <= n; ++i) {\n"
         "        printf(\"%d, \", t1);\n"
         "        nextTerm = t1 + t2;\n"
         "        t1 = t2;\n"
         "        t2 = nextTerm;\n"
         "    }\n\n"
         "    printf(\"\\n\");\n"
         "    return 0;\n"
         "}\n"},
         
        {"factorial.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int n;\n"
         "    unsigned long long factorial = 1;\n\n"
         "    printf(\"Enter a positive integer: \");\n"
         "    scanf(\"%d\", &n);\n\n"
         "    for (int i = 1; i <= n; ++i) {\n"
         "        factorial *= i;\n"
         "    }\n\n"
         "    printf(\"Factorial of %d = %llu\\n\", n, factorial);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"prime_check.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int n, i, isPrime = 1;\n\n"
         "    printf(\"Enter a positive integer: \");\n"
         "    scanf(\"%d\", &n);\n\n"
         "    if (n <= 1) {\n"
         "        isPrime = 0;\n"
         "    } else {\n"
         "        for (i = 2; i <= n / 2; ++i) {\n"
         "            if (n % i == 0) {\n"
         "                isPrime = 0;\n"
         "                break;\n"
         "            }\n"
         "        }\n"
         "    }\n\n"
         "    if (isPrime)\n"
         "        printf(\"%d is a prime number.\\n\", n);\n"
         "    else\n"
         "        printf(\"%d is not a prime number.\\n\", n);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"gcd.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int a, b, gcd;\n\n"
         "    printf(\"Enter two integers: \");\n"
         "    scanf(\"%d %d\", &a, &b);\n\n"
         "    for (int i = 1; i <= a && i <= b; ++i) {\n"
         "        if (a % i == 0 && b % i == 0)\n"
         "            gcd = i;\n"
         "    }\n\n"
         "    printf(\"GCD of %d and %d = %d\\n\", a, b, gcd);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"lcm.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int a, b, lcm;\n\n"
         "    printf(\"Enter two integers: \");\n"
         "    scanf(\"%d %d\", &a, &b);\n\n"
         "    lcm = (a > b) ? a : b;\n\n"
         "    while (1) {\n"
         "        if (lcm % a == 0 && "lcm % b == 0) {\n"
         "            printf(\"LCM of %d and %d = %d\\n\", a, b, lcm);\n"
         "            break;\n"
         "        }\n"
         "        ++lcm;\n"
         "    }\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"reverse_string.c", 
         "#include <stdio.h>\n"
         "#include <string.h>\n\n"
         "int main() {\n"
         "    char str[100], rev[100];\n"
         "    int len, j = 0;\n\n"
         "    printf(\"Enter a string: \");\n"
         "    fgets(str, sizeof(str), stdin);\n\n"
         "    len = strlen(str) - 1; // Exclude newline character\n"
         "    for (int i = len; i >= 0; i--) {\n"
         "        rev[j++] = str[i];\n"
         "    }\n"
         "    rev[j] = '\\0';\n\n"
         "    printf(\"Reversed string: %s\\n\", rev);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"count_vowels.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    char str[100];\n"
         "    int vowels = 0;\n\n"
         "    printf(\"Enter a string: \");\n"
         "    fgets(str, sizeof(str), stdin);\n\n"
         "    for (int i = 0; str[i] != '\\0'; i++) {\n"
         "        char ch = str[i];\n"
         "        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||\n"
         "            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {\n"
         "            vowels++;\n"
         "        }\n"
         "    }\n\n"
         "    printf(\"Number of vowels: %d\\n\", vowels);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"palindrome.c", 
         "#include <stdio.h>\n"
         "#include <string.h>\n\n"
         "int main() {\n"
         "    char str[100], rev[100];\n"
         "    int len, j = 0;\n\n"
         "    printf(\"Enter a string: \");\n"
         "    fgets(str, sizeof(str), stdin);\n\n"
         "    len = strlen(str) - 1; // Exclude newline character\n"
         "    for (int i = len; i >= 0; i--) {\n"
         "        rev[j++] = str[i];\n"
         "    }\n"
         "    rev[j] = '\\0';\n\n"
         "    if (strcmp(str, rev) == 0) {\n"
         "        printf(\"'%s' is a palindrome.\\n\", str);\n"
         "    } else {\n"
         "        printf(\"'%s' is not a palindrome.\\n\", str);\n"
         "    }\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"sum_of_digits.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int num, sum = 0;\n\n"
         "    printf(\"Enter an integer: \");\n"
         "    scanf(\"%d\", &num);\n\n"
         "    while (num != 0) {\n"
         "        sum += num % 10;\n"
         "        num /= 10;\n"
         "    }\n\n"
         "    printf(\"Sum of digits: %d\\n\", sum);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"count_words.c", 
         "#include <stdio.h>\n"
         "#include <string.h>\n\n"
         "int main() {\n"
         "    char str[100];\n"
         "    int count = 0;\n\n"
         "    printf(\"Enter a string: \");\n"
         "    fgets(str, sizeof(str), stdin);\n\n"
 "    char *token = strtok(str, \" \\\\n\");\n"
         "    while (token != NULL) {\n"
         "        count++;\n"
         "        token = strtok(NULL, \" \\\\n\");\n"
         "    }\n\n"
         "    printf(\"Number of words: %d\\n\", count);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"count_characters.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    char str[100];\n"
         "    int count = 0;\n\n"
         "    printf(\"Enter a string: \");\n"
         "    fgets(str, sizeof(str), stdin);\n\n"
         "    for (int i = 0; str[i] != '\\0'; i++) {\n"
         "        if (str[i] != ' ' && str[i] != '\\n') {\n"
         "            count++;\n"
         "        }\n"
         "    }\n\n"
         "    printf(\"Number of characters (excluding spaces): %d\\n\", count);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"binary_to_decimal.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    char binary[32];\n"
         "    int decimal = 0;\n\n"
         "    printf(\"Enter a binary number: \");\n"
         "    scanf(\"%s\", binary);\n\n"
         "    for (int i = 0; binary[i] != '\\0'; i++) {\n"
         "        decimal = decimal * 2 + (binary[i] - '0');\n"
         "    }\n\n"
         "    printf(\"Decimal equivalent: %d\\n\", decimal);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"decimal_to_binary.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int decimal, binary[32], i = 0;\n\n"
         "    printf(\"Enter a decimal number: \");\n"
         "    scanf(\"%d\", &decimal);\n\n"
         "    while (decimal > 0) {\n"
         "        binary[i++] = decimal % 2;\n"
         "        decimal /= 2;\n"
         "    }\n\n"
         "    printf(\"Binary equivalent: \");\n"
         "    for (int j = i - 1; j >= 0; j--) {\n"
         "        printf(\"%d\", binary[j]);\n"
         "    }\n"
         "    printf(\"\\n\");\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"string_length.c", 
         "#include <stdio.h>\n"
         "#include <string.h>\n\n"
         "int main() {\n"
         "    char str[100];\n\n"
         "    printf(\"Enter a string: \");\n"
         "    fgets(str, sizeof(str), stdin);\n\n"
         "    int length = strlen(str) - 1; // Exclude newline character\n"
         "    printf(\"Length of the string: %d\\n\", length);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"string_copy.c", 
         "#include <stdio.h>\n"
         "#include <string.h>\n\n"
         "int main() {\n"
         "    char source[100], destination[100];\n\n"
         "    printf(\"Enter a string: \");\n"
         "    fgets(source, sizeof(source), stdin);\n\n"
         "    strcpy(destination, source);\n"
         "    printf(\"Copied string: %s\\n\", destination);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"string_concatenation.c", 
         "#include <stdio.h>\n"
         "#include <string.h>\n\n"
         "int main() {\n"
         "    char str1[100], str2[100];\n\n"
         "    printf(\"Enter first string: \");\n"
         "    fgets(str1, sizeof(str1), stdin);\n\n"
         "    printf(\"Enter second string: \");\n"
         "    fgets(str2, sizeof(str2 ```c
), stdin);\n\n"
         "    strcat(str1, str2);\n"
         "    printf(\"Concatenated string: %s\\n\", str1);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"string_compare.c", 
         "#include <stdio.h>\n"
         "#include <string.h>\n\n"
         "int main() {\n"
         "    char str1[100], str2[100];\n\n"
         "    printf(\"Enter first string: \");\n"
         "    fgets(str1, sizeof(str1), stdin);\n\n"
         "    printf(\"Enter second string: \");\n"
         "    fgets(str2, sizeof(str2), stdin);\n\n"
         "    if (strcmp(str1, str2) == 0) {\n"
         "        printf(\"Strings are equal.\\n\");\n"
         "    } else {\n"
         "        printf(\"Strings are not equal.\\n\");\n"
         "    }\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"string_reverse.c", 
         "#include <stdio.h>\n"
         "#include <string.h>\n\n"
         "int main() {\n"
         "    char str[100];\n"
         "    int len;\n\n"
         "    printf(\"Enter a string: \");\n"
         "    fgets(str, sizeof(str), stdin);\n\n"
         "    len = strlen(str) - 1; // Exclude newline character\n"
         "    printf(\"Reversed string: \");\n\n"
         "    for (int i = len; i >= 0; i--) {\n"
         "        putchar(str[i]);\n"
         "    }\n"
         "    printf(\"\\n\");\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"count_digits.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int num, count = 0;\n\n"
         "    printf(\"Enter an integer: \");\n"
         "    scanf(\"%d\", &num);\n\n"
         "    while (num != 0) {\n"
         "        num /= 10;\n"
         "        count++;\n"
         "    }\n\n"
         "    printf(\"Number of digits: %d\\n\", count);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"sum_of_even_odd.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int n, sumEven = 0, sumOdd = 0;\n\n"
         "    printf(\"Enter a positive integer: \");\n"
         "    scanf(\"%d\", &n);\n\n"
         "    for (int i = 1; i <= n; i++) {\n"
         "        if (i % 2 == 0) {\n"
         "            sumEven += i;\n"
         "        } else {\n"
         "            sumOdd += i;\n"
         "        }\n"
         "    }\n\n"
         "    printf(\"Sum of even numbers: %d\\n\", sumEven);\n"
         "    printf(\"Sum of odd numbers: %d\\n\", sumOdd);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"area_of_circle.c", 
         "#include <stdio.h>\n"
         "#define PI 3.14159\n\n"
         "int main() {\n"
         "    float radius, area;\n\n"
         "    printf(\"Enter the radius of the circle: \");\n"
         "    scanf(\"%f\", &radius);\n\n"
         "    area = PI * radius * radius;\n"
         "    printf(\"Area of the circle: %.2f\\n\", area);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"area_of_rectangle.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    float length, width, area;\n\n"
         "    printf(\"Enter length and width of the rectangle: \");\n"
         "    scanf(\"%f %f\", &length, &width);\n\n"
         "    area = length * width;\n"
         "    "printf(\"Area of the rectangle: %.2f\\n\", area);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"area_of_triangle.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    float base, height, area;\n\n"
         "    printf(\"Enter base and height of the triangle: \");\n"
         "    scanf(\"%f %f\", &base, &height);\n\n"
         "    area = 0.5 * base * height;\n"
         "    printf(\"Area of the triangle: %.2f\\n\", area);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"simple_interest.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    float principal, rate, time, interest;\n\n"
         "    printf(\"Enter principal, rate of interest, and time: \");\n"
         "    scanf(\"%f %f %f\", &principal, &rate, &time);\n\n"
         "    interest = (principal * rate * time) / 100;\n"
         "    printf(\"Simple Interest: %.2f\\n\", interest);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"compound_interest.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    float principal, rate, time, amount;\n\n"
         "    printf(\"Enter principal, rate of interest, and time: \");\n"
         "    scanf(\"%f %f %f\", &principal, &rate, &time);\n\n"
         "    amount = principal * (1 + rate / 100);\n"
         "    for (int i = 1; i < time; i++) {\n"
         "        amount *= (1 + rate / 100);\n"
         "    }\n\n"
         "    printf(\"Compound Interest: %.2f\\n\", amount - principal);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"temperature_conversion.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    float celsius, fahrenheit;\n\n"
         "    printf(\"Enter temperature in Celsius: \");\n"
         "    scanf(\"%f\", &celsius);\n\n"
         "    fahrenheit = (celsius * 9 / 5) + 32;\n"
         "    printf(\"Temperature in Fahrenheit: %.2f\\n\", fahrenheit);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"factorial_recursive.c", 
         "#include <stdio.h>\n\n"
         "int factorial(int n) {\n"
         "    if (n == 0) return 1;\n"
         "    return n * factorial(n - 1);\n"
         "}\n\n"
         "int main() {\n"
         "    int n;\n\n"
         "    printf(\"Enter a positive integer: \");\n"
         "    scanf(\"%d\", &n);\n\n"
         "    printf(\"Factorial of %d = %d\\n\", n, factorial(n));\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"power.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int base, exponent, result = 1;\n\n"
         "    printf(\"Enter base and exponent: \");\n"
         "    scanf(\"%d %d\", &base, &exponent);\n\n"
         "    for (int i = 0; i < exponent; i++) {\n"
         "        result *= base;\n"
         "    }\n\n"
         "    printf(\"%d raised to the power of %d = %d\\n\", base, exponent, result);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"sum_of_n_numbers.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int n, sum = 0;\n\n"
         "    printf(\"Enter a positive integer: \");\n"
         "    scanf(\"%d\", &n);\n\n"
         "    for (int i = 1; i <= n; i++) {\n"
         "        sum += i;\n"
         "    }\n\n"
         "    printf(\"Sum of first %d natural numbers: %d\\n\", n, sum);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"sum_of_two_numbers.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int a, b, sum;\n\n"
         "    printf(\"Enter two integers: \");\n"
         "    scanf(\"%d %d\", &a, &b);\n\n"
         "    sum = a + b;\n"
         "    printf(\"Sum: %d\\n\", sum);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"multiply_two_numbers.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int a, b, product;\n\n"
         "    printf(\"Enter two integers: \");\n"
         "    scanf(\"%d %d\", &a, &b);\n\n"
         "    product = a * b;\n"
         "    printf(\"Product: %d\\n\", product);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"divide_two_numbers.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    float a, b, quotient;\n\n"
         "    printf(\"Enter two numbers: \");\n"
         "    scanf(\"%f %f\", &a, &b);\n\n"
         "    if (b != 0) {\n"
         "        quotient = a / b;\n"
         "        printf(\"Quotient: %.2f\\n\", quotient);\n"
         "    } else {\n"
         "        printf(\"Division by zero is not allowed.\\n\");\n"
         "    }\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"max_of_two_numbers.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int a, b;\n\n"
         "    printf(\"Enter two integers: \");\n"
         "    scanf(\"%d %d\", &a, &b);\n\n"
         "    if (a > b) {\n"
         "        printf(\"Maximum: %d\\n\", a);\n"
         "    } else {\n"
         "        printf(\"Maximum: %d\\n\", b);\n"
         "    }\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"min_of_two_numbers.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int a, b;\n\n"
         "    printf(\"Enter two integers: \");\n"
         "    scanf(\"%d %d\", &a, &b);\n\n"
         "    if (a < b) {\n"
         "        printf(\"Minimum: %d\\n\", a);\n"
         "    } else {\n"
         "        printf(\"Minimum: %d\\n\", b);\n"
         "    }\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"is_even_or_odd.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int num;\n\n"
         "    printf(\"Enter an integer: \");\n"
         "    scanf(\"%d\", &num);\n\n"
         "    if (num % 2 == 0) {\n"
         "        printf(\"%d is even.\\n\", num);\n"
         "    } else {\n"
         "        printf(\"%d is odd.\\n\", num);\n"
         "    }\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"is_positive_negative.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int num;\n\n"
         "    printf(\"Enter an integer: \");\n"
         "    scanf(\"%d\", &num);\n\n"
         "    if (num > 0) {\n"
         "        printf(\"%d is positive.\\n\", num);\n"
         "    } else if (num < 0) {\n"
         "        printf(\"% "d is negative.\\n\", num);\n"
         "    } else {\n"
         "        printf(\"%d is zero.\\n\", num);\n"
         "    }\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"is_prime.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int n, i, isPrime = 1;\n\n"
         "    printf(\"Enter a positive integer: \");\n"
         "    scanf(\"%d\", &n);\n\n"
         "    if (n <= 1) {\n"
         "        isPrime = 0;\n"
         "    } else {\n"
         "        for (i = 2; i <= n / 2; ++i) {\n"
         "            if (n % i == 0) {\n"
         "                isPrime = 0;\n"
         "                break;\n"
         "            }\n"
         "        }\n"
         "    }\n\n"
         "    if (isPrime)\n"
         "        printf(\"%d is a prime number.\\n\", n);\n"
         "    else\n"
         "        printf(\"%d is not a prime number.\\n\", n);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"fibonacci_recursive.c", 
         "#include <stdio.h>\n\n"
         "int fibonacci(int n) {\n"
         "    if (n <= 1) return n;\n"
         "    return fibonacci(n - 1) + fibonacci(n - 2);\n"
         "}\n\n"
         "int main() {\n"
         "    int n;\n\n"
         "    printf(\"Enter the number of terms: \");\n"
         "    scanf(\"%d\", &n);\n\n"
         "    printf(\"Fibonacci Series: \");\n\n"
         "    for (int i = 0; i < n; i++) {\n"
         "        printf(\"%d, \", fibonacci(i));\n"
         "    }\n\n"
         "    printf(\"\\n\");\n"
         "    return 0;\n"
         "}\n"},
         
        {"gcd_recursive.c", 
         "#include <stdio.h>\n\n"
         "int gcd(int a, int b) {\n"
         "    if (b == 0) return a;\n"
         "    return gcd(b, a % b);\n"
         "}\n\n"
         "int main() {\n"
         "    int a, b;\n\n"
         "    printf(\"Enter two integers: \");\n"
         "    scanf(\"%d %d\", &a, &b);\n\n"
         "    printf(\"GCD of %d and %d = %d\\n\", a, b, gcd(a, b));\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"lcm_recursive.c", 
         "#include <stdio.h>\n\n"
         "int gcd(int a, int b) {\n"
         "    if (b == 0) return a;\n"
         "    return gcd(b, a % b);\n"
         "}\n\n"
         "int lcm(int a, int b) {\n"
         "    return (a * b) / gcd(a, b);\n"
         "}\n\n"
         "int main() {\n"
         "    int a, b;\n\n"
         "    printf(\"Enter two integers: \");\n"
         "    scanf(\"%d %d\", &a, &b);\n\n"
         "    printf(\"LCM of %d and %d = %d\\n\", a, b, lcm(a, b));\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"binary_search.c", 
         "#include <stdio.h>\n\n"
         "int binarySearch(int arr[], int size, int target) {\n"
         "    int left = 0, right = size - 1;\n\n"
         "    while (left <= right) {\n"
         "        int mid = left + (right - left) / 2;\n\n"
         "        if (arr[mid] == target) return mid;\n"
         "        if (arr[mid] < target) left = mid + 1;\n"
         "        else "right = mid - 1;\n"
         "    }\n"
         "    return -1; // Target not found\n"
         "}\n\n"
         "int main() {\n"
         "    int arr[] = {2, 3, 4, 10, 40};\n"
         "    int size = sizeof(arr) / sizeof(arr[0]);\n"
         "    int target;\n\n"
         "    printf(\"Enter the number to search: \");\n"
         "    scanf(\"%d\", &target);\n\n"
         "    int result = binarySearch(arr, size, target);\n"
         "    if (result != -1)\n"
         "        printf(\"Element found at index: %d\\n\", result);\n"
         "    else\n"
         "        printf(\"Element not found in the array.\\n\");\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"selection_sort.c", 
         "#include <stdio.h>\n\n"
         "void selectionSort(int arr[], int size) {\n"
         "    for (int i = 0; i < size - 1; i++) {\n"
         "        int minIndex = i;\n"
         "        for (int j = i + 1; j < size; j++) {\n"
         "            if (arr[j] < arr[minIndex]) {\n"
         "                minIndex = j;\n"
         "            }\n"
         "        }\n"
         "        int temp = arr[minIndex];\n"
         "        arr[minIndex] = arr[i];\n"
         "        arr[i] = temp;\n"
         "    }\n"
         "}\n\n"
         "int main() {\n"
         "    int arr[] = {64, 25, 12, 22, 11};\n"
         "    int size = sizeof(arr) / sizeof(arr[0]);\n\n"
         "    selectionSort(arr, size);\n\n"
         "    printf(\"Sorted array: \");\n"
         "    for (int i = 0; i < size; i++) {\n"
         "        printf(\"%d \", arr[i]);\n"
         "    }\n"
         "    printf(\"\\n\");\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"insertion_sort.c", 
         "#include <stdio.h>\n\n"
         "void insertionSort(int arr[], int size) {\n"
         "    for (int i = 1; i < size; i++) {\n"
         "        int key = arr[i];\n"
         "        int j = i - 1;\n\n"
         "        while (j >= 0 && arr[j] > key) {\n"
         "            arr[j + 1] = arr[j];\n"
         "            j--;\n"
         "        }\n"
         "        arr[j + 1] = key;\n"
         "    }\n"
         "}\n\n"
         "int main() {\n"
         "    int arr[] = {12, 11, 13, 5, 6};\n"
         "    int size = sizeof(arr) / sizeof(arr[0]);\n\n"
         "    insertionSort(arr, size);\n\n"
         "    printf(\"Sorted array: \");\n"
         "    for (int i = 0; i < size; i++) {\n"
         "        printf(\"%d \", arr[i]);\n"
         "    }\n"
         "    printf(\"\\n\");\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"bubble_sort.c", 
         "#include <stdio.h>\n\n"
         "void bubbleSort(int arr[], int size) {\n"
         "    for (int i = 0; i < size - 1; i++) {\n"
         "        for (int j = 0; j < size - i - 1; j++) {\n"
         "            if (arr[j] > arr[j + 1]) {\n"
         "                int temp = arr[j];\n"
         "                arr[j] = arr[j + 1];\n"
         "                arr[j + 1] = temp;\n"
         "            }\n"
         "        }\n"
         "    }\n"
         "}\n\n"
         "int ```c
main() {\n"
         "    int arr[] = {64, 34, 25, 12, 22, 11, 90};\n"
         "    int size = sizeof(arr) / sizeof(arr[0]);\n\n"
         "    bubbleSort(arr, size);\n\n"
         "    printf(\"Sorted array: \");\n"
         "    for (int i = 0; i < size; i++) {\n"
         "        printf(\"%d \", arr[i]);\n"
         "    }\n"
         "    printf(\"\\n\");\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"merge_sort.c", 
         "#include <stdio.h>\n\n"
         "void merge(int arr[], int left, int mid, int right) {\n"
         "    int i, j, k;\n"
         "    int n1 = mid - left + 1;\n"
         "    int n2 = right - mid;\n\n"
         "    int L[n1], R[n2];\n\n"
         "    for (i = 0; i < n1; i++)\n"
         "        L[i] = arr[left + i];\n"
         "    for (j = 0; j < n2; j++)\n"
         "        R[j] = arr[mid + 1 + j];\n\n"
         "    i = 0; j = 0; k = left;\n\n"
         "    while (i < n1 && j < n2) {\n"
         "        if (L[i] <= R[j]) {\n"
         "            arr[k] = L[i];\n"
         "            i++;\n"
         "        } else {\n"
         "            arr[k] = R[j];\n"
         "            j++;\n"
         "        }\n"
         "        k++;\n"
         "    }\n\n"
         "    while (i < n1) {\n"
         "        arr[k] = L[i];\n"
         "        i++;\n"
         "        k++;\n"
         "    }\n\n"
         "    while (j < n2) {\n"
         "        arr[k] = R[j];\n"
         "        j++;\n"
         "        k++;\n"
         "    }\n"
         "}\n\n"
         "void mergeSort(int arr[], int left, int right) {\n"
         "    if (left < right) {\n"
         "        int mid = left + (right - left) / 2;\n\n"
         "        mergeSort(arr, left, mid);\n"
         "        mergeSort(arr, mid + 1, right);\n\n"
         "        merge(arr, left, mid, right);\n"
         "    }\n"
         "}\n\n"
         "int main() {\n"
         "    int arr[] = {38, 27, 43, 3, 9, 82, 10};\n"
         "    int size = sizeof(arr) / sizeof(arr[0]);\n\n"
         "    mergeSort(arr, 0, size - 1);\n\n"
         "    printf(\"Sorted array: \");\n"
         "    for (int i = 0; i < size; i++) {\n"
         "        printf(\"%d \", arr[i]);\n"
         "    }\n"
         "    printf(\"\\n\");\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"quick_sort.c", 
         "#include <stdio.h>\n\n"
         "int partition(int arr[], int low, int high) {\n"
         "    int pivot = arr[high];\n"
         "    int i = (low - 1);\n\n"
         "    for (int j = low; j < high; j++) {\n"
         "        if (arr[j] < pivot) {\n"
         "            i++;\n"
         "            int temp = arr[i];\n"
         "            arr[i] = arr[j];\n"
         "            arr[j] = temp;\n"
         "        }\n"
         "    }\n\n"
         "    int temp = arr[i + 1];\n"
         "    arr[i + 1] = arr[high];\n"
         "    arr[high] = temp;\n"
         "    return (i + 1);\n"
         "}\n\n"
         "void quickSort(int arr[], int low, int high) {\n"
         "    if (low < high) {\n"
         "        int pi = partition(arr, low, high);\n\n"
         "        quickSort(arr, low, pi - 1);\n"
         "        quickSort(arr, pi + 1, high);\n"
         "    }\n"
         "}\n\n"
         "int main() {\n"
         "    int arr[] = {10, 7, 8, 9, 1, 5};\n"
         "    int size = sizeof(arr) / sizeof(arr[0]);\n\n"
         "    quickSort(arr, 0, size - 1);\n\n"
         "    printf(\"Sorted array: \");\n"
         "    for (int i = 0; i < size; i++) {\n"
         "        printf(\"%d \", arr[i]);\n"
         "    }\n"
         "    printf(\"\\n\");\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"count_occurrences.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};\n"
         "    int size = sizeof(arr) / sizeof(arr[0]);\n"
         "    int count[size];\n"
         "    int visited[size];\n\n"
         "    for (int i = 0; i < size; i++) {\n"
         "        count[i] = 1;\n"
         "        visited[i] = 0;\n"
         "    }\n\n"
         "    for (int i = 0; i < size; i++) {\n"
         "        if (visited[i] == 1) continue;\n"
         "        for (int j = i + 1; j < size; j++) {\n"
         "            if (arr[i] == arr[j]) {\n"
         "                count[i]++;\n"
         "                visited[j] = 1;\n"
         "            }\n"
         "        }\n"
         "    }\n\n"
         "    printf(\"Element occurrences:\\n\");\n"
         "    for (int i = 0; i < size; i++) {\n"
         "        if (visited[i] == 0) {\n"
         "            printf(\"%d occurs %d times\\n\", arr[i], count[i]);\n"
         "        }\n"
         "    }\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"string_to_integer.c", 
         "#include <stdio.h>\n"
         "#include <stdlib.h>\n\n"
         "int main() {\n"
         "    char str[20];\n"
         "    printf(\"Enter a number: \");\n"
         "    fgets(str, sizeof(str), stdin);\n\n"
         "    int num = atoi(str);\n"
         "    printf(\"Integer value: %d\\n\", num);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"integer_to_string.c", 
         "#include <stdio.h>\n"
         "#include <stdlib.h>\n\n"
         "int main() {\n"
         "    int num;\n"
         "    printf(\"Enter an integer: \");\n"
         "    scanf(\"%d\", &num);\n\n"
         "    char str[20];\n"
         "    sprintf(str, \"%d\", num);\n"
         "    printf(\"String value: %s\\n\", str);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"string_to_float.c", 
         "#include <stdio.h>\n"
         "#include <stdlib.h>\n\n"
         "int main() {\n"
         "    char str[20];\n"
         "    printf(\"Enter a float number: \");\n"
         "    fgets(str, sizeof(str), stdin);\n\n"
         "    float num = atof(str);\n"
         "    printf(\"Float value: %.2f\\n\", num);\n\n"
         "    return 0;\n"
         "}\ ```c
}\n"},
         
        {"float_to_string.c", 
         "#include <stdio.h>\n"
         "#include <stdlib.h>\n\n"
         "int main() {\n"
         "    float num;\n"
         "    printf(\"Enter a float number: \");\n"
         "    scanf(\"%f\", &num);\n\n"
         "    char str[20];\n"
         "    sprintf(str, \"%.2f\", num);\n"
         "    printf(\"String value: %s\\n\", str);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"string_to_double.c", 
         "#include <stdio.h>\n"
         "#include <stdlib.h>\n\n"
         "int main() {\n"
         "    char str[20];\n"
         "    printf(\"Enter a double number: \");\n"
         "    fgets(str, sizeof(str), stdin);\n\n"
         "    double num = atof(str);\n"
         "    printf(\"Double value: %.2f\\n\", num);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"double_to_string.c", 
         "#include <stdio.h>\n"
         "#include <stdlib.h>\n\n"
         "int main() {\n"
         "    double num;\n"
         "    printf(\"Enter a double number: \");\n"
         "    scanf(\"%lf\", &num);\n\n"
         "    char str[20];\n"
         "    sprintf(str, \"%.2f\", num);\n"
         "    printf(\"String value: %s\\n\", str);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"string_to_char.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    char str[2];\n"
         "    printf(\"Enter a character: \");\n"
         "    fgets(str, sizeof(str), stdin);\n\n"
         "    char ch = str[0];\n"
         "    printf(\"Character value: %c\\n\", ch);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"char_to_string.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    char ch;\n"
         "    printf(\"Enter a character: \");\n"
         "    scanf(\" %c\", &ch);\n\n"
         "    char str[2];\n"
         "    sprintf(str, \"%c\", ch);\n"
         "    printf(\"String value: %s\\n\", str);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"string_to_boolean.c", 
         "#include <stdio.h>\n"
         "#include <string.h>\n\n"
         "int main() {\n"
         "    char str[10];\n"
         "    printf(\"Enter 'true' or 'false': \");\n"
         "    fgets(str, sizeof(str), stdin);\n\n"
         "    int boolean = (strcmp(str, \"true\\n\") == 0) ? 1 : 0;\n"
         "    printf(\"Boolean value: %d\\n\", boolean);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"boolean_to_string.c", 
         "#include <stdio.h>\n\n"
         "int main() {\n"
         "    int boolean;\n"
         "    printf(\"Enter 1 for true or 0 for false: \");\n"
         "    scanf(\"%d\", &boolean);\n\n"
         "    char *str = boolean ? \"true\" : \"false\";\n"
         "    printf(\"String value: %s\\n\", str);\n\n"
         "    return 0;\n"
         "}\n"},
         
        {"string_to_array.c", 
         "#include <stdio.h>\n"
         "#include <string.h>\n\n"
         "int main() {\n"
         "    char str[100];\n"
         "    printf(\"Enter a string: \");\n"
         "    fgets(str, sizeof(str), stdin);\n\n"
         "    char arr[100];\n"
         "    strcpy(arr, str);\n"
         "    printf(\"Array value: %s\\n\", arr);\n\n"
         "    return 0;\n ```c
"    return 0;\n"
"}\n"},
    };

    // Create the C files
    for (int i = 0; i < sizeof(files) / sizeof(files[0]); i++) {
        create_file(files[i][0], files[i][1]);
    }

    // Zip the files (This example uses zip command available on Linux/Mac)
    system("zip C_Programs.zip *.c");

    printf("C files created and zipped successfully.\n");
    return 0;
}