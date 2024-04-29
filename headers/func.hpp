#ifndef FUNC_H
#define FUNC_H

#include "reg.hpp"
#include "astro.hpp"
#include "voo.hpp"
#include "trip.hpp"
#include "morto.hpp"

void showTripul(Voo* voo, Registros<Tripulante*> &RegTripul);

void delTripul(Voo* voo, Astronauta* astro, Registros<Tripulante*> &RegTrip);

void limpezaGeral(Registros<Voo*> &RegVoos, Registros<Astronauta*> &RegAstro, Registros<Tripulante*> &RegTrip);

void explodeVoo(Voo* voo, Registros<Tripulante*> &RegTrip, Registros<Astronauta*> &RegAst, Registros<Morto*> &RegMortos);

void finalVoo(Voo* voo, Registros<Tripulante*> &RegTrip, Registros<Astronauta*> &RegAst);

void showMortos(Registros<Morto*> &RegMortos, Registros<Tripulante*> &RegTrip, Registros<Voo*> &RegVoos);

#endif
