// Praktikum 6
// 22.12.2022
// Ole Pearse-Danker; Tom Dora
// Kommandozeilenparameterausgabe; Textdatei Verschlüsseln; Vektor Positionen
// Version 1.0

#define _CRT_SECURE_NO_WARNINGS

#define TASK_2

#include <stdio.h> // includes scanf/printf
#include <stdlib.h> // includes system function, exit function
#include <string.h> // includes the strlen function -> gives us the length of an string
#include <ctype.h> // includes the toUpper function
#include <stdbool.h> // allows us to use bool variable


// Funktionsdefinitionen Aufgabe 2
void encrypt(unsigned char c[], int key);
void decrypt(unsigned char c[], int key);
short get_short(char text[], short MIN, short MAX);
void make_upper(char* s);

// Funktionsdefinitionen Aufgabe 3
int* find_int(int array[], int array_length, unsigned int searched_value);


int main(int argc, char* argv[]) // argc -> number of arguments that we get, argv -> array of strings

{

    //------------------------------------
    // Aufgabe 1 
    // Kommandozeilenparameter
    //------------------------------------

#ifdef TASK_1

    system("cls");
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

    system("cls");

    FILE* fptr; //File pointer to work with the file

    //This is the pointer to a FILE object that identifies the stream where characters are read from

    fptr = fopen("input.txt", "r"); // Connecting C program to external file "input"

    // "r" opening the file in read mode / "w" -> opening the file in write mode (or creating the file first of all)

    char content[10000]; // creating array to store the file content

    // reading from txt file and storing it in this array

    if (fptr != NULL) //if file opening is successful -> opening was successful
    {
        while (fgets(content, 10000, fptr)) // using fgets function to read the content of a file (fptr) and store content in "content" //fgets can only read the first sentence at a time -> while loop to read everything
        {



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

    char c[27];     //Char Array mit 27 Stellen
    c[26] = 0;      //damit c weiß, dass dass dort die Zeichenkette aufhört (sobald man die 0 findet -> Array ist zu Ende)
    for (int i = 0; i < 26; i++)
    {
        c[i] = 'A' + i;
        printf(" %c ", c[i]);
    }

    printf("\n\n");


    char* key = argv[3];              // A number written in the input.txt is a CHARACTER number NOT an INTEGER so we have to convert it to be able to use it 

    int key_in_int = atoi(key);       // conversion from ascii value to integer with atoi function from stdlib library


    printf("Verschiebung in int: %d\n", key_in_int);


    encrypt(content, key_in_int); // function to encrypt input

    fptr = fopen("output.txt", "w"); // opening output file in write mode / when there is no output file yet, this will create one

    fputs(content, fptr); // pasting encrypted content into the output with the fputs function


    decrypt(content, key_in_int); // function to decrypt input

    fptr = fopen("output_decoded.txt", "w");
    fputs(content, fptr);

    fclose(fptr); //closing files after working with it

    return 0;
#endif

    //------------------------------------
    // Aufgabe 3 
    // Position eines Integers in Array
    //------------------------------------

#ifdef TASK_3

    system("cls"); // clearing terminal for better UX

    //------------------------------------------
    // Aufgabe 3

    printf("------------------------------------------------------------------------------------------------\n");
    printf("Das folgende Programm berechnet ihnen die Position eines gesuchten Wertes innerhalb eines Arrays\n");
    printf("------------------------------------------------------------------------------------------------\n");

    int array[] = { 1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5,0,2,8,8,4,1,9,7,1,6,9,3,9,9,3,75 };
    size_t original_length = sizeof(array) / sizeof(int); // sizeof function returns the size in bytes that it takes to store this array

    int searched_number;

    bool allowed;

    printf("\n");

    for (size_t i = 0; i < original_length; i++) // size_t is used instead of an integer because sizeof funktion returns size_t and not an int -> if you dont do this, c is converting an size_t to an integer in the background
    {
        printf("%2d", array[i]);
    }

    printf("\n");

    do
    {
        searched_number = get_short("\nWaehlen Sie eine Zahl aus dem Array (1-75)", 1, 75); // getting input from the user 

        allowed = true; // bool that is always correct to be able to keep repeating the user prompt and following finding of the int

        printf("\n");

        bool end_of_array = false;  // Bool wird erst einmal auf false gesetzt, damit wir den Fall true als Abbruch - Bedingung für die Do-while Schleife benutzen können
        int* current_index = NULL;  // pointer für den aktuellen Index definieren und erstmal aus NULL setzen
        int* first_index = NULL;    // pointer für den ersten Index definieren und erstmal auf NULL setzen

        // current_index = array;
        current_index = &array[0];  //current Index zeigt nun auf die Adresse des ersten Elements des Arrays
        first_index = &array[0];    //first Index zeigt nun auf die Adresse des ersten Elements des Arrays

        size_t arr_len_from_current_index = original_length; // array length from current index is set to the length of the first array length

        do
        {
            current_index = find_int(current_index, arr_len_from_current_index, searched_number); //function to find int in array

            if (current_index == NULL)
            {
                end_of_array = true; // if the the find_int function returned NULL -> end of array is reached, so we can break out of the loop
            }
            else
            {
                printf("Die Zahl %d wurde an dieser Adresse gefunden %p\n", *current_index, current_index);
                current_index++;    
                arr_len_from_current_index = original_length - (current_index - first_index); // calculation length of the remaining array
            }
        } while (!end_of_array); // if end of array is reached -> break out of the loop


    } while (allowed);

    return 0;

#endif

}

// Funktionsdeklarationen

void encrypt(unsigned char c[], int key)
{

    printf("------------------------\n");
    printf("ENCODED:\n");

    for (int i = 0; c[i] != 0; i++) // continue iterating until end of length of string (/0)
    {
        if (c[i] >= 65 && c[i] <= 90) // ascii range of all uppercase characters (33-64)
        {
            c[i] += key;
            if (c[i] > 90) // if c[i] is bigger than 'Z' (90 is the Ascii value of 90) -> substract 26 (to get a valid character)
            {
                c[i] = c[i] - 26; // 
            }

            printf("%c", c[i]);

        }
        else                            //task states that only special characters must not be encrypted, hence only printing
        {
            printf("%c", c[i]);
        }
    }

    printf("\n");

    return;

}

void decrypt(unsigned char c[], int key)
{

    printf("------------------------\n");
    printf("DECODED:\n");

    for (int i = 0; c[i] != 0; i++) // solange durch die Schleife gehen bis man keine 0 mehr in der Zeichenkette hat (\0 ist die NUll Terminierung eines strings)
    {

        if (c[i] >= 65 && c[i] <= 90) // ascii range of all uppercase characters (65-90)
        {
            c[i] -= key;
            if (c[i] < 65) // if c[i] is smaller than 'Z' (65 is the Ascii value) -> add 26 to get valid 
            {
                c[i] = c[i] + 26;
            }


            printf("%c", c[i]);
        }
        else                            //task states that only special characters must not be encrypted, hence only printing
        {
            printf("%c", c[i]);
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

int* find_int(int* array, int array_length, unsigned int searched_value)
{
    for (int i = 0; i < array_length; i++)
    {
        printf("%2d", array[i]);
    }

    printf("\n\n");


    // pointer to the address of the searched value in array
    int* parray = NULL;

    for (int i = 0; i < array_length; i++)
    {
        if (array[i] == searched_value)
        {
           
            parray = &array[i];
            return &array[i];
        }
    }
    return NULL;

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

