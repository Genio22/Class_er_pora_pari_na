import os
import zipfile36
# Additional problem files provided by the user
user_provided_problems = [
    ("11_Modulus_Operation.c", """
#include <stdio.h>

int main() {
    int num1, num2, remainder;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    if (num2 != 0) {
        remainder = num1 % num2;
        printf("Remainder: %d\\n", remainder);
    } else {
        printf("Division by zero is not allowed.\\n");
    }

    return 0;
}
"""),
    ("12_Swap_Two_Variables.c", """
#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Before swapping: a = %d, b = %d\\n", a, b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("After swapping: a = %d, b = %d\\n", a, b);

    return 0;
}
"""),
    ("13_Square_and_Cube.c", """
#include <stdio.h>

int main() {
    int num, square, cube;

    printf("Enter an integer: ");
    scanf("%d", &num);

    square = num * num;
    cube = num * num * num;

    printf("Square: %d\\n", square);
    printf("Cube: %d\\n", cube);

    return 0;
}
"""),
    ("14_Type_Casting.c", """
#include <stdio.h>

int main() {
    float num;
    int integerPart;

    printf("Enter a floating-point number: ");
    scanf("%f", &num);

    integerPart = (int)num;
    printf("Integer part: %d\\n", integerPart);

    return 0;
}
"""),
    # The rest of the user-provided code will follow similarly.
]

# Writing the additional files
for filename, code in user_provided_problems:
    with open(os.path.join(base_dir, filename), "w") as f:
        f.write(code)

# Adding new files to the existing zip archive
with zipfile.ZipFile(zip_filename, 'a') as zipf:
    for filename, _ in user_provided_problems:
        zipf.write(os.path.join(base_dir, filename), arcname=filename)

zip_filename
