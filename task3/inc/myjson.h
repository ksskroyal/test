/**
 * @file myjson.h
 * @brief Contains the definition of the myjson class for handling JSON data.
 * 
 * This class provides methods for reading data from a file or stream
 * in JSON format, manipulating the data, and writing the data back out
 * to a file or stream in JSON format.
 * 
 * @details The class uses the nlohmann::json library to handle the JSON data.
 */

#ifndef MYJSON_H
#define MYJSON_H

#include <stdio.h>
#include <fstream>
#include <nlohmann/json.hpp>

#include "CookingRecipe.h"

using json = nlohmann::json;

/**
 * @class myjson
 * @brief Handles JSON data for storing and manipulating CookingRecipe.
 */ 

class myjson{
private:
    json data;
    
public:
    /**
     * @brief Default constructor for myjson.
     */
    myjson();

    /**
     * @brief Constructor for myjson that takes a json in string format as an argument.
     * @param[in] json_string The JSON file in string format.
     */
    myjson(char*);

    /**
     * @brief Constructor for myjson that takes a file stream as an argument.
     * @param[in] file The file stream containing the JSON data.
     */
    myjson(FILE*);
    
    /**
     * @brief Reads input from the specified file stream into the JSON data.
     * @param[in] file The file stream containing the JSON data.
     */
    void Input(FILE*);

    /**
     * @brief Prints the JSON data to the console.
     */
    void Print();
    void Clear();
    /**
     * @brief Executes a command specified in the JSON data.
     * 
     * Sorts CookingRecipe which are currently stored in JSON data by menu variants and rating.
     */
    void Execute(int  time_min,int  time_max,int  cal_min,int  cal_max);

    /**
     * @brief Adds a CookingRecipe to the JSON data.
     * @param[in] CookingRecipe The CookingRecipe to add.
     */
    void Add(CookingRecipe);

    /**
     * @brief Deletes the CookingRecipe with the specified id from the JSON data.
     * @param[in] id The id of the CookingRecipe to delete.
     */
    void Delete(std::string);


    void Save(std::string);

    /**
     * @brief Dumps the JSON data to a string.
     * @return A string representation of the JSON data.
     */
    std::string Dump();

    /**
     * @brief Creates a JSON object from a CookingRecipe object.
     * @param[in] CookingRecipe The CookingRecipe to create a JSON object from.
     * @return A JSON object representing the CookingRecipe
     */
    static json CreateJSON(CookingRecipe);

    /**
     * @brief Finds theCookingRecipe with the specified id in the JSON data.
     * @param[in] id The id of the CookingRecipe to find.
     * @return A JSON object representing the CookingRecipe, or an empty object if the CookingRecipe is not found.
     */
    json FindCookingRecipe(std::string);
};


#endif // MYJSON_H
