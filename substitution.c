#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int verificacion_clave(string clave);
int verificacion_alpha_mayus(string clave);
string encriptacion(string mensaje, int longitud_mensaje, string clave);

int main(int argc, string argv[])
{
    if (argv[1] == 0)
    {
        printf("error, no hay clave\n");
        return 1;
    }
    else if (argv[2] != 0)
    {
        printf("Hay exceso de argumentos\n");
        return 1;
    }

    int longitud_clave = strlen(argv[1]);
    string clave = argv[1];

    if (longitud_clave == 26)
    {
        verificacion_alpha_mayus(clave); // hace todo mayuscula

        verificacion_clave(clave); // verifica que no se repitan letras

        if (verificacion_alpha_mayus(clave) == 0 && verificacion_clave(clave) == 0)
        {
            string mensaje = get_string("Por favor introduce tu mensaje: ");
            int longitud_mensaje = strlen(mensaje);

            encriptacion(mensaje, longitud_mensaje, clave);
        }
        else
        {
            return 1;
        }
    }
    else
    {
        printf("La clave debe tener 26 caracteres\n");
        return 1;
    }
}

// funcion para verificar que los caracteres no sean iguales unos de otros

int verificacion_clave(string clave)
{
    int j = 1;
    for (int i = 0; i < 26; i++)
    {
        while (j < 26)
        {

            if (clave[i] == clave[j])
            {
                printf("hay letras repetidas\n");
                return 1;
            }

            j++;
        }

        j = i + 2;
    }

    return 0;
}

// funcion para cambiar las minusculas a mayusculas y si es alfabetico

int verificacion_alpha_mayus(string clave)
{
    for (int i = 0; i < 26; i++)
    {
        if (clave[i] <= 122 && clave[i] >= 65) // Limitamos para que solo entren valores alfabeticos
        {
            if (clave[i] <= 122 &&
                clave[i] >= 97) // ahora limitamos para que entren valores alfabeticos en minuscula
            {
                clave[i] = clave[i] - 32; // lo que esta en minuscula lo convertimos a mayuscula
                                          // para compara mas facil entre letras repetidas
            }
        }

        else
        {
            printf("Hay caracteres no alfabeticos\n");

            return 1;
        }
    }

    return 0;
}

// funcion para encriptar mensaje

string encriptacion(string mensaje, int longitud_mensaje, string clave)
{
    for (int i = 0; i < longitud_mensaje; i++)
    {
        if (mensaje[i] >= 97 && mensaje[i] <= 122)
        {
            int posicion = mensaje[i] - 'a';

            mensaje[i] = clave[posicion] + 32;
        }
        else if (mensaje[i] >= 65 && mensaje[i] <= 90)
        {
            int posicion = mensaje[i] - 'A';

            mensaje[i] = clave[posicion];
        }
    }
    printf("texto encriptado: %s\n", mensaje);

    return 0;
}
