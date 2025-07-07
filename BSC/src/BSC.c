// Basic Scientific Calculator - (EN/US) - V 1.0.0 - Stable Release.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Print (double F_Num, double S_Num, int Op);
double Calc (double F_Num, double S_Num, int Op);

int main (void) {

    char Op_Input[16], F_Num_In[40], S_Num_In[40];
    double F_Num = 0, S_Num = 0;
    int Op = 0;

    puts ("Welcome to Basic Scientific Calculator!\n");

    while (1) {

        for (int i = 0; i < 2; i++) { Op_Input[i] = 0; }
        for (int i = 0; i < 39; i++) { F_Num_In[i] = '_', S_Num_In[i] = '_'; }
        F_Num = 0, S_Num = 0, Op = 0;

        puts ("What operation would you like to do?:\n");
        puts ("1 - '+'.");
        puts ("2 - '-'.");
        puts ("3 - '*'.");
        puts ("4 - '/'.");
        puts ("5 - 'Mod(x, y)'.");
        puts ("6 - '%' (X percent of Y).");
        puts ("7 - '%' (X percentage of Y).");
        puts ("8 - '^'.");
        puts ("9 - 'Root(x, n)'.");
        puts ("10 - 'Log_2(x)'.");
        puts ("11 - 'Log_10(x)'.");
        puts ("12 - 'Log_e(x)'.");
        puts ("13 - Exit.\n");

        printf ("Option: ");
        fgets (Op_Input, sizeof (Op_Input), stdin);

        if (isdigit ((unsigned char) Op_Input[0]) || isdigit ((unsigned char) Op_Input[1])) { Op = atoi (Op_Input); }
        else { puts ("\nERROR: Your input is not a valid number. Restarting...\n\n"); continue; }

        if (Op > 9 && Op < 13) { printf ("\n\nX = "); fgets (F_Num_In, sizeof (F_Num_In), stdin); }
        else if (Op == 9) {
            
            printf ("\n\nRadicand: ");
            fgets (F_Num_In, sizeof (F_Num_In), stdin);

            printf ("\nIndex: ");
            fgets (S_Num_In, sizeof (S_Num_In), stdin);

        } else if (Op == 8) {
            
            printf ("\n\nBase: ");
            fgets (F_Num_In, sizeof (F_Num_In), stdin);

            printf ("\nExponent: ");
            fgets (S_Num_In, sizeof (S_Num_In), stdin);

        } else if (Op == 7) {
            
            printf ("\n\nPortion: ");
            fgets (F_Num_In, sizeof (F_Num_In), stdin);

            printf ("\nWhole: ");
            fgets (S_Num_In, sizeof (S_Num_In), stdin);

        } else if (Op == 6) {
            
            printf ("\n\nPercentage: ");
            fgets (F_Num_In, sizeof (F_Num_In), stdin);

            printf ("\nWhole: ");
            fgets (S_Num_In, sizeof (S_Num_In), stdin);

        } else if (Op == 5) {
            
            printf ("\n\nType x (x mod y): ");
            fgets (F_Num_In, sizeof (F_Num_In), stdin);

            printf ("\nType y (x mod y): ");
            fgets (S_Num_In, sizeof (S_Num_In), stdin);

        } else if (Op > 0 && Op < 5) {
            
            printf ("\n\nFirst Number: ");
            fgets (F_Num_In, sizeof (F_Num_In), stdin);

            printf ("\nSecond Number: ");
            fgets (S_Num_In, sizeof (S_Num_In), stdin);

        } else if (Op == 13) { puts ("\nStopping...\n"); return 0; }
        else { puts ("\nERROR: The option is out of range. Restarting...\n\n"); continue; }

        F_Num = atof (F_Num_In), S_Num = atof (S_Num_In);

        if ((Op == 4 || Op == 5 || Op == 7 || Op == 9) && S_Num == 0) { puts ("\nERROR: Zero is not allowed. Restarting...\n\n"); continue; }
        else if (Op > 9 && Op < 13 && F_Num <= 0) { puts ("\nERROR: Zero and negative numbers aren't allowed. Restarting...\n\n"); continue; }
        else if (Op == 9 && F_Num < 0 && (int) S_Num % 2 == 0) { puts ("\nERROR: Invalid root - negative number. Restarting...\n\n"); continue; }

        if (Print (F_Num, S_Num, Op) == 0) { return 0; }
        else { continue; }
    }
}

int Print (double F_Num, double S_Num, int Op) {

    printf ("\nCalculating...\n\n");

    double Result = Calc (F_Num, S_Num, Op);
    char Ext_Ask[16];

    switch (Op) {

        case 1: { printf ("\n%f + %f = %f\n\n", F_Num, S_Num, Result); break; }
        case 2: { printf ("\n%f - %f = %f\n\n", F_Num, S_Num, Result); break; }
        case 3: { printf ("\n%f * %f = %f\n\n", F_Num, S_Num, Result); break; }
        case 4: { printf ("\n%f / %f = %f\n\n", F_Num, S_Num, Result); break; }
        case 5: { printf ("\n%f mod %f = %f\n\n", F_Num, S_Num, Result); break; }
        case 6: { printf ("\n%f %% %f = %f\n\n", F_Num, S_Num, Result); break; }
        case 7: { printf ("\n%f %% %f = %f%%\n\n", F_Num, S_Num, Result); break; }
        case 8: { printf ("\n%f ^ %f = %f\n\n", F_Num, S_Num, Result); break; }
        case 9: { printf ("\n%f-th root of %f = %f\n\n", S_Num, F_Num, Result); break; }
        case 10: { printf ("\nLog_2(%f) = %f\n\n", F_Num, Result); break; }
        case 11: { printf ("\nLog_10(%f) = %f\n\n", F_Num, Result); break; }
        case 12: { printf ("\nLog_e(%f) = %f\n\n", F_Num, Result); break; }
    }

    while (1) {

        printf ("\nWould you like to quit? (Y/N): ");
        fgets (Ext_Ask, sizeof (Ext_Ask), stdin);

        if (Ext_Ask[0] == 'Y' || Ext_Ask[0] == 'y') { puts ("\nStopping...\n"); return 0; }
        else if (Ext_Ask[0] == 'N' || Ext_Ask[0] == 'n') { puts ("\nRestarting...\n\n"); return 1; }
        else { puts ("\nERROR: Invalid option.\n"); }
    }
}

double Calc (double F_Num, double S_Num, int Op) {

    switch (Op) {

        case 1: { return F_Num + S_Num; break; }
        case 2: { return F_Num - S_Num; break; }
        case 3: { return F_Num * S_Num; break; }
        case 4: { return F_Num / S_Num; break; }
        case 5: { return fmod (F_Num, S_Num); break; }
        case 6: { return F_Num / 100 * S_Num; break; }
        case 7: { return F_Num / S_Num * 100; break; }
        case 8: { return pow (F_Num, S_Num); break; }

        case 9: {

            if (F_Num < 0 && (int) S_Num % 2 != 0) { return -pow (-F_Num, 1.0 / S_Num); }
            else { return pow (F_Num, 1.0 / S_Num); }

            break;
        }

        case 10: { return log2 (F_Num); break; }
        case 11: { return log10 (F_Num); break; }
        case 12: { return log (F_Num); break; }
    }
}