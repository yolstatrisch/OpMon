/*
Player.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Contient la définition de la classe Player
*/
#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_

#include <iostream>
#include <vector>
#include "OpTeam.hpp"
#include "../objects/item/Item.hpp"
#include <SFML/Graphics.hpp>
/**
Classe représentant le joueur
*/
class Player {
    public:
        Player(std::string const& name);
        Player();
        OpTeam *getOpTeam();
        /**Ajoute un item au sac*/
        void addItem(int itemID);
        /**Renvoie le nombre d'exemplaires dans le sac de l'item donné en paramètres*/
        int checkItem(int itemID);
        /**Enlève un exemplaire de l'item dans le sac donné en paramètres*/
        bool deleteItem(int itemID);
        std::string getName() const {
            return name;
        }
        const std::string* getNameP() const{
            return &name;
        }
        void setName(std::string const &name) {
            this->name = name;
        }
        int getTrainerID() const {
            return trainerID;
        }
        void addOpMonToPC(OpMon *toAdd) {
            pc.push_back(toAdd);
        }
        OpMon *getOp(int ID) const {
            return opteam[ID];
        }
        OpMon *getPcOp(int ID) const {
            return pc[ID];
        }
        /**Soigne tous les Poké*/
        void healOp();
        /**Essaie d'ajouter un pokémon a l'opteam. Renvoie false si ce n'est pas possible*/
        bool addOpToOpTeam(OpMon *toAdd);

        void save();
        Player(std::ifstream &in, std::string &name);

        void setMap(int ID) {
            mapID = ID;
        }
        sf::Sprite &getSprite() {
            return persSprite;
        }
        int getppDir() {
            return *ppDir;
        }
        void setppDirPointer(int *ppDir) {
            this->ppDir = ppDir;
        }
        void setppDir(int ppDir) {
            *(this->ppDir) = ppDir;
        }
        /**Translation : pers(onnage) = character
        Sorry if I put it in public, I need it for in Overworld
        DON'T USE!!! Use getSprite instead!
        */
        //DontUse
        sf::Sprite persSprite;

        bool gameIsOver = false;
    private:
        std::string name;
        const unsigned int trainerID;//jusqu'a 8 chiffres (Hexadecimal) (jusqu'a 16^8 soit 4 octets soit un int)
        int bag[ITEM_NUMBER];
        std::vector<OpMon *> pc = std::vector<OpMon *>();
        OpTeam opteam = OpTeam("temp");
        int *ppDir;
        int mapID = 0;
};

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_ */
