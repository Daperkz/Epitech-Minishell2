/*
** EPITECH PROJECT, 2025
** my_math.h
** File description:
** my_math
*/

#ifndef MY_MATH_H_
    #define MY_MATH_H_

    #define PI 3.14159265359
    #define E 2.71828

    #define RAND_F (rand() / (RAND_MAX + 1.0))

    // Calculates the absolute value
    #define ABS(x) ((x) < 0 ? -x : x)
    // Returns the sign of x
    #define SIGN(x) my_sign(x)
    // Returns the smaller of two values
    #define MIN(x, y) (x < y ? x : y)
    // Returns the larger of two values
    #define MAX(x, y) (x > y ? x : y)

int my_sign(int x);
int my_isneg(int nb);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_ipow(int n, int p);

// Returns the factorial of n
long my_factorial(int n);
// Returns the exponential of n
//double my_exp(int n);

//functions found in the rounds.c

// Calculates the ceiling of a value (towards inf)
int my_ceil(double x);
// Calculates the floor of a value (towards -inf)
int my_floor(double x);
// Returns the nearest Integer
int my_round(double x);
// Returns the Integer part by truncating toward zero
int my_trunc(double x);

#endif /* !MY_MATH_H_ */
