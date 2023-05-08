/**
 * @file myjson.cpp
 * @brief Realization of myjson class
 */

#include "myjson.h"
#include <iostream>
#include <string>
#include <fstream>
myjson::myjson(){
    data = json({});
}

myjson::myjson(char* str){
    data = json::parse(str);
}

myjson::myjson(FILE* fin){
    Input(fin);
}

void myjson::Input(FILE* fin){
    data = json::parse(fin);
}

void myjson::Print(){
    std::string temp = data.dump(2);
    std::cout << temp << std::endl;
}

void myjson::Execute(int  MinTime, int  MaxTime, int  MinCal, int  MaxCal)
{
    size_t n = data["CookingRecipe"].size();
    double Time, Cal; double Value;
    std::string Name;
    std::vector<std::pair<std::string, double>> Ingredient;
    std::vector<CookingRecipe> recipe;
    recipe.reserve(n);
    for (int i = 0; i < n; i++)
    {
        if (MinTime <= data["CookingRecipe"][i]["Time"] && data["CookingRecipe"][i]["Time"] <= MaxTime
            && MinCal <= data["CookingRecipe"][i]["Cal"] && data["CookingRecipe"][i]["Cal"] <= MaxCal)

        {
            CookingRecipe rest;
            rest.name=data["CookingRecipe"][i]["Name"];
            rest.time=data["CookingRecipe"][i]["Time"];
            rest.cal=data["CookingRecipe"][i]["Cal"];

            for(int jj=0;jj < data["CookingRecipe"][i]["Ingredient"].size();jj++)
            {
                rest.ingredient.push_back({data["CookingRecipe"][i]["Ingredient"][jj]["Name"],
                                          data["CookingRecipe"][i]["Ingredient"][jj]["Value"]});

            }


            recipe.push_back(rest);
            std::cout <<rest.name;
        }
    }
    data.clear();
    for(int i = 0; i < recipe.size(); i++){
        Add(recipe[i]);}

}



void myjson::Clear(){
    data.clear();
}

void myjson::Add(CookingRecipe rest){
    data["CookingRecipe"] += CreateJSON(rest);
}

json myjson::CreateJSON(CookingRecipe tump){
    json tum;

    tum["Name"] = tump.name;
    tum["Time"] = tump.time;
    tum["Cal"] = tump.cal;
    tum["ID"] = tump.id;

    for(int i = 0; i < tump.ingredient.size(); i++){
        tum["Ingredient"][i]["Name"] = tump.ingredient[i].first;
        tum["Ingredient"][i]["Value"] = tump.ingredient[i].second;
    }

    return tum;
}

void myjson::Delete(std::string id){
    for(int i = 0; i < data["CookingRecipe"].size(); i++){
        if(data["CookingRecipe"][i]["Name"] == id){
            data["CookingRecipe"].erase(i);
        }
    }
}

json myjson::FindCookingRecipe(std::string id){
    std::string name;
    int cal, time;
    std::vector<std::pair<std::string, int>> rating; 

    bool flag = false;

    for(int i = 0; i < data["CookingRecipe"].size(); i++){
        if(data["CookingRecipe"][i]["ID"] == id){
            name = data["CookingRecipe"][i]["Name"];
            time = data["CookingRecipe"][i]["Time"];
            cal = data["CookingRecipe"][i]["Cal"];

            for(int j = 0; j < data["CookingRecipe"][i]["Ingredient"].size(); j++){
                std::pair<std::string, int> temp;
                for(auto& [key, value] : data["CookingRecipe"][i]["Ingredient"][j].items()){
                    if(key == "Name") temp.first = value;
                    if(key == "Value") temp.second = value;
                }
                rating.push_back(temp);
            }
            flag = true;
            break;
        }
    }
    if(flag){
        CookingRecipe result(name, time, cal, rating);
        return CreateJSON(result);
    }else{
        return nlohmann::json({});
    }
    return nlohmann::json({});
}

std::string myjson::Dump(){
    return data.dump(4, ' ');
}

void myjson::Save(std::string filename){
    std::ofstream fout(filename);
    fout << Dump();
    fout.close();
}
