/**
 * @file CookingRecipe.h
 * @brief Header file for the CookingRecipe struct.
 * struct is a CookingRecipe and contains its name,time,cal,ingredient and ID.
 * It also contains functions to get the ID and print the details of the CookingRecipe.
 */

#ifndef COOKINGRECIPE_H
#define COOKINGRECIPE_H



#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>

/**
 * @struct CookingRecipe
 * @brief The CookingRecipe struct is a recipe of dish.
 */
struct CookingRecipe
        {
    /** The ID parameter value*/
    static const int idParam = 3;

    /**The name of the CookingRecipe*/
    std::string name;

    /**The time of the CookingRecipe*/
    int time;

    /**Calorie content of the dish*/
    int  cal ;

    /**Pairs <Name of the  Ingredient, value>*/
    std::vector<std::pair<std::string, int > >  ingredient;

    /**The ID of the CookingRecipe */
    std::string id;

    /**
     * @brief Default constructor for CookingRecipe
     */
    CookingRecipe();

    /**
     *@brief Constructor for CookingRecipe.
     *@param Name_ The name of the CookingRecipe
     *@param Time_ The time of the CookingRecipe
     *@param Cal_ The cal of the CookingRecipe
     *@param Ingredient_ The ingredient of the CookingRecipe
     */
    CookingRecipe(std::string, int , int , std::vector<std::pair<std::string, int >>);

    /**
     *@brief Print the details of the CookingRecipe
     */
    void print();
    /**
     *@brief Generate ID of the CookingRecipe.
     *@param name The name of the CookingRecipe
     *@param hashParam The hash parameter value
     *@return The ID of the CookingRecipe
     */
    static std::string getID(std::string, int);
};

/**
 * @class Hash
 *
 * @brief Provides hashing functionality for strings.
 */
class Hash{
private:
    /**
     * @brief A prime number used for hashing.
     */
    static const int p = 1234567891; // prime

    /**
     * @brief Removed default constructor.
     */
    Hash();
public:
    /**
     * @brief Computes a hash for the given string using the specified length.
     *
     * @param string The string to hash.
     * @param length The length of the string to hash.
     *
     * @return The computed hash value.
     */
    static int getHash(const std::string word, int k){
        int len = word.length();
        int range = len;
        if(k < range && k > 0) range = k;
        int hash = k;

        for(int i = 0; i < range; i++){
            hash = (hash<<5)^(hash>>27)^word[i];
        }
        return hash % p;
    }
};

/**
 * @class reg
 * @brief A class to check the validity of CookingRecipe IDs.
 */
class reg{
private:
    /**
     * @brief Removed default constructor.
     */
    reg();
public:
    /**
     * @brief A regular expression used to match valid CookingRecipe IDs.
     */
    static inline const std::regex id_regex{R"(<CookingRecipe><[A-Za-z]{3}><[0-9]+>)"};

    /**
     * @brief A function to check if a string matches the CookingRecipe ID regex pattern.
     * @param string A string to be checked.
     * @return True if the string matches the regex pattern, false otherwise.
     */
    static bool check(std::string str)
    {
        return std::regex_match(str, id_regex);
    }
};

#endif //  COOKINGRECIPE_H
