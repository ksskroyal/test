/**
 * @file generator.h
 * @brief Header file for the Generator class.
 * 
 * Declaration of Generator class, which provides an ability to generate JSON files.
 * 
 */

#ifndef GENERATOR_H
#define GENERATOR_H

#include "CookingRecipe.h"

#include <stdio.h>
#include <fstream>
#include <ctime>

/**
 * @class Generator
 * @brief Generates random JSON file filled with random CookingRecipe.h
 *
 * This class generates random CookingRecipe.h objects using the data read from files.
 */
class Generator{
private:

	/** The maximum time a CookingRecipe can have. */
	int maxTime = 100;

	/** The maximum cal a CookingRecipe can have. */
	int maxCal = 1000;

	/** The maximum worth a CookingRecipe can have. */
	int maxWorth = 101;

	/** The vector of CookingRecipe names. */
	std::vector<std::string> CookingRecipeNames;

	/** The vector of rating names. */
	std::vector<std::string> ratingNames;
public:
	/**
	 * @brief Default constructor for the Generator class.
	 *
	 * Initializes the random seed for generating random CookingRecipe.
	 */
	Generator();

	/**
	 * @brief Reads data from files.
	 * @param restFile The file containing the CookingRecipe names.
	 * @param ratingFile The file containing the names of ingredient.
	 */
	void readFiles(std::string, std::string);

	/**
	 * @brief Generates random CookingRecipe
	 * @param filename The file to write the generated CookingRecipe to.
	 * @param number The number of CookingRecipe to generate.
	 */
	void generate(std::string, int);

	/**
	 * @brief Prints the CookingRecipe in the vector.
	 */
	void print();

	/**
	 * @brief Generates a random CookingRecipe
	 * @return A randomly generated CookingRecipe
	 */
    CookingRecipe genCookingRecipe();
};

#endif // GENERATOR_H