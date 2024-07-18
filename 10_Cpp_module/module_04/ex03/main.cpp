#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    return 0;
}

// #include "MateriaSource.hpp"
// #include "Character.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"
// #include <iostream>

// int main() {
//     {
//         IMateriaSource* src = new MateriaSource();
//         src->learnMateria( new Ice() );
//         src->learnMateria( new Cure() );

//         ICharacter* me = new Character( "me" );

//         AMateria* tmp;

//         tmp = src->createMateria( "ice" );
//         me->equip( tmp );

//         tmp = src->createMateria( "cure" );
//         me->equip( tmp );

//         ICharacter* bob = new Character( "bob" );
//         me->use( 0, bob );
//         me->use( 1,bob );
//         delete bob;
//         delete me;
//         delete src;
//     }
//     {
//         std::cout << std::endl;
//         // system( "leaks ex03" );
//         std::cout << std::endl;
//     }

//     {
//         IMateriaSource* src = new MateriaSource();
//         src->learnMateria( new Ice() );
//         src->learnMateria( new Ice() );
//         src->learnMateria( new Cure() );
//         src->learnMateria( new Ice() );

//         // tmp == 5
//         AMateria* tmp;
//         tmp = new Cure();
//         src->learnMateria( tmp );

//         delete tmp;
//         std::cout << "Delete tmp Materia (cure)" << std::endl;

//         ICharacter* p1 = new Character( "Player1" );
//         tmp = src->createMateria( "ice" );
//         p1->equip( tmp );
//         tmp = src->createMateria( "cure" );
//         p1->equip( tmp );
//         p1->equip( NULL );  // slot[2] empty
//         tmp = src->createMateria( "cure" );
//         p1->equip( tmp );  // slot[2] filled

//         ICharacter* bob = new Character( "bob" );
//         std::cout << "0" << std::endl;
//         p1->use( 0, bob );
//         std::cout << "1" << std::endl;
//         p1->use( 1,bob );
//         std::cout << "2" << std::endl;
//         p1->use( 2, bob );
//         std::cout << "3" << std::endl;
//         p1->use( 3,bob );  // empty

//         delete bob;
//         delete p1;
//         delete src;
//     }
//     {
//         std::cout << std::endl;
//         // system( "leaks ex03" );
//         std::cout << std::endl;
//     }

//     return 0;
// }