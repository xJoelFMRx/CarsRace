#include "Coche.h"

void IniciarCarrera()
{
    srand(time(nullptr));
    Coche* coche1 = new Coche();
    Coche* coche2 = new Coche(1, 20, 2);
    Coche* coche3 = new Coche(1, 35, 3);
    bool iniciarCarrera = false;
    char tecla;

    coche1->DibujarCoche();
    coche2->DibujarCoche();
    coche3->DibujarCoche();
    while (!iniciarCarrera)
    {
        if (_kbhit())
        {
            tecla = toupper(_getch());
            if (tecla == 'G')
            {
                iniciarCarrera = true;
            }
        }
    }
    while (!(coche1->LlegarMeta() || coche2->LlegarMeta() || coche3->LlegarMeta()))
    {
        //Borrar
        coche1->BorrarCoche();
        coche2->BorrarCoche();
        coche3->BorrarCoche();
        //Mover
        coche1->MoverCoche();
        coche2->MoverCoche();
        coche3->MoverCoche();
        //Dibujar
        coche1->DibujarCoche();
        coche2->DibujarCoche();
        coche3->DibujarCoche();
        _sleep(50);

        if (coche1->LlegarMeta())
        {
            string mensaje = "EL COCHE 1 GANA!!";
            system("cls");
            Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
            cout << mensaje;
            break;
        }
        if (coche2->LlegarMeta())
        {
            string mensaje = "EL COCHE 2 GANA!!";
            system("cls");
            Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
            cout << mensaje;
            break;
        }
        if (coche3->LlegarMeta())
        {
            string mensaje = "EL COCHE 3 GANA!!";
            system("cls");
            Console::SetCursorPosition(ANCHO_CONSOLA / 2 - mensaje.size() / 2, ALTO_CONSOLA / 2);
            cout << mensaje;
            break;
        }
    }
    delete coche1;
    delete coche2;
    delete coche3;
}

int main()
{
    Ventana();
    IniciarCarrera();

    system("pause>0");
    return 0;
}
