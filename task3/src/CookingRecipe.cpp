/**
 * @file CookingRecipe.cpp
 * @brief Realization of CookingRecipe class
 */

#include "CookingRecipe.h"

CookingRecipe::CookingRecipe() = default;

CookingRecipe::CookingRecipe(std::string Name_, int  Time_,int  Cal_, std::vector<std::pair<std::string, int >> ingredient_){
    name = Name_;
    time = Time_;
    cal = Cal_;
    ingredient = ingredient_;
    id = getID(name, ingredient_.size());
}

void CookingRecipe::print(){
    std::cout << "Name = " << name << std::endl
            << "Time = " << time << std::endl
            << "Cal = " << cal << std::endl
            << "Ingredients : " << std::endl;

    for(int i = 0; i < ingredient.size(); i++){
        std::cout << i << ") Name = " << ingredient[i].first << " Rated = " << ingredient[i].second << std::endl;
    }
    std::cout << std::endl;
}

std::string CookingRecipe::getID(std::string name , int hashParam){
    std::string result = "<CookingRecipe><";
    result += name.substr(0, idParam) + "><";

    int temp = Hash::getHash(name, hashParam);
    result += std::to_string(temp) + ">";
    
    return result;
}

