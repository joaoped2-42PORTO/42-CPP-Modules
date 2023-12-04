//
// Created by joaoped2 on 11/29/23.
//

#ifndef CPP_MODULES_42_CLAPTRAP_HPP
#define CPP_MODULES_42_CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    private:
        std::string Name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public:
        ClapTrap( std::string name);
        ClapTrap( const ClapTrap& cpy );
        ClapTrap& operator = ( const ClapTrap& claptrap );
        ~ClapTrap();
        void attack( const std::string& target );
        void takeDamage( unsigned  int amount);
        void beRapaired( unsigned int amount);

        //Getters
        void getName( void );
        void getHitPoints( void );
        void getEnergyPoints( void );
        void getAttackDamage( void );
        void giveDamage( unsigned int damage );
};

std::ostream &operator<<(std::ostream &out, const ClapTrap &teste);

#endif //CPP_MODULES_42_CLAPTRAP_HPP
