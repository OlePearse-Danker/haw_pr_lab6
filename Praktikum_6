#define _CRT_SECURE_NO_WARNINGS

#define TASK_2

#include <stdio.h> // includes scanf/printf
#include <stdlib.h> // includes system function, exit function
#include <string.h> // includes the strlen function -> gives us the length of an string
#include <ctype.h> // includes the toUpper function
#include <stdbool.h> // allows us to use bool variable


// Funktionsdefinitionen Aufgabe 2
void encrypt(unsigned char c[], int verschiebung);
void decrypt( unsigned char c[], int verschiebung);
short get_short(char text[], short MIN, short MAX);
void make_upper(char* s);

// Funktionsdefinitionen Aufgabe 3
int *find_int(int array[], int array_length, unsigned int searched_value);


int main(int argc, char* argv[]) // argc -> number of arguments that we get, argv -> array of strings

{

    //------------------------------------
    // Aufgabe 1 
    // Kommandozeilenparameter
    //------------------------------------

#ifdef TASK_1

    system("clear");
    printf("Anzahl der Argumente: %d\n", argc); // man bekommt immer eins mehr als die angegebenen Argumente, weil das Programm selbst als Argument angesehen wird

    // um zu starten im Terminal eingeben: ./parameter Guten Tag 123 // oder unter WIN -> Praktikm 6  Debug Properties

    for (int i = 0; i < argc; i++)
    {
        printf("Parameter [%d] = \"%s\"\n", i, argv[i]);
    }
    return 0;

#endif

    //------------------------------------
    // Aufgabe 2 
    // Caeser-Verschlüsselung 
    //------------------------------------


#ifdef TASK_2

    system("clear");

    FILE* fptr; //File pointer to work with the file

    //This is the pointer to a FILE object that identifies the stream where characters are read from

    fptr = fopen("input.txt", "r"); // Connecting C program to external file "input"

    // "r" opening the file in read mode / "w" -> opening the file in write mode (or creating the file first of all)

    char content[100]; // creating array to store the file content

    // reading from txt file and storing it in this array

    if (fptr != NULL) //if file opening is successful -> opening was successful
    {
        while (fgets(content, 100, fptr)) // using fgets function to read the content of a file (fptr) and store content in "content" //fgets can only read the first sentence at a time -> while loop to read everything
        {

            printf("CONTENT READ:\n");

            printf("%s", content); // 100 is the size of the file 

            // fptr is the pointer used to read the file 

        }

        printf("\n");
    }
    else
    {
        printf("File open unsuccessful");
    }

    make_upper(content); // gets length of a string and makes all letters upper case

    // char ch;
    // printf("Enter a value: ");
    // scanf("%c" ,&ch);
    // printf("%d", ch);

    //-------------------------------------

    // Verschlüsselung

    //-------------------------------------

    //Ausgabe des Alphabets

    printf("\n");

    char c[27];

    // c[26] = 0; // 26. Element wird auf Null gesetzt 

    for (int i = 0; i < 26; i++)
    {
        c[i] = 'A' + i;
        printf(" %c ", c[i]);
    }

    printf("\n\n");

    


    char *verschiebung = argv[3];

    int verschiebung_result = atoi(verschiebung);


    printf("Verschiebung in int: %d\n", verschiebung_result);

    //*verschiebung = argv[2];

    //verschiebung = get_short("Um wie viele Stellen soll die Nachricht verschoben werden? ", 1, 25);

    encrypt(content, verschiebung_result); // function to encrypt input

    fptr = fopen("output.txt", "w");

    fputs(content, fptr); // pasting encrypted content into the output with the fputs function

    decrypt(content, verschiebung_result); // 

    fclose(fptr); //closing files after working with it

    return 0;
#endif

    //------------------------------------

    // Aufgabe 3 

    // Position eines Integers in Array

    //------------------------------------

#ifdef TASK_3

    system("clear"); // clearing terminal for better UX

    //------------------------------------------
    // Aufgabe 3

    int array[] = { 1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5,0,2,8,8,4,1,9,7,1,6,9,3,9,9,3,75 };
    int length = sizeof(array) / sizeof(int); // sizeof function returns the size in bytes that it takes to store this array

    int number;

    bool allowed;

    printf("\n");

    for (size_t i = 0; i < length; i++)
    {
        printf("%2d", array[i]);
    }

    printf("\n");
    

    // printf("1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4 6 2 6 4 3 8 3 2 7 9 5 0 2 8 8 4 1 9 7 1 6 9 3 9 9 3 75\n\n");

    do
    {
        number = get_short("\nWaehlen Sie eine Zahl aus dem Array", 1, 75); // getting input from the user 

        allowed = true;

        printf("\n");

        // so we have to divide it by the size in bytes that it takes to store an int)
        bool end_of_array = false;
        int *current_index = NULL;
        int *first_index = NULL;

        // current_index = array;
        current_index = &array[0];
        first_index = &array[0];

        size_t arr_len_from_current_index = length;

        do
        {
            current_index = find_int(current_index, arr_len_from_current_index, number); //function to find int in array

            if (current_index == NULL)
            {
                end_of_array = true;
            }
            else
            {
                printf("Found int %d at pos: %p\n", *current_index, current_index);
                current_index++;
                arr_len_from_current_index = length - (current_index - first_index);
            }
        } while (!end_of_array);

    } while (allowed);

    return 0;

#endif

}

// Funktionsdeklarationen

void encrypt(unsigned char c[], int verschiebung)
{

    printf("------------------------\n");
    printf("ENCODED:\n");

    for (int i = 0;  c[i] != 0; i++) // continue iterating until end of length of string
    {

        if (c[i] >= 65 && c[i] <= 90) // ascii range of all uppercase characters (33-64)
        {

            c[i] += verschiebung;
            printf(" %c ", c[i]);

        }
        else
        {
            printf(" %c ", c[i]);
        }

    }

    printf("\n");

    return;

}

void decrypt(unsigned char c[], int verschiebung)
{

    printf("------------------------\n");
    printf("DECODED:\n");

    for (int i = 0; c[i] != 0; i++) // solange durch die Schleife gehen bis man keine 0 mehr in der Zeichenkette hat (\0 ist die NUll Terminierung eines strings)
    {

        if (c[i] >= 65 && c[i] <= 90) // ascii range of all uppercase characters (65-90)
        {
            c[i] -= verschiebung;
            printf(" %c ", c[i]);
        }
        else
        {
            printf(" %c ", c[i]);
        }

    }

    printf("\n");
    return;

}

void make_upper(char* s)
{
    int length = strlen(s); // gets the length of a string

    for (int i = 0; i < length; i++)
    {
        s[i] = toupper(s[i]); // toupper takes in the character as an argument and if it is lowerCase it will make it upperCase

    } // if the character is already an upper case letter it will do nothing 

}

int *find_int(int *array, int array_length, unsigned int searched_value)
{
    for (int i = 0; i < array_length; i++)
    {
        printf("%2d", array[i]);
    }

    printf("\n\n");

    int anzahl = 0; // keeps track of the amount of times the number has been found in the array

    // pointer to the address of the searched value in array
    int *parray = NULL;

    for (int i = 0; i < array_length; i++)
    {
        if (array[i] == searched_value)
        {
            anzahl++;
            parray = &array[i];
            return &array[i];
        }
    }
    return NULL;

    // if (anzahl > 0)
    // {
    //     printf("\nDie Zahl %d kommt %d mal in dem Array vor.\n", searched_value, anzahl);
    //     return &parray[0];
    // }

    // else
    // {
    //     printf("Die Zahl %d existiert in diesem Array nicht.\n", searched_value);
    //     return NULL;
    // }
}



short get_short(char text[], short MIN, short MAX)
{
    //declare working variables 
    short value;
    int finished = 0; //0 für FALSE
    char ch;
    int retVal;

    do
    {
        printf("%s: ", text); //Abkürzung "s" für "string" / Zeichenkette
        ch = '\0'; // \0 wird als ein Buchstabe gewertet; O ist nicht die Zahl 0 sondern ein "Null Character"; Null Character hat in der Ascii Tabelle auch den Wert 0
        retVal = scanf("%hd%c", &value, &ch); // -> "hd" steht für short -> Adresse ist "Value"; scanf gibt auch einen Wert zurück, diesen speichern wir in retVal 
        // check for valid user input
        if (retVal != 2)
        {
            printf("Das war keine korrekte Zahl!\n");
            #ifdef TASK_3 // when we have invalid input, only task 3 demands to exit program immediately, thus #ifdef TASK_3
            exit(EXIT_FAILURE);
            #endif
        }

        else if (ch != '\n')
        {
            printf("Unerwartete Zeichen hinter der Zahl!\n");
            #ifdef TASK_3
            exit(EXIT_FAILURE);
            #endif
        }

        else if (value < MIN)
        {
            printf("Zahl ist zu klein (MIN: %hd)\n", MIN);
            #ifdef TASK_3
            exit(EXIT_FAILURE);
            #endif
        }

        else if (value > MAX)
        {
            printf("Zahl ist zu gro%c (MAX: %hd)\n", 225, MAX);

            #ifdef TASK_3
            exit(EXIT_FAILURE);
            #endif
        }

        else finished = 1;  //falls die Variable tatsächlich 2 ist; und der character ein newline, ist alles richtig und die loop wird beendet
                            //Variable finished wird auf 1 gesetzt -> weil 1 für TRUE
                            //clear input stream buffer

        while (ch != '\n') scanf("%c", &ch); //Variation mit scanf von getchar

    } while (!finished); //repeat if not finished 

    //return user input
    return value; //wer auch immer die Funktion get_short aufruft bekomm "value" zurück
}
