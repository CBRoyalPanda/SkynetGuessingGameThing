//A target
//A grid sized 1 - 64
//A drone hunter
//Software which is using a binary search algorithm

#include <iostream>
#include <ctime>
#include <random>

using namespace std;



int main()
{
	//Variables
	int target;
	int searchGridHighNumber = 64;
	int searchGridLowNumber = 1;

	int HumanLocationPrediction = 0;
	int linearLocationPrediction = 0;
	int RandomLocationPrediction = 0;
	int targetLocationPrediction = 0;

	int HumanGuessAmount = 0;
	int LinearGuessAmount = 0;
	int RandomGuessAmount = 0;
	int BinaryGuessAmount = 0;

	//Generating a random number
	cout << "Placing a target within one of 64 sectors" << endl;
	srand(time(0));
	target = rand() % 64 + 1;

	//I'm simply keeping this line here so I don't have to accurately guess the number every time I test the code
	cout << "The target is located at sector " << target << "." << endl;
	
	cout << "Skynet HK Aerial Initilizing software..." << endl;

	//Human Input
	while (HumanLocationPrediction != target)
	{
		cout << "Where do you think the target is located? (1-64)" << endl;
		cin >> HumanLocationPrediction;

		//Counts how many guesses it takes to find the target
		HumanGuessAmount++;

		if (HumanLocationPrediction != target)
		{
			cout << "You are incorrect, please try again" << endl;
		}
		else
		{
			cout << "You are correct" << endl;
		}
	}
	
	//Linear Search
	//Adds by 1 to find target

	cout << "Running Linear Search..." << endl;
	while (linearLocationPrediction != target)
	{
		LinearGuessAmount++;
		linearLocationPrediction = linearLocationPrediction + 1;
	}
	cout << "Linear Search Completed" << endl;

	//Random Search
	//Generates Random numbers until the target is found

	cout << "Running Random Search..." << endl;
	while (RandomLocationPrediction != target)
	{
		RandomLocationPrediction = rand() % 64 + 1;

		RandomGuessAmount++;
	}
	cout << "Random search completed" << endl;


	cout << "Running Binary Search..." << endl;
	// Binary Search
	// While the guess is not equal to the targets location, this will continue to run
	while (targetLocationPrediction != target)
	{
		cout << "Scanning Area..." << endl;

		//Sets the guess as the value in the middle of the min and the max
		targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

		//Keeps Track of the amount of guesses the Binary Search makes
		BinaryGuessAmount++;
		
		//If the guess is lower than the target
		//The minimum is set to the same value as the guess
		//Bassically ignoring the bottom half of the area
		if (targetLocationPrediction < target)
		{
			cout << "The targets location was higher than the prediction" << endl;
			searchGridLowNumber = targetLocationPrediction + 1;

			cout << "Minimum value changed to " << searchGridLowNumber << "." << endl;
		}

		//If the target is lower than the guess
		//Set the maximum to be the same value as the guess
		//Basically ignoring the top half of the area
		if (targetLocationPrediction > target)
		{
			cout << "The targets location was lower than the prediction" << endl;
			searchGridHighNumber = targetLocationPrediction - 1;

			cout << "Maximum value changed to " << searchGridHighNumber << "." << endl;
		}

		//If the guess is equal to the target's location then gg
		if (targetLocationPrediction == target)
		{
			cout << "The target has been found in sector " << targetLocationPrediction << "." << endl;
		}
	}
	cout << "Binary Search Completed" << endl;

	//Display the Results
	cout << " " << endl;
	cout << "The Human found the target in " << HumanGuessAmount << " guesses." << endl;
	cout << "The Linear search found the target in " << LinearGuessAmount << " guesses." << endl;
	cout << "The Random search found the target in " << RandomGuessAmount << " guesses." << endl;
	cout << "The Binary search found the target in " << BinaryGuessAmount << " guesses." << endl;

	return 0;
}